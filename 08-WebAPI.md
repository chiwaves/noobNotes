# DOM

- `querySelector('css选择器')` 

  `querySelector('li:nth-child(3)');` 

  `querySelectorAll()` 获得的是NodeList伪数组

- DOM对象和HTML元素关系：Attribute方法



- 事件冒泡和组织事件冒泡

- 清除定时器或延时器的方法

  ```js
  // 变量timeId必须在函数作用域外声明
  var timeId;
  // 装炸弹
  btn1.onclick = function () {
    timeId = setInterval(function () {
       console.log( 'boom!' );
    }, 1000);
  }
  
  // 拆炸弹
  btn2.onclick = function () {
  	clearInterval(timeId);
  }
  ```

  

