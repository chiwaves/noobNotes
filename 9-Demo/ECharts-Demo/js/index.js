(function () {
  let rem = function () {
    let width = window.innerWidth
    if (width < 1024) {
      width = 1024
    } else if (width > 1920) {
      width = 1920
    }
    document.documentElement.style.fontSize = width * (24 / 1920) + 'px'
  }
  rem()
  window.onresize = rem

  $('.tabs>a').click(function () {
    $(this).addClass('active').siblings().removeClass('active')
    $('.content').eq($(this).index()).css('display', 'block').siblings('.content').css('display', 'none')
  })

  $('.marquee').each(function (idx, ele) {
    $(ele).children().clone().appendTo($(this))
  })
})();

// 实现点位-饼状图
(function () {
  let myChart = echarts.init(document.querySelector('.pie'))
  let option = {
    // 控制提示
    tooltip: {
      // 非轴图形，使用item的意思是放到数据对应图形上触发提示
      trigger: 'item',
      // 格式化提示内容：
      // a 代表图表名称 b 代表数据名称 c 代表数据  d代表  当前数据/总数据的比例
      formatter: "{a} <br/>{b} : {c} ({d}%)"
    },
    // 控制图表
    series: [
      {
        // 图表名称
        name: '点位统计',
        // 图表类型
        type: 'pie',
        // 南丁格尔玫瑰图 有两个圆  内圆半径10%  外圆半径70%
        // 百分比基于  图表DOM容器的半径
        radius: ['10%', '70%'],
        // 图表中心位置 left 50%  top 50% 距离图表DOM容器
        center: ['50%', '50%'],
        // 半径模式，另外一种是 area 面积模式
        roseType: 'radius',
        // 数据集 value 数据的值 name 数据的名称
        data: [
          { value: 20, name: '云南' },
          { value: 26, name: '北京' },
          { value: 24, name: '山东' },
          { value: 25, name: '河北' },
          { value: 20, name: '江苏' },
          { value: 25, name: '浙江' },
          { value: 30, name: '四川' },
          { value: 42, name: '湖北' }
        ],
        color: ['#006cff', '#60cda0', '#ed8884', '#ff9f7f', '#0096ff', '#9fe6b8', '#32c5e9', '#1d9dff'],
        label: {
          fontSize: 10
        },
        labelLine: {
          length: 8,
          length2: 10
        }
      }
    ]
  }
  myChart.setOption(option)
})();

// 实现用户-柱状图
(function () {
  let myChart = echarts.init(document.querySelector('.bar'))
  let itemStyle = {
    // 数值
    value: 1200,
    // 柱子颜色
    itemStyle: {
      color: '#254065'
    },
    // 鼠标经过柱子颜色
    emphasis: {
      itemStyle: {
        color: '#254065'
      }
    },
    // 工具提示隐藏
    tooltip: {
      show: false,
      // extraCssText: 'opacity:0'
      // 注意： 'display:none' 无法隐藏工具提示
    }
  }
  let option = {
    tooltip: {
      // 触发类型  经过轴触发axis  经过图形触发item
      trigger: 'item',
      // 轴触发提示才有效
      axisPointer: {
        // 默认为直线，可选为：'line' 线效果 | 'shadow' 阴影效果
        type: 'shadow'
      }
    },
    // 图表边界控制
    grid: {
      // 距离 上右下左 的距离
      show: true,
      top: '3%',
      right: '4%',
      bottom: '3%',
      left: 0,
      // 是否包含文本
      containLabel: true,
      borderColor: 'rgba(0, 240, 255, 0.3)',
    },
    // 控制x轴
    xAxis: [
      {
        // 使用类目，必须有data属性
        type: 'category',
        // 使用 data 中的数据设为刻度文字
        data: ['上海', '广州', '北京', '深圳', '合肥', '', '......', '', '杭州', '厦门', '济南', '成都', '重庆'],
        // 刻度设置
        axisTick: {
          // 标签与刻度对齐
          show: false,
        },
        axisLabel: {
          color: "#4c9bfd"
        }
      }
    ],
    // 控制y轴
    yAxis: [
      {
        // 使用数据的值设为刻度文字
        type: 'value',
        axisTick: {
          show: false,
        },
        axisLabel: {
          color: "#4c9bfd"
        },
        splitLine: {
          show: true,
          lineStyle: {
            color: ['rgba(0, 240, 255, 0.3)']
          }
        }
      },
    ],
    // 控制x轴
    series: [
      {
        // 图表数据名称
        name: '用户统计',
        // 图表类型
        type: 'bar',
        // 柱子宽度
        barWidth: '60%',
        color: {
          type: 'linear',
          // 0, 0, 0, 1 意思是颜色从上到下渲染
          // 0，1，0，0 从下到上渲染
          // 0，0，1，0 颜色横向从左到右渲染
          // 1，0，0，0 颜色横向横向从右到左渲染
          x: 0,
          y: 0,
          x2: 0,
          y2: 1,
          colorStops: [{
            offset: 0, color: '#00fffb' // 0% 处的颜色
          }, {
            offset: 1, color: '#0061ce' // 100% 处的颜色
          }],
          global: false // 缺省为 false
        },
        // 数据
        data: [2100, 1900, 1700, 1560, 1400, itemStyle, itemStyle, itemStyle, 900, 750, 600, 480, 240],
      }
    ]
  }
  myChart.setOption(option)
})();

