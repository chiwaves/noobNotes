# JavaScript 基础

## 基础

### JS 变量命名规范

1. 由英文字母、数字、下划线 _ 、美元符 $ 组成
2. 严格区分大小写
3. 不能以数字开头
4. 不能是关键字、保留字 (var, while, for ... )



### 数字前面加0表示八进制



### 字符串引号嵌套

外双内单，外单内双

```js
// main2048.js 第41行
$("#grid-container").append('<div class="number-cell" id="number-cell-' + i + '-' + j + '"></div>');
// 第一组：'<div class="number-cell" id="number-cell-'
// 第二组：'-'
// 第三组：'"></div>'
```



### typeof 操作符

用来检验数据类型

```js
var tmp = null;
console.log(typeof tmp); // object
```

```js
//   + - * / % > === && , = typeof var 等等都是操作符
```

```js
var str = 'abc';
console.log(typeof str++);
/* typeof 操作的对象是整体str++表达式的返回值。对字符串进行自增自减时，会先对字符串用Number()方法进行转换，得到NaN，转换的结果即为str++表达式的返回值。对返回值进行typeof操作得到number类型，最后str = str + 1，即str = NaN + 1, str = NaN */
```

```js
var i = 3;
i = i++;
console.log(i);
/* i++是一个表达式，整个表达式返回的结果是3，然后将i++表达式的返回值赋值给i，i再变为3。所以最后打印3。最后i增加为4 */
```



### instanceof 操作符

用来检测对象的类型

```js
var num = 10
var obj = {name: 'ppp'}
var arr = [1, 2, 3]
var foo = num => console.log(num)
console.log(num instanceof Object) // false
console.log(obj instanceof Array) // false
console.log(arr instanceof Array) // true
console.log(foo instanceof Function) //true
console.log(arr instanceof Object) // true
console.log(foo instanceof Object) // true
```



### 数据类型转换

```js
var num = 18;
console.log(num.toString());
console.log(String(num));
console.log(num + '');
```

```js
console.log(parseInt(3.98)); // 3
console.log(parseFloat(3.98)); // 3.98
console.log(parseInt('15.3元一条2斤的鱼')); // 15 
console.log(parseFloat('15.3元一条2.5斤的鱼')); // 15.3
console.log(parseFloat('大明$15一条3斤的鱼')); // NaN
console.log(Number(3.14)); // 3.14
console.log(3.14 * 1); //3.14
```

通过prompt输入的数据都是字符串型的，需要转换为数字型

```js
var sum = 0;
var num = 7;
for (var i = 1; i <= num; i++) {
    var score = prompt('请输入第' + i + '个学生的成绩');
    sum += parseFloat(score);
}
console.log(sum);
```



### 运算符优先级

小括号 -> 一元 ( ++、--、! ) -> 算术 -> 关系 ( >、>=、<、<= ) -> 相等 ( === 、!==) -> 逻辑 ( **先 && 后 ||** ) -> 赋值 -> 逗号



### == 和 ===

用 == 进行判断会转型

用 === 要求全等，值和数据类型全都一致

```js
var a = 2, b = '2';
a == b; // true
a === b; // false
```

用 != 进行判断，如果转型后还不一致才返回 true

用 !== 进行判断，如果值或数据类型有一项不一致，就返回 true

```js
var a = 2, b = '2';
a != b; // false
a !== b; // true
```



短路运算(逻辑中断) ？？？



switch 里的匹配的时候必须是全等，值和数据类型都一致

```js
var num = '343';
switch (num) {
    case 141:
        console.log('found');
        break;
    case 343:
        console.log('found, too');
        break;
    default:
        console.log('404 not found');
}
// 404 not found
```



switch例题：将分数转换为等级，应试教育转素质教育

```js
let score = [87, 65, 81, 73, 100, 42, 93, 77];
let res = []
score.forEach((el) => {
    switch(parseInt(el / 10)) {
        case 10:
            res.push('A');
            break;
        case 9:
            res.push('A');
            break;
        case 8:
            res.push('B');
            break;
        case 7:
            res.push('C');
            break;
        case 6:
            res.push('D');
            break;
        default:
            res.push('E');
            break;
    }
})
console.log(res);
```



### 立即执行函数表达式(IIFE)

三种写法

```js
(function () {
    console.log(1)
})();
```

```js
(function () {
    console.log(2)
}());
```

```js
!function () {
    console.log(3)
}();
```

注意，浏览器可能会断句错误无法读取。IIFE的前后最好都有分号隔开上下文



## 预解析

JavaScript 是客户端脚本语言。也是一种解释型语言。解释器是在运行时进行及时解释并立即执行。JS 引擎解释一句代码，计算机执行一句代码。相比于编译型语言，编译器先将全部代码转换为中间文件，最后再去执行。



不声明不赋值，直接使用，ReferenceError

不声明，直接赋值，然后使用，可行，全局变量



