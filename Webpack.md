# Webpack



## 初步创建项目

1. 新建一个项目文件夹，在文件夹内运行`npm init -y`，初始化包配置文件 package.json

2. 新建 src 文件夹，新建 src --> index.html

3. `npm install webpack webpack-cli -D`。在项目根目录里创建文件名为 webpack.config.js ，对该文件初始化配置

   ```js
   module.exports = {
       mode: 'development'
   }
   ```

4. 在 package.json 配置文件中的 scripts 节点下，新增 dev 脚本

   ```js
   "scripts": {
       "dev": "webpack"
   }
   ```

5. `npm run dev` ，启动 webpack 进行项目打包。打包完成后，项目根目录中新生成了 dist 文件夹。于是，将 src --> index.html 中，scripts 引用路径修改为 "../dist/main.js"

   ```html
   <script src="../dist/main.js"></script>
   ```

6. 配置自动打包功能：`npm i webpack-dev-server -D`

7. 在 package.json 中的 scripts 节点修改为如下

   ```js
   "scripts": {
       "dev": "webpack-dev-server"
   }
   ```

8. 将 src --> index.html 中，scripts 引用路径修改为 "/main.js"

   ```html
   <script src="/main.js"></script>
   ```

9. 进一步修改 package.json 中的 scripts 节点。比如，打包完成后自动打开网页，变更 IP 地址，变更端口号

   ```js
   "scripts": {
       "dev": "webpack-dev-server --open --host 127.0.0.127 --port 8848"
   }
   ```

10. 此时网页加载的默认页面是项目根目录。体验很差，可以修改默认加载 index.html。加载`npm i html-webpack-plugin -D`

11. 在 webpack.config.js 文件中修改如下配置

    ```js
    const path = require("path")
    const HtmlWebpackPlugin = require("html-webpack-plugin")
    const htmlPlugin = new HtmlWebpackPlugin({
    	template: "./src/index.html",
        filename: "index.html",
    })
    
    module.exports = {
        mode: "development",
      	plugins: [htmlPlugin],
    }
    ```



## 加载 less, scss, 图片字体



### 先加载 css 加载器

1. 无论是 less 还是 scss 加载器都要先预先加载 css 加载器。

   `npm i style-loader css-loader -D`

2. 还可以加载一个自动添加浏览器 css 兼容性前缀的插件 postCSS。

   `npm i postcss-loader autoprefixer -D`

3. 在项目根目录中创建 postcss 配置文件 postcss.config.js，并作如下配置

   ```js
   const autoprefixer = require('autoprefixer')
   module.exports = {
   	plugins: [autoprefixer]
   }
   ```

### less 加载器

1. 加载两个包 `npm i less-loader less -D`

2. 在 webpack.config.js 的 module --> rules 数组中，添加 loader 规则如下

   ```js
   rules: [
   	{
   		test: /\.less$/,
           use: ["style-loader", "css-loader", "postcss-loader", "less-loader"],
   	},
   ]
   ```

3. 在 src --> index.js 中添加 `import './assets/less/index.less'`

### scss 加载器

1. 加载两个包 `npm i sass-loader node-sass -D`

2. 在 webpack.config.js 的 module --> rules 数组中，添加 loader 规则如下

   ```js
   rules: [
   	{
   		test: /\.scss$/,
           use: ["style-loader", "css-loader", "postcss-loader", "sass-loader"],
   	},
   ]
   ```

3. 在 src --> index.js 中添加 `import './assets/scss/index.scss'`

### 图片和字体文件加载器

1. 如果没有图片加载器，此时 css，less，scss中 的背景图片是无法加载的。

2. 加载两个包 `npm i sass-loader node-sass -D`

3. 在 webpack.config.js 的 module --> rules 数组中，添加 loader 规则如下

   ```js
   rules: [
   	{
   		test: /\.jpg|png|gif|bmp|ttf|eot|svg|woff|woff2$/,
           use: "url-loader?limit=1024",
   	},
   ]
   ```

4. 在 src --> index.js 中添加 `import './assets/scss/index.scss'`



## 打包处理 js 高级语法

1. 安装 babel 转换器包：`npm i babel-loader @babel/core @babel/runtime -D`

2. 安装 babel 语法插件包：`npm i @babel/preset-env @babel/plugin-transform-runtime @babel/plugin-proposal-class-properties -D`

3. 在根目录中创建 babel.config.js 并初始化配置

   ```js
   module.exports = {
   	presets: ['@babel/preset-env'],
   	plugins: ['@babel/plugin-transform-runtime', '@babel/plugin-proposal-class-properties']
   }
   ```

4. 在 webpack.config.js 的 module --> rules 数组中，添加 loader 规则

   ```js
   rules: [
   	{
   		test: /\.js$/,
           use: 'babel-loader',
           exclude: /node_modules/,
   	},
   ]
   ```

   