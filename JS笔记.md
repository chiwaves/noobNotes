# JS笔记

- 相等运算符有两种：
第一种==比较，它会自动转换数据类型再比较，很多时候，会得到非常诡异的结果
第二种===比较，它不会自动转换数据类型，如果数据类型不一致，返回false，如果一致再比较
由于这个设计缺陷，不要使用==比较，始终坚持使用===比较。

- 字符串是不可变的，如果对字符串的某个索引赋值，不会有任何错误，但是，也没有任何效果
  var s = 'Test';
  s[0] = 'X';
  alert(s); // s仍然为'Test'

- JavaScript访问数组不会越界，而且可以直接改变数组长度。
  但在编写代码时，不建议直接修改Array的大小，访问索引时要确保索引不会越界。

- 字符串用substring(X, Y)截取索引号第X到第Y-1

- substr(X, len) 截取从索引号第X开始的len个字符，参数len省略则截取到最后

- 数组用slice(X, Y)截取，返回一个新的数组。slice()方法的参数中有一个负数，则用数组长度加上该数来确定相应的位置。在一个包含 5 项的数组上调用 slice(-2, -1)与调用 slice(3, 4)得到的结果相同。

- splice()方法可以用于删除，插入，替换
  splice(2, 1, "red", "green")会删除当前数组位置 2 的项，然后再从位置 2 开始插入字符串"red"和"green"。

- 循环：for...in/for...of，forEach，map
  高阶方法：filter，every

- 闭包指的是有权访问父作用域的函数，即使在父函数关闭之后。

  ```js
  var add = (function () {
      var counter = 0;
      return function () {return counter += 1;}
  })();
  add();
  add();
  add();
  // 计数器目前是 3
  ```

  变量 add 的赋值是自调用函数的返回值。
  这个自调用函数只运行一次。它设置计数器为零（0），并返回函数表达式。
  这样 add 成为了函数。最“精彩的”部分是它能够访问父作用域中的计数器。
  这被称为 JavaScript 闭包。它使函数拥有“私有”变量成为可能。
  计数器被这个匿名函数的作用域保护，并且只能使用 add 函数来修改。

- 函数是对象？还是对象方法？
  通过函数构造器来调用函数
  如果函数调用的前面是 new 关键字，那么这是一个构造函数调用。
  它看起来像你创建一个新的函数，但由于 JavaScript 函数是对象，你实际上创建一个新对象：

  ```js
  // 这是函数构造器：
  function myFunction(arg1, arg2) {
      this.firstName = arg1;
      this.lastName  = arg2;
  }
  // 创建了一个新对象：
  var x = new myFunction("Bill", "Gates");
  x.firstName;	// 会返回 "Bill"
  ```

​       构造函数始终都应该以一个

​       大写字母开头，而非构造函数则应该以一个小写字母开头



# 待办



## 移动端改写

1. js 代替媒体查询，获取浏览器窗口实时宽度来实现rem布局
2. swiper 代替 overflow: auto 完成轮播图效果
3. js 实现列表框根据内部列表项数量宽度自适应
4. iscroll 代替 overflow: auto 完成横向滑动的列表效果



## Web API

- 放大镜造轮子
- swiper 造轮子
- iscroll 造轮子：touch事件
- **拖拽登录框案例实现 (document.onmousemove)**
- 2048 改写移动版后 ontouch 事件
- .box * {}



## jQuery

- `$(.checkbox:checked)` 花式CSS选择器

- document 是DOM顶级对象，无法调用animate方法

- `window.innerHTML` 写死

- css 子绝父相，子元素同时写 left 和 right 或者同时写 top 和 bottom 把元素拉伸开

- index() eq(),不是在同类而是在全部的子元素中的排名

- `form` 表单中的按钮默认跳转事件 `action`属性默认行为，和a标签一样使用 javascript:; 或 e.preventDefault

- 事件委托 --> 事件冒泡-->e.target

- ajax原理

- 节流防抖，万能防抖函数的闭包实现

- `<button onclick="location.href='./edit.html?id=' + $(this).parents('tr').attr('data-id')"

  ​     class="btn btn-primary btn-edit">编辑</button>`
  



## 大事件

- 短路，debugger，input选择器
- null == ''
- 退出登录的confirm
- window.parent
- 表单 oninput 内容改变； onchange 内容改变并且失去焦点
- startsWith
- dataset 快速获取标签自定义属性
- jq   ajax > serialize()
- canvas，blob对象，toBlob 也是异步的
- 9.10 map部分
- 函数式编程
- 函数柯里化
- cropper预习文档
- typeof 可以判断是否是函数



## Node


- 再次需要认证时，浏览器自动发送cookie，是否是浏览器中所有的有效cookie，没有一点限制吗
- res.send() 直接发送script，浏览器直接执行，为什么





- [x] main2048.js  第41行

  ```js
  $("#grid-container").append('<div class="number-cell" id="number-cell-'+i+'-'+j+'"></div>');
  /* 若结尾是空格，比如 id="number-cell '+i+'-'+j+'" 就不行 */
  ```

- [x] event.keyCode

- [x] JS DOM vs JQuery

- [x] document.querySelector(' ')

- [x] 箭头函数

- [x] 过滤器 splice slice

- [ ] 计算属性

- [ ] ajax promise

- [ ] jsonp

- [ ] Vue组件加载

- [ ] 哈希路由 	/#/order/alipay

- [x] 接口错误拦截  axios.interceptors.response.use()

- [x] testground 简易的组件跨域实现

- [x] 动态加载对象 用[ ]

- [x] 对象的继承 JSON.parse(JSON.stringify(item))可行，es6扩展运算符...可行，Object.create(item)不可行

- [x] html form 标签 表单 submit

- [x] NavHeader用户名下拉列表bug

- [ ] 订单筛选的完美实现

- [x] 《闭包，看这一篇就够了——带你看透闭包的本质，百发百中》闭包例子10中的onclick事件

- [x] 异步函数到底是啥，闭包是怎么解决异步的问题的

- [x] 廖雪峰 箭头函数 this 词法作用域

- [x] eval()到底有啥用？有和没有有区别？

- [ ] 正则 两处

- [ ] 访问器属性 使用场景

- [ ] 寄生组合式怎么高效了？

- [x] 下拉菜单宽度还原

- [ ] element-ui 气泡确认框点击确认触发事件的async写法
  this.$confirm().then ( async() => {} )
  
- [ ] CSS3动画Vue动画 @keyframe，子元素选中父元素 bootstrap .row


