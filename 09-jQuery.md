# jQuery



## 概述

### 入口函数

等DOM结构渲染完毕即可执行js代码，不必等待外部资源加载完毕，比`window.onload()`快

```javascript
$(function () {
	... // js代码
});
```

```javascript
$(document).ready.(function () {
	... // js代码
});
```

$ 是jQuery的别称，简便写法，是jQuery的顶级对象。$ 或 jQuery 之于 jquery 库，相当于 document 之于 DOM。加载 jQuery 文件后，`console.dir(window)`可以看到 window 上挂载了 $ 对象，jquery 的对象和方法都在其中。



### jQuery 对象

利用 $ 对 DOM 对象包装后产生的对象，伪数组形式。注意避免混淆。

```js
$("div").style.display = 'none' // 混淆了DOM对象和jquery对象的方法
```

```js
// 方法混淆
$('button').click(function () {
    this.innerHTML = '同化完成'
})
```

```js
// 正确示范
$('button').click(function () {
	$(this)[0].innerHTML = '同化完成'
})
```



DOM对象可以转换为jQuery对象

```js
var myvideo = document.querySelector("video");
// 已经使用原生js获取了myvideo这个DOM对象
$(myvideo); // 转为jQuery对象
```

jQuery对象可以转换为DOM对象，再使用DOM对象的方法

```js
$("div")[index] // index是索引号
```

```js
$("div")[0].style.background = 'red' // 转为DOM对象，DOM的方法修改css样式
```



## 选择器

原生js获取元素方法多，getElementById()、querySelector()，曾经各浏览器兼容性不一致。jquery做了封装，统一了标准。

用法：`$("选择器")`

```js
$("ul>li") // 子代选择器，只获取ul亲儿子li元素，不会获取孙子层级的li
$("ul li") // 后代选择器，获取ul下所有的li元素，包括孙子层级
```



### 隐式迭代

匹配的所有元素内部进行遍历循环，给每个元素添加css

```js
$("li").css("background", "pink");  // 每个div标签的背景色都设置为粉色
```



### 筛选选择器

```js
$("li:first") // 选择第一个li
$("li:last") // 选择最后一个li
$("li:eq(2)") // 选择索引号为2即第3个li
$("li:odd") // 选择索引号为奇数的li
$("li:even") // 选择索引号为偶数的li
```



### 筛选方法

查前代

```js
$("li").parent(); // 查找父级
$(".item").parents(".grandpa"); // 选中.item所有祖先元素中的.grandpa
```

查后代

```js
$("ul").children("li") // 相当于子代选择器$("ul>li")
$("ul").find("li") // 相当于后代选择器$("ul li")
$("ul").find() // 选择ul的全部后代
```

查同辈

```js
$(".theLi").siblings("li") // 兄弟节点的所有li，不包括自己
$(".first").next() // 该结点后一个同辈元素
$(".first").nextAll() // 该结点之后所有的同辈元素
$(".last").prev() // 该结点前一个同辈元素
$(".last").prevAll() // 该结点之前所有的同辈元素
```

```js
$("li").eq(2) // 相当于$("li:eq(2)")

$(this).index() // 获取该结点的索引号
$("#content div").eq(index).show()
$("#content div").eq(index).siblings().hide()
```

排他思想

```js
// 被选中的btn变成粉色，其余不变色
$("button").click(function () {
    $(this).css("background", "pink");
    $(this).siblings("button").css("background", "");
})
```

排他思想的链式写法

```js
$("button").click(function () {
    $(this).css("background", "pink").siblings("button").css("background", "")
})
```



## 样式操作

参数只写属性名，则返回属性值

```js
$(this).css("color"); // 返回当前元素的样式的color
```

```js
$(this).css("width", "300px");
$(this).css("width", 300);
```



对象形式的参数设置多组样式，属性名可以不加引号

```js
$(this).css({
    width: 400,
	color: "white",
    backgroundColor: "pink" // 属性名中短杠改为驼峰写法
});
```



样式操作较多时可以用设置类的方法

```js
// 添加类，原生js中className操作会覆盖掉原先的类名
$("li").click(function () {
    $(this).addClass("current");
})
// 移除类
$("li").click(function () {
    $(this).removeClass("current");
})
// 切换类
$("li").click(function () {
    $(this).toggleClass("current");
})
```



链式操作

```js
$(".tab-list li").click(function () {
    // 当前的li添加current类，其余兄弟移除current类
    $(this).addClass("current").sublings().removeClass("current");
    // 点击的同时，得到当前li的索引号
    var index = $(this).index();
    // 让下半部里面相应索引号的item显示，其余的item隐藏
    $(".tab-con .item").eq(index).show().siblings().hide();
});
```



## 效果

鼠标悬停下拉菜单

```js
$(".nav>li").hover(function () {
    $(this).children("ul").slideToggle();
})
```

```js
// stop()停止上一次动画，必须写在动画前面
$(".nav>li").hover(function () {
    $(this).children("ul").stop().slideToggle();
})
```

自定义动画

