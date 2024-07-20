# project 5: Objective and Subjective Quality Evaluation of Web Content / Attribute Analysis of Short Video Content on Platforms like TikTok

## project description

项目5：网页内容的主客观质量评价/抖音等短视频内容的属性分析
分组方案：3-4人/组，进行网页内容（多模态：图像、文本、视频、评论等）的质量评价，可以从多个维度来进行评价，例如内容的客观质量和主观质量、包括正能量性、积极性等。

题目来源：横向项目
可以专门针对抖音上的短视频来对其正能量特性进行分析，或者专门针对抖音上的短视频来分析视频内容是否违规，或者是否属于重复（例如：事件的个体不同，但是内容是重复的），以及情感倾向等。

研究方案：
先爬取抖音短视频，或者访问开源网页代码，爬取相关内容。
然后用大模型，例如CLIP，CLAP，CLIP4CLIP，SAM等模型来都内容进行解析。
最后再将内容进行质量评价。

It's seems that we need to use crawler to fectch videos in douyin(tiktok in China), and then use large models, CLIP4CLIP for example, to analyze them. Trying to find out whether it's illegal or expressing positive values or not. Finally, we analyze the output of the model and have a result.

So the key is to learn about how to use crawler and the models.


什么是视频的情绪分析，视频中可能出现多个人，每个人的情绪也可能随时间变化。是指视频的价值导向吗？

## preparation

* CLIP: Contrastive Language-Image Pre-training
OpenAI开发的一种深度学习模型，旨在理解和关联图像和文本数据。
Designed to understand and relate image and text data.

* CLAP: Contrasive Language-Audio Pre-training
可以看作CLIP在音频领域的扩展，使用对比学习将音频和文本映射到同一个向量空间，从而让模型能够理解音频内容与文本描述之间的关系。
Designed to understand the relationship between audio content and text description.

* CLIP4CLIP
一个基于CLIP架构的视频理解模型，扩展了CLIP的能力，使其能够处理视频数据。CLIP4CLIP能够从视频中提取有意义的信息，并将其与文本描述相匹配。可以用于视频检索、视频字幕生成以及视频内容理解等任务。
CLIP4CLIP can extract meaningful information from videos and match it with text descriptions. It can be used for tasks such as video retrieval, video subtitle generatioin, and ==video content understanding==.
[paper](https://arxiv.org/pdf/2104.08860.pdf)
[code](https://github.com/ArrowLuo/CLIP4Clip)

CLIP4CLIP may be useful in our project, but we haven't learnt about how to use it.


