# 廖雪峰Git教程

[TOC]

## 学到的Git命令总结

Git命令（除`git init`外）均需要在Git管理目录内执行

1. `git init` 将当前目录变为Git可以管理的目录
2. `git add <file1> <file2> ...` 将文件提交到暂存区
3. `git commit -m <messages>` 将文件从暂存区提交到版本库
4. `git status` 查看版本库当前的状态，
5. `git diff`系列：比较两个区域内文件的不同, 有三种用法
   1. 工作区&暂存区 `git diff <file>` 即尚未缓存的改动
   2. 工作区&版本库 `git diff HEAD <file>` 即尚未提交的改动
6. `git reset`系列：调整文件的版本
   1. `git reset --hard HEAD^`：通过`^`的个数来表示回退几个版本
   2. `git reset --hard <commit id>`：通过`commit id`（版本号）转到目标版本
7. `git log` 查看提交历史，以便确定要回退到哪个版本，可加上`--pretty=oneline`获取概要信息
8. `git reflog` 查看命令历史，以便确定要回到未来的哪个版本
9. `git checkout -- <file>` 丢弃工作区的修改（工作区修改后还未加入暂存区时）（即用版本库里的版本替换工作取得版本）
10. `git reset HEAD <file>` 丢弃暂存区的修改（工作区修改且加入暂存区但还没有提交时）
11. `ssh-keygen -t rsa -C <my email>` 创建SSH密钥
12. `git remote add origin git@server-name:path/repo-name.git`关联一个远程库。其中server-name, repo-name分别为服务器名称，远程库名称。eg：`git remote add origin git@github.com:ACY222/learngit.git`
13. `git push origin master`推送master分支的所有内容到远程库中。若为首次推送，需要加上参数`-u`，即`git push -u origin master`
14. `git remote -v`查看远程库信息
15. `git remote rm <repo-name>`解除本地库和远程库的关联关系


## 创建版本库

通过`git init`命令将当前目录变为 Git 可以管理的目录。

执行命令之后，当前目录下多了一个`.git`的目录，Git 使用该目录来跟踪管理版本库。`.git`默认是隐藏的，所以可能看不到它，用`ls -ah`命令就可以看见。

## 把文件添加到版本库

所有的版本控制系统只能跟踪文本文件的改动。如TXT文件、网页、所有的程序代码等（Microsoft 的 `word` 使用二进制格式，所以版本控制系统无法跟踪`word`文件的改动）。文本编码建议使用标注的UTF-8编码。

将文件放到Git版本库需要两步：
1. 使用命令`git add <file1> <file2> ...`将文件提交到暂存区
2. 使用命令`git commit -m <messages>`将文件提交到版本库

## 时光机穿梭——文件版本控制

通过`git status`可以看出版本库当前的状态, 了解到文件是否被修改。若已知有文件被修改过，可以用`git diff`看修改的结果。

### 版本回退

不断对文件修改，然后不断提交到版本库里，就像每段修改后保存一个快照，当错误地修改了文件或误删后，可以恢复到某个快照，然后继续工作。

在Git中，用`git log`命令查看保存过的所有快照，eg：
```
$ git log
commit 1094adb7b9b3807259d8cb349e7df1d4d6477073 (HEAD -> master)
Author: Michael Liao <askxuefeng@gmail.com>
Date:   Fri May 18 21:06:15 2018 +0800

    append GPL

commit e475afc93c209a690c39c13a46716e8fa000c366
Author: Michael Liao <askxuefeng@gmail.com>
Date:   Fri May 18 21:03:36 2018 +0800

    add distributed

commit eaadf4e385e865d25c48e7ca9c8395c3f7dfaef0
Author: Michael Liao <askxuefeng@gmail.com>
Date:   Fri May 18 20:59:18 2018 +0800

    wrote a readme file
```
如果嫌输出信息太多，可以加上`--pretty=oneline`参数：
```
$ git log --pretty=oneline
1094adb7b9b3807259d8cb349e7df1d4d6477073 (HEAD -> master) append GPL
e475afc93c209a690c39c13a46716e8fa000c366 add distributed
eaadf4e385e865d25c48e7ca9c8395c3f7dfaef0 wrote a readme file
```
其中长串字符是`commit id`（版本号），可以利用它进行回溯。