```js
$(".btn").click(function () {
    $(".tango").animate({
        width: "30px"
        height: 30,
        fontSize: "30px",
    }, 1000, function () {
        alert("动画执行完毕")
    })
})
```

`animate()`中要更改的属性用对象的形式写入，作为第一个参数。第二个参数是动画持续时间。第三个参数可选，是动画执行完毕后执行的回调函数。不止是`animate()`，`fadeIn()`、`fadeOut()`等等也可以加回调函数。但是并不是所有的属性都可以更改，比如颜色属性就不可更改。



## 属性

固有属性

```js
console.log($("a").prop("href"));
$("img").prop("title", "这是图片");
```

```js
$("input").change(function () {
    console.log($(this).prop("checked"));
})
```



自定义属性

```js
$("div").attr("index"); // 类似原生getAttribute()
$("div").attr("index", 3); // 类似原生setAttribute()
console.log($("div").attr("data-index")); // HTML5新增的自定义属性data-xxx
```



固有属性用`attr`亦可以获取和修改。但是仍然推荐用 `prop`方法来获取和修改。`prop`可以选中标签的隐藏属性，`attr`却不可以。比如 `<input type="checkbox">`的`checked`属性。当一开始时，checkbox 的 checked 属性默认为 false，而且不显示在标签上，`attr`无法选中该属性。

```js
$('.j-checkbox').click(function () {
    var i = $(this).parents('.cart-item').index()
    data[i].checked = $(this).prop('checked')
    if ($(this).prop('checked')) {
        $(this).parents('.cart-item').addClass('check-cart-item')
    } else {
        $(this).parents('.cart-item').removeClass('check-cart-item')
    }
    renewFooter()
})
```



元素的缓存

```js
$("span").data("username", "andy"); // 存入缓存中，在DOM中不会显示
console.log($("span").data("username"));
```

```js
// 相比attr()，获取H5属性data-index不用加data- ，而且返回数字型
console.log($("div").data("index")); 
```



## 内容文本值

```js
$("div").html("<span>233</span>"); // 相当于innerHTML
$("div").text("233"); // 相当于innerText
$("input").val("name");  // 相当于value
```



## 添加删除

遍历元素

```js
// 回调函数的第一个参数是索引号，第二个参数是DOM元素对象
$(".good-item").each(function (index, domEle) {
    $(domEle).css("font-size", 16);
})
```

```js
var obj = {
    name: "andy",
    age: "18",
    sex: "male"
}
$.each(obj, function (i, ele) {
    console.log(i); // 第一个参数表示对象的属性名或数组的索引号
    console.log(ele); // 第二个参数表示对象的属性值或数组的元素
}) // 类似for...in
```



内部添加

```js
var nw = $("<li>我是后来创建的li标签</li>");
$("ul").append(nw); // 内部添加并且放到最后
$("ul").prepend(nw); //  内部添加并且放到最前
```



外部添加

```js
var nw = $("<p>我是后妈生的</p>");
$(".tango").after(nw);
$(".tango").before(nw);
```



删除

```js
$("ul").remove(); // 删除匹配的元素，自杀
$("ul").empty(); // 清空匹配的元素里面的子节点
$("ul").html(""); // 清除子元素，常用于对一个元素的内部结构清除或重写
```



## 事件

单个事件注册

```js
$("div").click(function () {
    $(this).css("background", "purple");
});
```



事件处理，可以在一个元素上一次绑定多个事件

on()代替了原先的bind()，live()，delegate()等方法

```js
$("div").on({
    mouseenter: function () {
        $(this).css("background", "purple");
    },
    click: function () {
        $(this).css("background", "skyblue");
    },
    mouseleave: function () {
        $(this).css("background", "pink");
    }
});
```

```js
$("div").on("mouseenter mouseleave", function () {
    $(this).toggleClass("active");
})
```



### 事件委派

```js
// click绑定在ul上，但是触发的对象是ul里面的li
$("ul").on("click", "li", function () {
    alert("attention!");
})
```

on()绑定动态创建的元素

**经常用：如果需要后期动态生成DOM元素，那么动态生成的元素身上绑定事件必须要通过对其父元素进行事件委派**

```js
$(".pro-list").on("click", "li", function () {
    alert("attention!");
});
var li = $("<li>我是后来创建的元素</li>");
$(".pro-list").append(li);
```



off()解除事件绑定

```js
$("P").off() // 解绑p元素所有事件处理程序
$("p").off("click") //解绑p元素上面的点击事件 
$("p").off("click", "li") // 解绑事件委托
$("p").one("click", function () {
    alert("hello"); // 只触发事件一次
})
```



## Ajax

### 示例用法

```js
let data
$.ajax({
    url: '',
    type: 'get',
    data: {
        keyword: 'heroid',
        other: 2
    },
    dataType: 'json',
    success(res) {
        data = res.data
        console.log(data)
        // ... 后续对返回结果res的操作
    }
})
```

url 是作为传输目标的后端接口。type 是请求类型，get、post、put、delete 等等。dataType 写为 json 表示对传回来的数据进行一次 `JSON.parse()`操作。一般后台传来的是 json 格式，所以经常使用。success 写的是请求成功后的回调函数。



