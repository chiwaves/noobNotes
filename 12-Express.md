## express搭建

1. 安装express

   ```sh
   npm i express -D
   ```

   ```js
   const express = require ('express');
   const app = express();
   
   app.listen(3001); // 监听localhost:3001
   ```

   

## 服务器代理

1. 配置path

   ```js
   const path = require ('path');
   app.use(express.static(path.join(__dirname, 'public')));
   // 将静态资源文件，比如html放在public目录下
   ```

   

2. 安装request并配置代理服务器

   ```sh
   npm i require -D
   ```

   ```js
   const request = require ('request');
   
   // 如果用的是post方式，还要安装body-parser插件
   app.get('/xxx', (req, res) => {
     let msg = req.query.msg;
     let url = `http://api.qingyunke.com/api.php?key=free&appid=0&msg=${msg}`;
     request(url, (err, response, body) => {
       res.send(body);
     })
   })
   ```

   

## express搭配node-sass食用

- node-sass并不一定是非要在vue-cli中使用，如果node后台使用express框架一样可以加载node-sass插件然后愉快的食用sass。具体步骤如下：

1. 全局安装

   ```sh
   npm i node-sass -g
   ```

2. 在public目录下创建文件夹scss和css，分别在其中创建main.scss和main.css文件

3. 使用-w监听scss文件的变动，一旦发生变动就将其翻译到css文件中

   ```sh
   node-sass -w public\scss\main.scss public\css\main.css
   ```

   