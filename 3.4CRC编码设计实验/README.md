# CRC编码设计实验
## CRC编码
CRC校验基本原理如下![](https://raw.githubusercontent.com/hegaoxiang/ComputerCompositionExperiment/master/3.4CRC%E7%BC%96%E7%A0%81%E8%AE%BE%E8%AE%A1%E5%AE%9E%E9%AA%8C/Resource/Principle.png "CRC校验原理")
### 确定校验信息位数
对于实验中我们使用16位的机内码，我们应该添加5位CRC校验位（P1~P5）。
### 选择生成多项式G(x)
由于多项式的选择需要满足一定条件，所以我们选择CRC5中的一种100101作为本题的多项式。
### 求出16个特殊常量的CRC余数，然后求出CRC校验码。
根据原理![](https://raw.githubusercontent.com/hegaoxiang/ComputerCompositionExperiment/master/3.4CRC%E7%BC%96%E7%A0%81%E8%AE%BE%E8%AE%A1%E5%AE%9E%E9%AA%8C/Resource/PrincipleOfRemainderInModulo-2Division.png "模2除法余数原理")
举例
```
因为 1101 = 1000 ^ 0100 ^ 0001
所以 1101 % 1011 = (1000 % 1011) ^ (0100 & 1011) ^ (0001 % 1011)
```
因此，在本题中，我们先求出
常量C1  0000 0000 0000 000**1** 00000的CRC余数R1，
常量C2  0000 0000 0000 00**1**0 00000的CRC余数R2，
常量C3  0000 0000 0000 0**1**00 00000的CRC余数R3，
……
常量C16 **1**000 0000 0000 0000 00000的CRC余数R16
其中，R(n)等于R(n-1)左移一位补0再除以生成多项式的余数
根据上图原理，所以我们根据待编码的每一位值，当这一位值为1时，将这一位对应的CRC余数Rn参与异或运算，最后的异或结果就是原始数据的CRC余数。最后将数据组合起来，便就是CRC校验码。
实现电路图如下，其中各常量是根据生成多项式100101求出的各个CRC余数
![](https://raw.githubusercontent.com/hegaoxiang/ComputerCompositionExperiment/master/3.4CRC%E7%BC%96%E7%A0%81%E8%AE%BE%E8%AE%A1%E5%AE%9E%E9%AA%8C/Resource/CRCCodingCircuitDiagram.png "CRC编码电路图")
## CRC解码
根据CRC码的特性。对于**同一个**生成多项式，所有的CRC校验码其CRC余数和出错位是一一对应关系，以16位原始数据为例，即当有**一位**错误发生时，第16出错时其求得的CRC余数一定是R16。
所有我们可以先求出传输过来的CRC校验码的CRC余数，然后根据余数来修改对应位置的值
### 求CRC校验码的CRC余数
我们只需要在原先CRC原始数据求CRC余数的基础上，再异或上原始数据的CRC余数，其结果，就是CRC校验码的余数。电路图如下
![](https://raw.githubusercontent.com/hegaoxiang/ComputerCompositionExperiment/master/3.4CRC%E7%BC%96%E7%A0%81%E8%AE%BE%E8%AE%A1%E5%AE%9E%E9%AA%8C/Resource/SolvingCRCRemainder.png "求CRC校验码的CRC余数")
### 根据余数来修改对应位置的值
我们可以利用比较器，判断求得CRC余数与R1到R16比较，如果相等，则确定是这一位发生错误，所以我们需要对结果进行异或。最后的值，便是修改后的值。电路图如下
![](https://raw.githubusercontent.com/hegaoxiang/ComputerCompositionExperiment/master/3.4CRC%E7%BC%96%E7%A0%81%E8%AE%BE%E8%AE%A1%E5%AE%9E%E9%AA%8C/Resource/CRCCodeCorrection01.png "根据余数修改电路")
![](https://raw.githubusercontent.com/hegaoxiang/ComputerCompositionExperiment/master/3.4CRC%E7%BC%96%E7%A0%81%E8%AE%BE%E8%AE%A1%E5%AE%9E%E9%AA%8C/Resource/CRCCodeCorrection02.png "根据余数修改电路")

## 运行截图
![](https://raw.githubusercontent.com/hegaoxiang/ComputerCompositionExperiment/master/3.4CRC%E7%BC%96%E7%A0%81%E8%AE%BE%E8%AE%A1%E5%AE%9E%E9%AA%8C/Resource/CRC%E7%BC%96%E7%A0%81%E5%AE%9E%E9%AA%8C.gif )
