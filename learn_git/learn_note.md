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