js 引擎运行 js 代码分为两步

1. 预解析： js 引擎会把代码里所有的 var 和 function 提升到当前作用域的最前面

2. 代码执行：按照代码书写的顺序从上往下执行




预解可能会引发提升。提升就是将整个代码中所有的声明，包括变量和函数，“移动”到其各自作用域的最前端。

1. 变量提升：就是把所有的变量声明提升到当前的作用域最前面，不提升赋值操作

2. 函数提升：就是把所有的函数声明提升到当前作用域的最前面，但不调用函数

   - 案例1：成功打印 'Are'

   ```js
   fn();
   function fn() {
       console.log('Are');
   }
   ```

   预解析具体过程如下

   ```js
   function fn() {
       console.log('Are');
   }
   fn();
   ```

   

   - 案例2：TypeError 报错

   ```js
   foo();
   var foo = function() {
       console.log('you');
   }
   ```

   预解析具体过程如下

   ```js
   var foo;
   foo();
   foo = function() {
       console.log('you');
   }
   ```

   

   综合案例：

   ```js
   f1();
   console.log('c1 = ' + c);
   console.log('b1 = ' + b);
   console.log('a1 = ' + a);
   function f1() {
       var a = b = c = 9; // 未声明就赋值，b和c变为全局变量
       console.log('a2 = ' + a);
       console.log('b2 = ' + b);
       console.log('c2 = ' + c);
   }
   ```

   预解析具体过程如下

   ```js
   function f1() {
       var a;
       a = b = c = 9;
       console.log(a); // 9
       console.log(b); // 9
       console.log(c); // 9
   }
   f1();
   console.log(c); // 9
   console.log(b); // 9
   console.log(a); // ReferenceError: a is not defined
   ```



如果同时声明了同名的变量和函数，函数声明优先

```js
console.log(foo);
function foo() {
    console.log('我是函数');
}
var foo;
console.log(foo)
```



预解析后结果如下，函数声明会被提升到普通变量声明之前。然后，普通变量声明会被当做重复声明，进而被忽略掉。

```js
function foo() {
    console.log('我是函数');
}
/* var foo */
console.log(foo);
console.log(foo);
```

```js
var a = 11;
console.log(a);
function a() {
	console.log('嘿嘿嘿');
}
a();
```



预解析后结果如下，虽然普通变量a的声明重复了，被忽略了。但在第4行又将11赋值给函数a。a又从 function 变为 number

```js
function a() {
	console.log('嘿嘿嘿');
}
/* var a; */
a = 11;
console.log(a); // 11
a(); // TypeError: a is not a function
```



每个作用域中都会有预解析，函数内部也会有预解析，递归解析

```js
var num = 10;
foo();
function foo() {
    console.log(num);
    var num = 223;
}
console.log(num);
```

预解析后结果如下

```js
var num;
function foo() {
    var num = 233;
    console.log(num); // 233
    num = 233;
}
num = 114;
foo();
console.log(num); // 114
```



## 数据在内存中的存放方式

值类型( 基本类型 )的变量的变量名指向了系统在栈中开放的一个空间，这个栈空间内存放的是这个变量的值。

引用类型( 复杂类型 )的变量的变量名指向了一个栈空间，里面存放了一个堆地址，在堆中的这个地址上才真正存放了引用类型数据。

![avatar](D:\noobNotes\images\屏幕截图 2020-10-18 133240.jpg)

当我们把引用类型的变量传给形参时，其实是把变量在栈空间里保存的堆地址赋值给了形参。此时，形参和实参保存的是同一个堆地址，对形参的操作会影响实参。有点像C语言里的指针。

例如：

```js
var num = 10;
function fn(tmp) {
// 形参，就相当于局部变量，可以看作在这里声明了局部变量tmp，即var tmp = 10
  tmp = 99;
  console.log(tmp); // 99
}
fn(num);
console.log(num); // 10
```

```js
var obj = {
  name:"zhangSan",
  age:18
}
function fn(tmp) {
  tmp.name = "lsp";
  console.log(tmp.name); // lsp
}
fn(obj);
console.log(obj.name); // lsp
```



## 对象

### 对象里面属性的调用

1. 对象.属性
2. 对象['属性名']，中括号内的属性名必须加引号，或者中括号内不直接是属性的名称，而是一个变量，该变量内存着属性的名称。

```js
let obj = {
    name: 'tango',
    age: 18,
    score: 59
}
let score = 'name';
console.log(obj['score']); // 59
console.log(obj[score]); // tango
```



### 对象的属性和方法简写

当属性值和属性名相同时，可省略一个

```js
var a = 3
var b = 4
var obj = {
    a,
    b,
}
console.log(obj.a)
```

方法可省略 function，注意是由传统函数声明简写而来的，不是由箭头函数简写而来的

