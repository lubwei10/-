 

**目录**

[一、配置STM32开发环境](about:blank#%E4%B8%80%E3%80%81%E9%85%8D%E7%BD%AESTM32%E5%BC%80%E5%8F%91%E7%8E%AF%E5%A2%83)

[二、使用CubeMX生成代码](about:blank#%E4%BA%8C%E3%80%81%E4%BD%BF%E7%94%A8CubeMX%E7%94%9F%E6%88%90%E4%BB%A3%E7%A0%81)

[三、总结](about:blank#%E4%B8%89%E3%80%81%E6%80%BB%E7%BB%93)

[四、参考文献](about:blank#%E5%9B%9B%E3%80%81%E5%8F%82%E8%80%83%E6%96%87%E7%8C%AE)

* * *

一、配置STM32开发环境
-------------

参考博客：[STM32基于HAL库的流水灯实验-CSDN博客](https://blog.csdn.net/2403_87623656/article/details/144153146?sharetype=blogdetail&sharerId=144153146&sharerefer=PC&sharesource=2403_87623656&spm=1011.2480.3001.8118 "STM32基于HAL库的流水灯实验-CSDN博客")

二、使用CubeMX生成代码
--------------

1.创建新工程

![](https://i-blog.csdnimg.cn/direct/8b03bf4ca9c54b6295923bedd3820250.png)

2.SYS选择Senal Wire

![](https://i-blog.csdnimg.cn/direct/4dfc85af3a7946f0a7a6388d645b5b90.png)

3.RCC选择Crystal/Ceramic Resonator

![](https://i-blog.csdnimg.cn/direct/7b9a55f94e004829977a70c00f62daa7.png)

2.选择芯片类型

![](https://i-blog.csdnimg.cn/direct/6250b17be4a94b1ea5c21ff20dc45cf3.png)

3.GPIO端口选择配置

选择 LED 灯引脚 PA5，设置引脚为输出模式 GPIO\_Output；  
选择作为外部中断的引脚 PB15，设置为与中断线 GPIO\_EXTI15 连接

![](https://i-blog.csdnimg.cn/direct/0ad29300479f480e89049a7a0cd48817.png)

将 GPIO\_PA5 命名为 LD1

![](https://i-blog.csdnimg.cn/direct/bd54eca2d18e4f018d1521c6e8528c09.png)

将 GPIO\_PB15 命令为 B1\_EXTI ，触发方式选择下降沿触发

![](https://i-blog.csdnimg.cn/direct/1b39058f618d47b99aeeb9c6e38dfae8.png)

配置中断优先级

![](https://i-blog.csdnimg.cn/direct/b3d611eb9e124914b93a57c30464d883.png)

4.生成并打开代码

![](https://i-blog.csdnimg.cn/direct/7880fc3a9b0d4e1abdf864e248af08a9.png)

![](https://i-blog.csdnimg.cn/direct/88775ccf8e0f4c4e9756ee8149223b5c.png)

![](https://i-blog.csdnimg.cn/direct/bfbd8a7a2f7846648d962e7bd194ac1d.png)

5.修改代码

在main函数中添加函数

![](https://i-blog.csdnimg.cn/direct/aed34b48d16d4ec89329278b67d529a3.png)

```

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) 
{ 
    if( GPIO_Pin == B1_EXTI_Pin ) // 判断外部中断源
        {
            HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin); // 翻转LD1状态
        }
}
```

6.生成编辑生成.hex文件

![](https://i-blog.csdnimg.cn/direct/43edcf1bf89e4819806d18b71a25dcbd.png)

![](https://i-blog.csdnimg.cn/direct/c43b3942d2334eb7a655485a702aeb07.png)

7.效果图

![](https://i-blog.csdnimg.cn/direct/28b96b852f5a47d890604bb6e0684192.gif)

三、proteus仿真
-----------

![](https://i-blog.csdnimg.cn/direct/a4c90b17ecba4235b5156c9979cfaf12.png)

四、总结
----

使用CubeMX生成代码能比较方便地实现中断控制灯的亮灭，但需要注意GPIO引脚高低电平的设置和优先级的处理。在实验中是用杜邦线模拟代替开关，不考虑消抖，如果是按键开关就需要延迟消抖处理。

五、参考文献
------

[HAL 库 STM32CubeMX 实现 LED 亮灭----中断模式\_stm32f103 中断控制两个led同时亮灭-CSDN博客](https://blog.csdn.net/m0_58892312/article/details/121004248 "HAL 库 STM32CubeMX 实现 LED 亮灭----中断模式_stm32f103 中断控制两个led同时亮灭-CSDN博客")

  

本文转自 [https://blog.csdn.net/2403\_87623656/article/details/144154183?spm=1001.2014.3001.5502](https://blog.csdn.net/2403_87623656/article/details/144154183?spm=1001.2014.3001.5502)，如有侵权，请联系删除。