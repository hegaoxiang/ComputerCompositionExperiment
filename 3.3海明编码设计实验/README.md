# 海明编码设计实验
## 海明码
### 构建海明码
![](https://raw.githubusercontent.com/hegaoxiang/ComputerCompositionExperiment/master/3.3%E6%B5%B7%E6%98%8E%E7%BC%96%E7%A0%81%E8%AE%BE%E8%AE%A1%E5%AE%9E%E9%AA%8C/Resource/CheckNo.png)
现在位置知道了，但是具体的值我们还不知道，那怎么来得到P1到Pn具体的值呢？
根据海明码的定义
![](https://raw.githubusercontent.com/hegaoxiang/ComputerCompositionExperiment/master/3.3海明编码设计实验/Resource/findPValue.png)
因此，我们成功获取到了校验位的值，即我们成功得到了原始数据的海明码（ps：图中采用偶校验计算P的值只是因为偶校验计算更为简单）
### 海明编码实验图如下
![](https://raw.githubusercontent.com/hegaoxiang/ComputerCompositionExperiment/master/3.3%E6%B5%B7%E6%98%8E%E7%BC%96%E7%A0%81%E8%AE%BE%E8%AE%A1%E5%AE%9E%E9%AA%8C/Resource/CircuitDiagram.png "海明编码实验电路图")（PS：异或门的多输入行为应该改为当奇数个1输入时输出1）
### 海明解码
当传输过程中，有**一位错误**发生时，我们可以上面求出的校验位和其校验的数据进行**异或**运算得到的一系列的值，然后这些值组合成一个二进制的数的十进制值就是出错的数据在**海明码**中的位置。
![](https://raw.githubusercontent.com/hegaoxiang/ComputerCompositionExperiment/master/3.3%E6%B5%B7%E6%98%8E%E7%BC%96%E7%A0%81%E8%AE%BE%E8%AE%A1%E5%AE%9E%E9%AA%8C/Resource/ExampleOfErrorCorrection.png "海明校验纠错举例")

求出G系列的值后，我们需要将其代表的位置上面的数字更正。其实就是将0变为1，1变为0。我们只需要将对应位置**与1异或**就可以了。这在电路中怎么实现呢？
在本题中，首先，我们通过logsim的**分离器**，将G1到G5的值连接起来构成一个5位的二进制数。然后利用一个常量1，通过一个**移位器**将1左移移到指定位置，即除了错误位置上为1，其余位置均为0的与海明码同位宽（22位）的二进制数。
然后，我们将这个数字与海明码相异或，就得到了修正后的海明码。
最后，再利用分离器，将对应位置的原始数据提出来，再再利用分离器，将这些提出来的1位的数据构成16位的数据。这样，我们就得到了正确的原始数据。
## 检错
对于本次实验，实验中有可能出现2位错误，这个时候，海明码无法纠错，但是可以检查到错误。但是单单对于海明码自身而言，他只知道出错了，不知道出了几位错。
![](https://raw.githubusercontent.com/hegaoxiang/ComputerCompositionExperiment/master/3.3%E6%B5%B7%E6%98%8E%E7%BC%96%E7%A0%81%E8%AE%BE%E8%AE%A1%E5%AE%9E%E9%AA%8C/Resource/errorExample.png "多位错误例子")
所以我们再利用偶校验进行一次检查，这样可以检查到两位错误。虽然说不可纠错，但是我们至少还是做了点事情。
偶校验时检测整个海明码，所以偶校验位添加在海明码的最后面。当偶校验检测没有出错而海明码检测出错的时候，就说明出现了两位错啦。（PS：由于添加了偶校验，所以当偶校验位出错时，海明检错无法检测到，所以对于无错误的判断需要当两个检测都没有出现错误才算真正的无错误）
## 海明解码实验图如下
![](https://raw.githubusercontent.com/hegaoxiang/ComputerCompositionExperiment/master/3.3%E6%B5%B7%E6%98%8E%E7%BC%96%E7%A0%81%E8%AE%BE%E8%AE%A1%E5%AE%9E%E9%AA%8C/Resource/finnal.png "finnal")