在Git中，用`HEAD`表示当前版本，上一个版本是`HEAD^`，上上个版本是`HEAD^^`，往上n个版本是`HEAD~n`。
故可以用`git reset --hard HEAD^`回溯到上一个版本，也可以用`git reset --hard <commit id>`回溯，其中<commit id>不需要写全，前几位就可以，只要Git可以用它找到唯一的版本号。当回退到某个版本后，可以用`git reflog`查询回退前的版本号，从而使用`git reset --hard <commit id>`再回到未来。

### 工作区和暂存区

#### 工作区(Working Directory)

我在电脑里能看到的目录就是工作区

#### 版本库(Respository)

工作区中的隐藏目录`.git`不是工作区，而是Git的版本库。

Git的版本库中存了很多东西，其中最重要的就是称为`stage`（我的计算机中叫`index`）的暂存区，还有Git自动创建的第一个分支`master`，已经指向`master`的一个指针`HEAD`。

### 管理修改

Git跟踪并管理的是修改，而非文件。

eg：第一次修改->`git add`->第二次修改->`git commit` 只会提交第一次修改的内容
解决方法为: 
1. 第一次修改->`git add`->第二次修改->`git add`->`git commit`
2. 第一次修改->`git add`->`git commit`->第二次修改->`git add`->`git commit`

第一种方法中，由于第一次修改未提交，所以以后不能在回溯到该版本。故第二种方法更好。

### 撤销修改

1. 当文件修改后还没放到暂存区，可以使用命令`git  checkout -- <file>`撤销修改。
2. 当文件修改后并放到了暂存区，可以使用命令`git reset HEAD <file>`将暂存区的修改撤销掉(unstaged)，重新放回工作区，然后转1。
3. 文件修改后提交到了版本库，可以进行版本回退。

### 删除文件

一般情况下，会直接在文件管理器中删除无用的文件，或是在终端中使用`rm <file>`删除。
这时，工作区和版本库不一致，有两种情况：
1. 我确实需要从版本库中删除该文件，那就用命令`git rm <file>`删除，并且`git commit ...`，文件就从版本库中被删除
2. 删错了，可以用命令`git checkout -- test.txt`将误删的文件恢复到最新版本

## 远程仓库

远程仓库是Git的杀手级功能之一。Git是分布式版本控制系统，同一个Git仓库，可以分布到不同的机器上。实际情况中，我们往往找一台电脑充当服务器的角色，每天24h开机，其他每个人 都从这个“服务器”仓库克隆(clone)一份到自己的电脑上，并且各自把各自的提交推送(push)到服务器仓库里，也从服务器仓库中拉取(pull)别人的提交。

网站***GitHub***就是提供Git仓库托管服务的。而获取Git远程仓库的方式如下：
1. 创建SSH Key。使用`ssh-keygen -t rsa -C <my email>`，然后一路回车，使用默认值即可创建。之后在用户主目录（即`~`，在Git Bash中可通过`cd ~`转到）（而不是工作区所在目录）中找到`.ssh`目录，里面有`id_rsa`和`id_rsa.pb`两个文件，这两个就是SSH Key的密钥对，前者是私钥，后者是公钥。
2. 登录***GitHub***，打开`settings`,`SSH and GPG keys`页面，点击`New SSH key`，在Key文本框中粘贴`id_rsa.pub`文件内容后点击`Add SSH Key`即可看到已经添加的Key。(在我的计算机中，不能直接打开`id_rsa.pub`文件，可通过Git Bash中的`cat id_rsa.pub`命令或power shell中的`type id_rsa.pub`命令将该文件内容打印出来)

### 添加远程库