(function () {
  let data = {
    year: [
      [24, 40, 101, 134, 90, 230, 210, 230, 120, 230, 210, 120],
      [40, 64, 191, 324, 290, 330, 310, 213, 180, 200, 180, 79]
    ],
    quarter: [
      [23, 75, 12, 97, 21, 67, 98, 21, 43, 64, 76, 38],
      [43, 31, 65, 23, 78, 21, 82, 64, 43, 60, 19, 34]
    ],
    month: [
      [34, 87, 32, 76, 98, 12, 32, 87, 39, 36, 29, 36],
      [56, 43, 98, 21, 56, 87, 43, 12, 43, 54, 12, 98]
    ],
    week: [
      [43, 73, 62, 54, 91, 54, 84, 43, 86, 43, 54, 53],
      [32, 54, 34, 87, 32, 45, 62, 68, 93, 54, 54, 24]
    ]
  }
  let myChart = echarts.init(document.querySelector('.line'))
  let option = {
    grid: {
      show: true,// 显示边框
      top: '20%',
      left: '3%',
      right: '4%',
      bottom: '3%',
      borderColor: '#012f4a',// 边框颜色
      containLabel: true // 包含刻度文字在内
    },
    legend: {
      textStyle: {
        color: '#4c9bfd' // 图例文字颜色
      },
      right: '10%' // 距离右边10%
    },
    tooltip: {
      trigger: 'axis'
    },
    xAxis: {
      type: 'category',
      data: ['1月', '2月', '3月', '4月', '5月', '6月', '7月', '8月', '9月', '10月', '11月', '12月'],
      axisTick: {
        show: false // 去除刻度线
      },
      axisLabel: {
        color: '#4c9bfd' // 文本颜色
      },
      axisLine: {
        show: false // 隐藏坐标轴轴线
      },
      boundaryGap: false  // 去除轴内间距
    },
    yAxis: {
      type: 'value',
      axisTick: {
        show: false  // 去除刻度
      },
      axisLabel: {
        color: '#4c9bfd' // 文字颜色
      },
      splitLine: {
        lineStyle: {
          color: '#012f4a' // 分割线颜色
        }
      }
    },
    series: [{
      name: '预计销售额',
      data: [24, 40, 101, 134, 90, 230, 210, 230, 120, 230, 210, 120],
      type: 'line',
      smooth: true,
      itemStyle: {
        color: "#00f2f1"
      }
    }, {
      name: '实际销售额',
      data: [40, 64, 191, 324, 290, 330, 310, 213, 180, 200, 180, 79],
      type: 'line',
      smooth: true,
      itemStyle: {
        color: "#ed3f35", // 线颜色
      }
    }]
  }
  myChart.setOption(option)

  let count = 0
  $('.caption a').click(function () {
    $(this).addClass('active').siblings().removeClass('active')
    let i = $(this).attr('data-type')
    option.series[0].data = data[i][0]
    option.series[1].data = data[i][1]
    count = $(this).index() - 1
    myChart.setOption(option)
  })

  let foo = () => {
    count = ++count % $('.caption a').length
    $('.caption a').eq(count).click()
  }
  let inter = setInterval(foo, 1000)
  $('.sales').hover(() => {
    clearInterval(inter)
  }, () => {
    inter = setInterval(foo, 1000)
  })
})()