### FormData

HTML中提供了`<form>`表单元素，通过表单元素可以让浏览器自动收集用户输入的数据，然后发送给服务器。

```html
<form action="/handling-page" method="POST" enctype="application/x-www-form-urlencoded">
  <div>
    <label for="name">用户名：</label>
    <input type="text" id="name" name="user_name" />
  </div>
  <div>
    <label for="passwd">密码：</label>
    <input type="password" id="passwd" name="user_passwd" />
  </div>
  <div>
    <input type="submit" id="submit" name="submit_button" value="提交" />
  </div>
</form>
```

不过这种发送信息的方式非常不安全。早就被废弃，不必多花时间研究。现在仍可能用到`<form>`标签的场景，是将`<from>`标签与 FormData 对象一起使用。如果上传的数据有图像或文件，那么必须使用 FormData 对象上传，Json 无法替代。现在，仅仅使用FormData对象，阻止浏览器的自动发送行为，而使用 js 脚本发送 ajax 请求。

更具体的案例参考就业班 Ajax 第 5 天 的 heroManager 中的 edit.html，其中部分相关的代码如下。以及大事件 BigEvent 项目第 3 天的更换头像、第 5 天的发表文章部分。

```html
<div class="panel-body">
    <form action="#" method="" class="form-horizontal" id="form">
    <!-- 隐藏input ： 用户看不见，但是formdata可以获取到 -->
        <input type="hidden" id="heroId" name="id" />
        <div class="form-group">
              <label for="heroName" class="col-sm-2 control-label">姓名</label>
              <div class="col-sm-10">
                    <input required type="text" class="form-control" id="heroName" name="name" placeholder="请输入姓名"
                  value="盖伦" />
              </div>
        </div>
        <div class="form-group">
            <label for="heroIcon" class="col-sm-2 control-label">头像</label>
            <div class="col-sm-10">
                <input required type="file" class="file-input" id="heroIcon" name="icon" />
                <!-- 预览的标签 -->
                <img src="" class="preview" alt="" style="height: 100px;" />
            </div>
        </div>
        <div class="form-group">
            <div class="col-sm-offset-2 col-sm-10">
                <button type="submit" class="btn btn-primary btn-save">保存</button>
                <button type="submit" class="btn btn-cancel">取消</button>
            </div>
        </div>
    </form>
</div>
```

```HTML
<script>
    $("#form").on("submit", e => {
        // 禁用表单默认提交事件
        e.preventDefault()
        // 创建FormData对象: FormData()构造函数的形参必须是DOM对象，不可以是jQuery对象
        let fd = new FormData($("#form")[0])
        $.ajax({
            url: "http://127.0.0.1:4399/hero/update",
            type: "post",
            dataType: "json",
            data: fd,
            contentType: false,
            processData: false,
            success (res) {
                if (res.code == 202) {
                    alert("修改成功")
                    window.location.href = "./index.html"
                }
            },
        })
    })
</script>
```

将目标表单作为形参传入，创建完 FormData 对象后。表单中的用户输入的数据会自动添加进 FormData 对象。如果此时还有参数遗漏，比如隐藏的不需要用户输入，但是接口又要求的参数，可以使用`FormData.set()`或`FormData.append()`手动加入。

```js
// 使用 set() 方法添加
fd.set("content", htmlStr)
// 使用 append() 方法添加
canvas.toBlob(blobObj => {
    fd.append("cover_img", blobObj)
})
```

如果指定的键不存在，则 `set()` 和 `append()`都会在 `FormData `对象中添加该键并赋上指定的值。但如果指定的键存在，则`set()` 方法会对 `FormData` 对象里的某个 key 设置一个新的值，覆盖原先的旧值。`append()` 方法会找到 `FormData` 对象内的该键，然后在该键的值最后位置加上新的值。



## 模板语法

1. 从 art-template 官网上下载`template-web.js`文件，导入模板引擎文件

   `<script src="./libs/template-web.js"></script>`

2. 然后在 body 中写 HTML 模板

3. 最后在另一个 script 标签中调用模板

   ```html
   <body>
       <script type="text/html" id="hero">
     	{{ each skins }}	<!-- 遍历 res.data.skins 数组 -->
     	{{if $value.iconImg}}	<!-- $value 表示 skins 数组中的每一个元素 -->
     	<li idx="{{ $index }}">	<!-- $index 表示 skins 数组中元素的下标 -->
       	<a href="javascript:;">
         		<img src="{{ $value.iconImg }}" alt="icon">
       	</a>
     	</li>
     	{{ /if }}
     	{{ /each }}
   	</script>
       
       <script>
         	$.ajax({
           	url: 'https://autumnfish.cn/api/lol/info',
           	type: 'get',
           	data: {id: 1},
           	dataType: 'json',
           	success(res) {
                   // template() 中的第一个参数是所用的模板id，第二个参数是需要动态修改的数据，一般是个对象
             		$(".list").html(template("hero", res.data))
           	}
         	})
       </script>
   </body>
   ```

