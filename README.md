
<!-- PROJECT SHIELDS -->

[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]

<!-- PROJECT LOGO -->
<br />

  
  <p align="center">
    一个基于VSCode+EIDE+SDCC开发51单片机的项目
    <br />
<!--     <a href="https://github.com/LL-WHUT/89C52"><strong>探索本项目的文档 »</strong></a> -->
    <br />
    <br />
<!--     <a href="https://github.com/LL-WHUT/89C52">查看Demo</a> -->
    ·
    <a href="https://github.com/LL-WHUT/89C52/issues">报告Bug</a>
    ·
    <a href="https://github.com/LL-WHUT/89C52/issues">提出新特性</a>
  </p>

</p>

## 目录

- [上手指南](#上手指南)
  - [开发前的配置要求](#开发前的配置要求)
  - [安装步骤](#安装步骤)
- [文件目录说明](#文件目录说明)
- [开发指南](#开发指南)
- [贡献者](#贡献者)
  - [如何参与开源项目](#如何参与开源项目)
- [版本控制](#版本控制)
- [作者](#作者)

### 上手指南




###### 开发前的配置要求

1. 一台联网电脑
2. 一块51单片机
3. 一双手和一个聪明的大脑🧠
###### **安装步骤**

1. Get a free API Key at [https://example.com](https://example.com)
2. Clone the repo

```sh
git clone https://github.com/LL-WHUT/89C52.git
```
3. 安装<a href="https://code.visualstudio.com/">VScode</a> 
4. 安装VScode插件<br>项目管理：EIDE<br>语法高亮和错误提示等：C/C++ 、 C/C++ Extension Pack 、 C/C++ Themes<br>版本控制(可选)：GitLens
5. 安装SDCC(Small Device C Compiler)<br>点击VSCode左边的EIDE图标，选择Configure Toolchain，点击第三个Small Device C Compiler(sdcc)。可以选择Online在线自动安装SDCC，也可以选择Local手动安装<a href="https://sdcc.sourceforge.net/snap.php#Windows">SDCC</a>
6. 安装<a href="https://www.python.org/downloads/windows/">Python</a>(可选)
7. 安装pyserial模块(可选)<br>终端执行
```sh
pip install pyserial
```

### 文件目录说明

```
filetree 
├─build
│  └─Debug
│      └─src  //编译出来的hex文件在这里
├─Documents
│      普中-2_普中-3_普中-4开发板原理图.pdf  //此项目所使用的开发板原理图
│
├─inc  //头文件存放位置
│      28byj48.h
│      delay.h
│      ds18b20.h
│      gled_display.h
│      keyscan.h
│      lcd1602.h
│      reg52.h
│      smg_display.h
│
├─src
│      main.c  //主函数位置
│
└─tools
        stcflash.py  //将hex文件烧录到单片机的Python程序
```

### **开发指南**
1. 打开本项目<br>EIDE图标 --> Open Project --> 选择项目中的89C52.code-workspace文件
2. 新建项目<br>EIDE图标 --> New Project --> Internal Template --> 89C52 SDCC Quickstart
3. 编写代码<br>主函数位于main.c
4. 构建<br>按钮位于VSCode右上角，也可以使用Build的快捷键F7
5. 烧录<br>如果之前安装了Python和pyserial，可以点击Build右边第二个按钮Program Flash(Ctrl+Alt+D)。如果没有安装pyserial，则可以使用stc-isp等软件选中Debug/src下的hex文件进行烧录。



### 贡献者

请阅读**CONTRIBUTING.md** 查阅为该项目做出贡献的开发者。

#### 如何参与开源项目

贡献使开源社区成为一个学习、激励和创造的绝佳场所。你所作的任何贡献都是**非常感谢**的。


1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request



### 版本控制

该项目使用Git进行版本管理。您可以在repository参看当前可用版本。

### 作者

ll-whut@whut.edu.cn   

 *您也可以在贡献者名单中参看所有参与该项目的开发者。*

### 版权说明

该项目签署了MIT 授权许可，详情请参阅 [LICENSE.txt](https://github.com/LL-WHUT/89C52/blob/master/LICENSE.txt)


<!-- links -->
[your-project-path]:LL-WHUT/89C52
[contributors-shield]: https://img.shields.io/github/contributors/LL-WHUT/89C52.svg?style=flat-square
[contributors-url]: https://github.com/LL-WHUT/89C52/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/LL-WHUT/89C52.svg?style=flat-square
[forks-url]: https://github.com/LL-WHUT/89C52/network/members
[stars-shield]: https://img.shields.io/github/stars/LL-WHUT/89C52.svg?style=flat-square
[stars-url]: https://github.com/LL-WHUT/89C52/stargazers
[issues-shield]: https://img.shields.io/github/issues/LL-WHUT/89C52.svg?style=flat-square
[issues-url]: https://img.shields.io/github/issues/LL-WHUT/89C52.svg
[license-shield]: https://img.shields.io/github/license/LL-WHUT/89C52.svg?style=flat-square
[license-url]: https://github.com/LL-WHUT/89C52/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=flat-square&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/shaojintian