假设我们已经在本地创建了一个名为`learngit`的Git仓库，又在GitHub创建一个了一个名为`learngit`的空的Git仓库，想让两个仓库进行远程同步，这样GitHub上的仓库既可以作为备份，又可以让其他人通过该仓库来协作。

接下来，我们可以在本地`learngit`仓库下运行命令：`git remote add origin git@server-name:path/repo-name.git`。添加后，远程库的名字就是`origin`，这是Git默认的叫法。
下一步可以用命令`git push -u origin master`把本地库的所有内容推送到远程库上。
用`git push`命令，实际上是把当前分支`master`推送到远程。

由于远程库是空的，我们第一次推送`master`分支时，加上了`-u`参数，Git不但会把本地的`master`分支内容推送到远程新的`master`分支，还会把本地的`master`分支和远程的`master`关联起来，在以后的推送或拉取时就可以简化命令为`git push origin master`。

### 删除远程库

如果添加时地址写错了，或者是想删除远程库，可以用`git remote rm <name>`命令。使用前，可以先用`git remote -v`查看远程库信息，然后根据名字删除。

注意，此处的“删除”其实时解除了本地和远程的绑定关系，并不是物理上删除了远程库，远程库本身没有任何改动。要想真正删除远程库，需要登录到GitHub中删除。

### 从远程库克隆

假设我们从零开发，那么最好的方式是先创建远程库，然后从远程库克隆。

首先登陆GitHub，创建一个新的仓库`gitskills`。下一步用命令`git clone git@server-name:path/repo-name.git`克隆一个本地库：`git clone git@github.com:ACY222/gitskills.git`。这样，本地库中就有了远程库的文件。

## 分支管理

可用于多人协作——每个人克隆源码后分别完成自己的工作，完成后再合并。这样的话，当某个人的工作未完成时不会影响他人的工作。

### 创建与合并分支

Git将每次提交串成一条时间线，这条时间线就是一个分支。截止到目前，只有一条时间线，在Git里，这个分支叫主分支，即`master`分支。Git用`master`指向最新的提交，再用`HEAD`指向`master`，就能确定当前分支。实际上，`HEAD`指向当前分支。

当我们创建新的分支如`dev`时，Git新建了一个指针叫`dev`，指向`master`相同的提交，再把`HEAD`指向`dev`，就表示当前分支在`dev`上。我们的后续操作就在`dev`分支上进行，而`master`分支保持不动。

具体实现：
1. `git branch <branch>` 创建分支
2. `git checkout <branch>` 或 `git switch <branch>`切换分支
3. `git checkout -b <branch>`或`git switch -c <branch>`创建+切换分支
4. `git branch`查看已有分支，当前分支前面会标一个`*`号
5. `git merge <branch>`合并指定分支到当前分支
6. `git branch -d <branch>`删除指定分支

### 解决冲突

当我们在不同的分支中的修改产生冲突时（eg：对同一行内容修改为不同的结果），必须首先解决冲突，解决冲突后再提交，合并完成。

解决冲突就是把Git合并失败的文件手动编辑为我们希望的内容，再提交。

用`git log --graph`命令可以看到分支合并图。

### 分支合并策略

通常，合并分支时，如果可能的话，Git会使用`Fast Forward`模式，但这种模式下，删除分治后，会丢掉分支信息。

如果禁用`Fast Forward`模式，Git会在merge时生成一个新的commit，这样，从分支历史上就可以看出分支信息。

实现方式为`git merge --no-ff -m <messages> <branch>`，eg：`git merge --no-ff -m "merge with no-ff dev`

#### 分治策略

在实际开发中，我们应该按照几个基本原则进行分支管理：

首先，`master`分支应该是非常稳定的，也就是仅用来发布新版本，平时不能在上面干活；干活都在`dev`分支上，到某个时候，比如1.0版本发布时，再把`dev`分支合并到`master`上，在`master`分支发布。

我和团队成员每个人都在`dev`分支上干活，每个人都有自己的分支，时不时往`dev`分支上合并就可以。

### bug分支

