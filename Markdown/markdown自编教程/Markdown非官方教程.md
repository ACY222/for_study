---
export_on_save:
    prince: true
---
# Markdown 使用教程

- [Markdown 使用教程](#markdown-使用教程)
  - [为什么要使用 Markdown](#为什么要使用-markdown)
  - [如何学习 Markdown 语法](#如何学习-markdown-语法)
  - [Markdown 基础语法](#markdown-基础语法)
    - [标题](#标题)
    - [段落](#段落)
    - [字体](#字体)
    - [列表](#列表)
    - [代码](#代码)
      - [行内代码](#行内代码)
      - [代码块](#代码块)
    - [图片](#图片)
    - [引用](#引用)
    - [链接](#链接)
    - [表格](#表格)
    - [任务清单](#任务清单)
  - [其他](#其他)
    - [编辑器推荐](#编辑器推荐)
    - [学习资源](#学习资源)
    - [Markdown 的方言问题](#markdown-的方言问题)

## 为什么要使用 Markdown

Markdown 有如下优点：
1. Markdown 兼具轻量与功能。`Word`过于臃肿，记事本又没有排版功能。而 Markdown 则集百家之长，成一家之言。
2. Markdown 是纯文本可移植的。即你可以用几乎所有的文本编辑器打开 Markdown 格式的文本文件（其后缀为`.md`），如果你不喜欢当前用来处理 Markdown 的软件，可以随时换掉他，这与 Microsoft Word 形成了鲜明对比。
3. Markdown 语法简单，学习成本较低:cool:。

---

## 如何学习 Markdown 语法

建议你去[markdown在线编辑器](https://markdown.com.cn/editor/)中，尝试对照着我的教程内容实现每一个语法，实现之后对着教程的目录，再***默写***一遍(~~因为自己淋过雨，所以要把别人的伞撕叉:drooling_face:~~)。

完成上面的内容之后，你基本上可以独立使用 Markdown 进行工作了（偶尔遇到没学过的语法或者是有遗忘，现查就可以）。

---

## Markdown 基础语法

### 标题

Markdown 通过在行首插入1-6个`#`实现标题效果，分别对应1-6级标题。
> eg: Markdown 的标题
> ```
> # this is title 1
> ## this is title 2
> ###### this is title 6
> ```
> # this is title 1
> ## this is title 2
> ###### this is title 6

尤其要注意的一个点是，`#`与标题内容之间需要有一个空格。实际上，写 Markdown 与写代码有一定的相似之处——有些地方对细节要求很高。如果你没有得到想要的结果，首先需要检查自己的语法是否正确，比如是否少了个空格等。

### 段落

Markdown 使用空白行（即回车）将文本进行分隔，从而实现段落的效果。
> eg: Markdown 的段落
> ```
> 中国科学技术大学是一所理工科大学。
>
> 学校现有31个学院（学部），含8个科教融合学院。
> ```
> 中国科学技术大学是一所理工科大学。
> 
> 学校现有31个学院（学部），含8个科教融合学院。

### 字体

Markdown 使用星号`*`和下划线`_`作为标记强调字符的符号，这里推荐使用`*`，~~因为我用的是星号，我觉得你应该和我保持一致~~。因为`*`更加常见，可读性更强。
> eg: Markdown 的字体
> *这是斜体*（`*这是斜体*`）
> **这是加粗**（`**这是加粗**`）
> ***这是加粗斜体***（`***这是加粗斜体***`）
> ~~这是加删除线~~（`~~这是加删除线~~`）

### 列表

Markdown 支持有序列表和无序列表。有序列表使用阿拉伯数字进行标记，无序列表使用星号`*`、加号`+`或减号`-`进行标记，与标题一样，符号与内容之间同样需要存在一个空格。

> eg: Markdown 有序列表
> ```
> 1. First item
> 2. Second item
> 3. Third item
> ```
> 1. First item
> 2. Second item
> 3. Third item

无序列表同样建议你使用`*`
> eg: Markdown 无序列表
> ```
> * First item
> * Second item
> * Third item
> ```
> * First item
> * Second item
> * Third item

列表可以嵌套，只需要加上正确的缩进。
> eg: Markdown 列表嵌套
> ```
> 1. First item
> 2. Second item
>   * Part 1
>   * Part 2
> 3. Third item
> ```
> 
> 1. First item
> 2. Second item
>   * Part 1
>   * Part 2
> 3. Third item

注：我在使用 Markdown 时，常常出现一些奇怪的缩进，自己尝试解决无果，又鲜有资料介绍这方面的内容，不过问题并不是很严重，所以至今没有解决。

### 代码

Markdown 中加入代码块有两种方式，行内代码与代码块。

#### 行内代码

嵌入行内代码使用"`"作为标记。行内代码常常用于转义或强调某些字符。
> eg: Markdown 行内代码
> ```
> 我很喜欢`vscode`这款软件
> ```
> 我很喜欢`vscode`这款软件

打电话时我提到的用来替代改变字体颜色的手段就是它。

#### 代码块

代码块一般用来展示代码，你暂时不需要，故不做介绍。

### 图片

标记图片的格式为`![picture name](/path to the picture)`
图片的路径问题比较麻烦，我建议使用插件解决，我目前用的是`Paste Image`，直接粘贴即可。

### 引用

Markdown 使用`>`来标记引用。
> eg: Markdown 引用
> ```
> > 我是奎桑提！
> ```
> > 我是奎桑提

实际上，你可以发现，这篇教程里面所有的举例都是通过引用和代码块实现的。

### 链接

标记链接的格式为`[title](https://www.example.com)`（是的，上次我演示时多加了一个感叹号`!`其实是图片的格式）。

> eg: Markdown 链接
> ```
> [bilibili](https://www.bilibili.com)
> ```
> [bilibili](https://www.bilibili.com)

### 表格

说实话，Markdown 中的表格用着不是很方便。它的格式是这样的：

> eg: Markdown 表格
> ```
> | Name | Age | Height | Weight |
> | ---- | --- | ------ | ------ |
> | ac   | 20  | 178    | 76     |
> | KSante | 0.4 | 5    | 0.01   |
> ```
> | Name | Age | Height | Weight |
> | ---- | --- | ------ | ------ |
> | ac   | 20  | 178    | 76     |
> | KSante | 0.4 | 5    | 0.1    |
> | Huifan | 18  | 160  | 50     |

### 任务清单

我非常喜欢的一个功能:smile:。格式是`- [x] task`或`- [ ] task`

> eg: Markdown 表格
> ```
> - [x] Have a good night
> - [ ] Get your height and weight data
> - [ ] Complete the tutorial
> ```
> - [x] Have a good night
> - [x] Get your height and weight data
> - [x] Complete the tutorial
> - [ ] Learn how to use markdown

## 其他

### 编辑器推荐

我只推荐一个——宇宙第一编辑器`vscode`，下载的话，你可以去网上找教程，~~或者是共享屏幕找我帮忙，但陆邢老师显然没有这么懒，这点主动性还是有的。~~

下载`vscode`后，需要再安装几个插件：
1. Chinese (Simplified)(简体中文) Language Pack for Visual Stdio Code
2. Markdown All in One
3. Markdown Preview Enhanced
4. Markdown PDF
5. Paste Image

也可以再安装一些插件获得更好的体验，比如更漂亮的背景，语法高亮，文件图标等，但都属于锦上添花，这里不赘述。

### 学习资源

详见上次给你发的文件。

### Markdown 的方言问题

实际上不同的 Markdown 应用程序实现的 Markdown 语法通常都略有不同。我们通常称之为`flavors`（方言）。掌握你的应用程序所实现的 Markdown 语法即可。