 

**目录**

[一、配置STM32开发环境](about:blank#%E4%B8%80%E3%80%81%E9%85%8D%E7%BD%AESTM32%E5%BC%80%E5%8F%91%E7%8E%AF%E5%A2%83)

[（一）安装jdk](about:blank#%EF%BC%88%E4%B8%80%EF%BC%89%E5%AE%89%E8%A3%85jdk)

[（二）安装STM32CubeMX](about:blank#%EF%BC%88%E4%BA%8C%EF%BC%89%E5%AE%89%E8%A3%85STM32CubeMX)

[（三）安装固件库](about:blank#%EF%BC%88%E4%B8%89%EF%BC%89%E5%AE%89%E8%A3%85%E5%9B%BA%E4%BB%B6%E5%BA%93)

[二、使用CubeMX生成代码](about:blank#%E4%BA%8C%E3%80%81%E4%BD%BF%E7%94%A8CubeMX%E7%94%9F%E6%88%90%E4%BB%A3%E7%A0%81)

[三、波形观察](about:blank#%E4%B8%89%E3%80%81%E6%B3%A2%E5%BD%A2%E8%A7%82%E5%AF%9F)

[四、体会](about:blank#%E5%9B%9B%E3%80%81%E4%BD%93%E4%BC%9A)

[五、参考文献](about:blank#%E4%BA%94%E3%80%81%E5%8F%82%E8%80%83%E6%96%87%E7%8C%AE)

* * *

一、配置STM32开发环境
-------------

#### （一）安装jdk

STM32CubeMX基于Java实现的，需要安装jdk环境。

下载连接：[https://www.st.com/en/development-tools/stm32cubemx.html](https://www.st.com/en/development-tools/stm32cubemx.html "https://www.st.com/en/development-tools/stm32cubemx.html")

### （二）安装STM32CubeMX

下载地址：[https://www.st.com/en/development-tools/stm32cubemx.html](https://www.st.com/en/development-tools/stm32cubemx.html "https://www.st.com/en/development-tools/stm32cubemx.html")

1'以管理员身份运行.exe文件

![](https://i-blog.csdnimg.cn/direct/8ee08f5c6ab3404da47060c9e19889cc.png)

2.任选一个安装，建议选择install for me only

![](https://i-blog.csdnimg.cn/direct/9b25f7eb6dc64b5398c4520a76f25972.png)

3.选择next

![](https://i-blog.csdnimg.cn/direct/bafc7f5b0e04432daba31be1b634136b.png)

4、勾选accept ，接着选择next

![](https://i-blog.csdnimg.cn/direct/83f2140af67d442dbccaaaa75b627a64.png)  
5.勾选understood，接着选择next  
![](https://i-blog.csdnimg.cn/direct/c4f1b2794af74c8d95ee4558ffc3c85f.png)  
6.选择下载地址，注意路径中不要有中文，接着选择next

![](https://i-blog.csdnimg.cn/direct/a4ce7b5f481143989ab7ec63f1ee6751.png)

7.选择YSE

![](https://i-blog.csdnimg.cn/direct/430cea1a8e224cbbbdab41b286247e21.png)

8.默认选项即可，选择next

![](https://i-blog.csdnimg.cn/direct/65e532c4d2da4c7496fb97b736fb8f3e.png)

9.等待安装完成即可

![](https://i-blog.csdnimg.cn/direct/d09a21cd9c764e48a966cf855b8b7083.png)

![](https://i-blog.csdnimg.cn/direct/c57cb51b2f2e402691f7619dc399918e.png)

### （三）安装固件库

1.运行CubeMX

![](https://i-blog.csdnimg.cn/direct/6667570c929a48658384f255904828fe.png)

2.点击HELP，选择Manage

![](https://i-blog.csdnimg.cn/direct/dfb968f411e14658b5bec9f67f5baa4a.png)

3.选择适配开发板的固件库进行安装，这里选用的STM32F1

![](https://i-blog.csdnimg.cn/direct/d2800bb5cfe74f70be14a1334071dda6.png)

二、使用CubeMX生成代码
--------------

1.创建新工程

![](https://i-blog.csdnimg.cn/direct/11282ffa94984d428021d89fdb2d9d23.png)2.选择芯片

![](https://i-blog.csdnimg.cn/direct/32d7e5bfd1904344b830a62b0767818b.png)

3.SYS选择Senal Wire

![](https://i-blog.csdnimg.cn/direct/2758855bd5574c1c82cbe30410ee0b8c.png)

4.RCC选择Crystal/Ceramic Resonator

![](https://i-blog.csdnimg.cn/direct/506fd30e993b4b8fac21ae35878f5759.png)

5.GPIO配置端口选择，在芯片的引脚上右键想用的端口设置为GPIO\_OUTPUT，这里选择的是PA15,PB0,PC13

![](https://i-blog.csdnimg.cn/direct/b3ee725c66664f5a8cae87ea221f5724.png)

3个引脚GPIO输出类型都选择高电平

![](https://i-blog.csdnimg.cn/direct/1d52ac747ace4e438c007b2a61ebf9fb.png)

6.时钟配置

![](https://i-blog.csdnimg.cn/direct/685375edba504c468c59ee2a92cfb899.png)

7.Project Manager设置

![](https://i-blog.csdnimg.cn/direct/6d132bd87f494d59b289e63a001e4909.png)

![](https://i-blog.csdnimg.cn/direct/0477927e2ed94f2299da957b7f53b17c.png)

8.配置完毕后生成代码并打开

![](https://i-blog.csdnimg.cn/direct/8d22279fc8a54516ba6388b68c5326af.png)

![](https://i-blog.csdnimg.cn/direct/05ba52147581438784d755936eb0a650.png)

9.修改main中的while函数

![](https://i-blog.csdnimg.cn/direct/a0e4c53c0bc84935b2c1bbd1e50c465f.png)

```
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);  // 灯1亮
    HAL_Delay(1000); // 延时1s
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);  // 灯1灭
      
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);  // 灯2亮
    HAL_Delay(1000); // 延时1s
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);  // 灯2灭
      
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);  // 灯3亮
    HAL_Delay(1000); // 延时1s
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);  // 灯3灭
```

10.编译生成HAL文件

![](https://i-blog.csdnimg.cn/direct/cc5027ad52894e9c88b5344aa911734b.png)

11.效果图

![](https://i-blog.csdnimg.cn/direct/fbd71da7b597473ea680ed1e238c4528.gif)

三、波形观察
------

### KEIL仿真

1.设置debug

![](https://i-blog.csdnimg.cn/direct/f18bec6134f84c77afc5e7039fb959c8.png)

2.点击测试

![](https://i-blog.csdnimg.cn/direct/3cf587c9464c4d1e8248972b7e88031a.png)

3.选择逻辑分析仪

![](https://i-blog.csdnimg.cn/direct/0e24610443214e75b28a2c96e1b79ff7.png)

4.点击Setup

添加引脚，Display Tybe选择Bit，(PORTB & 0X00000000)>>

![](https://i-blog.csdnimg.cn/direct/5875756508944e18a7631efb91f657bc.png)

5.观察波形

![](https://i-blog.csdnimg.cn/direct/92d9de2e8ad44f399f1b7d2045f0d958.png)

可以看出每个引脚低电平约为1s高电平约2s为一个周期

### Proteus仿真

![](https://i-blog.csdnimg.cn/direct/55d9f69571c24f67b28f6c75cd1501de.png)

![](https://i-blog.csdnimg.cn/direct/b0f07568b73a42d4bce4f9eac3d0a7ce.png)

四、体会
----

通过本次HAL库的STM32流水灯实现，让我感受到了CubeMX的方便之处，只需要配置好GPIO引脚和一些其他设置就可以快速生成Keil代码，通过修改代码中的函数就可以达到想要的功能。

五、参考文献
------

[STM32基于HAL库流水灯实验\_hel库安装教程中文版-CSDN博客](https://blog.csdn.net/weixin_56102526/article/details/120877293 "STM32基于HAL库流水灯实验_hel库安装教程中文版-CSDN博客")

  

本文转自 [https://blog.csdn.net/2403\_87623656/article/details/144153146?spm=1001.2014.3001.5502](https://blog.csdn.net/2403_87623656/article/details/144153146?spm=1001.2014.3001.5502)，如有侵权，请联系删除。