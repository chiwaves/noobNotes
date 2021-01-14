# Git 原理

Git 是分布式版本控制器。核心就是可以保存不同版本的代码。如果是单人开发，则可以快速滚到某个版本 (即某个分支) 。如果是多人开发，则方便合作编写。

即使 Git 本地仓库，也可以做到每个分支不相同。虽然是废话但方便理解

Git 和 Github 是两种东西，就好比雷锋和雷峰塔的关系。Git 是本地代码仓库，Github 是远程代码仓库。Github 的同类平台还有 Gitee，Gitlab 等



# 本地仓库版本控制

首先在项目文件夹中打开 vscode，打开控制台，运行 `git init` 初始化仓库，然后`git add .` 添加全部

`git commit -m"描述信息"` 提交全部

`git branch 新分支名` 创建新分支

`git checkout 分支名` 或者 `git switch 分支名` 切换到某个分支

在某个分支修改完，添加并提交后不会影响到其他分支的内容，切记 vscode 中的变基分支不是切换分支，切换分支老老实实在控制台输代码



# 直接克隆远程仓库

克隆远程仓库，无需初始化

`git clone 仓库地址`

用 vscode 重新打开下载下来的项目文件夹，比如上文中的 study，开始后续操作

默认下载下来的是项目的 master (main) 分支

`git branch` 查看分支列表

一个本地仓库只能克隆远程的一个分支。如果只想下载其他分支，可以使用

`git clone -b 分支名 仓库地址`

下载下来后，使用 `git branch` 查看所在分支的分支名就是下载的这个分支名，而不是 master

一般来说，克隆的远程仓库可能没有给你管理员权限。修改后 push 会提示  `remote: You do not have permission push to this repository` 

如果有权限，在本地修改后，直接三板斧即可上传。

```bash
git add .
git commit -m"描述信息"
git push
```

如果下载后，又在本地仓库创建了新的分支。在 push 到远程仓库时，需要补充填写仓库名和分支名，根据 vscode 提示来即可 `git push origin theBranch`



# 本地仓库与远程仓库同步