```js
var loc = 'outter' //  用var声明挂载到window上
var obj = {
    loc: 'inner',
    fun() {
        console.log(this.loc)
    },
    arrow: () => {
        console.log(this.loc)
    }
}
obj.fun() // 打印对象obj的loc属性值
obj.arrow() // 打印window的loc属性值
```



### 遍历对象

```js
var obj = {
    name: 'mi',
    age: 18,
    sex: 'male',
    sing: function(){
        console.log('awsl');
    }
}
for (var key in obj) {
    console.log(obj[key]);
}
```



### JavaScript 内置对象

js自带的一些对象，这些对象提供了一些现成的属性和方法可以供开发者使用

Math 对象，提供了

1. Math.PI
2. Math.floor() 向下取整，可隐式转换
3. Math.ceil() 向上取整，可隐式转换
4. Math.round() 四舍五入取整，可隐式转换
5. Math.abs() 取绝对值，可隐式转换
6. Math.max() / Math.min() 最大/最小值。有字符型传入，返回NaN。无参传入，返回-Infinity



### 函数 arguments 对象

每个函数都内置了一个 arguments 对象，arguments 对象中存储了传递的所有实参。arguments 是以伪数组的形式展示的。伪数组具有以下特点：

- 具有 length 属性
- 按索引方式存储数据，因此也可以遍历
- 不具有数组的方法，比如 push、pop 等

不知道输入的参数个数的时候，arguments 对象很好用，例如求最大值函数

```js
function getMax() {
    var max = arguments[0];
    for (var i = 0; i < arguments.length; i++) {
        if (arguments[i] > max) {
            max = arguments[i];
        }
    }
    console.log(max);
}
getMax(1, 3, 5, 7, 9)
getMax(93, 156, 10, 14)
```



## 数组方法

### push() —— pop()

### unshift() —— shift()

push 在数组结尾加元素，unshift 在数组开头加一个元素。然后都会返回数组的新长度

### reverse()

颠倒数组中的元素

### sort() 

对数组元素进行排序，括号内需要指明一个比较函数compareFunction

```js
var arr1 = [12, 4, 78, 2, 1]
arr1.sort(function(a, b) {
    return a - b; // 升序排列，return b - a 就是降序排列
});
console.log(arr1);
```

### indexOf()

在数组中从前向后查找指定元素，返回第一个符合要求的元素索引号。如果找不到返回-1

### lastIndexOf()

从后向前查找，其他同上

### toString()

将数组转换为字符串，原先元素用逗号间隔

### join()

将数组转换为字符串，可以自行设置间隔符合

```js
var arr1 = [1, 3, 5, 7, 9];
console.log(arr1.join(" and "));
```

### concat()

连接几个数组，返回连接完成的数组，不影响原数组

### slice(start, end) 



### splice(start, end) 





## 字符串方法

字符串是基本数据类型，按理来说应该没有方法，方法是复杂数据类型 Object 该有的。然而，众所周知，字符串有 length 方法。这是因为 javascript 将简单数据类型包装成复杂数据类型。每当我们读取一个基本类型的值的时候，后台会自动给我们创建一个对应的基本包装类型的对象，从而让我们能调用他们的方法。比如创建了一个字符串并调用他的方法。

```js
var s1 = "some text";
var s2 = s1.substring(2);
```

实际执行了：1. 创建 String 类型的一个实例；2. 在实例上调用指定的方法；3. 销毁这个实例

```js
var s1 = new String("some text");
var s2 = s1.substring(2);
s1 = null;
```

字符串的所有方法都不会修改字符串本身，字符串是不可变的，操作完成后会返回一个新的字符串，也就是新开辟一个内存空间存放新的字符串。所以尽量少进行字符串拼接的操作，这样会造出很多弃用字符串，他们存在内存中但无法被访问，浪费性能。

### indexOf(tango, [start]) 

从索引号为start的字符开始查找目标tango，例如查找"abcoefoxyozzopp"中所有的"o"出现的位置

```js
   var str = "abcoefoxyozzopp";
   var res = [];
   var start = 0;
   while (str.indexOf("o", start) !== -1) {
       start = str.indexOf("o", start);
       res.push(start++);
   }
   console.log(res);
```



### charAt() 和 charCodeAt()

返回指定索引号位置的字符或字符ASCII编码

```js
var str = 'andy';
console.log(str.charAt(2));
console.log(str.charCodeAt(2));
console.log(str[2]); // H5的新方法
```



### String.prototype.replace('oo', 'xx')

将字符串中的'oo' 替换为'xx'



### String.prototype.split()

将字符串转换为数组，join() 方法的逆方法

```js
var str = "red and pink and blue and purple";
var arr = str.split(" and ");
console.log(arr); // (4) ["red", "pink", "blue", "purple"]
```



### toUpperCase() 和 toLowerCase()



### substring(start, end)

截取字符串中索引号为 start 到索引号为 end-1 的字符



### substr(start, len)

截取从索引号为 start 的字符开始的共 len 个字符，参数 len 省略则截取到最后
