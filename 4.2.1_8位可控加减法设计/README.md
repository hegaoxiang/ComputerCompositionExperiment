# 8位可控加减法器设计
## 加法和减法
对于二进制补码预算加法，很容易，只需要将对应的位置连接上，后一位的进位需要加到前一位上，就可以了

对于二进制补码运算减法
```
X[补] - Y[补] = X[补] + (-Y)[补]
```
那么问题来了，`-Y`怎么求呢。
根据下面的补码对应图，推测出你的想法
![](https://raw.githubusercontent.com/hegaoxiang/ComputerCompositionExperiment/master/4.2.1_8%E4%BD%8D%E5%8F%AF%E6%8E%A7%E5%8A%A0%E5%87%8F%E6%B3%95%E8%AE%BE%E8%AE%A1/Resource/PrincipleOfBinaryComplement.jpg "二进制补码原理")
我们不难发现，无论对于正数还是负数，由于补码的神奇性，我们只需要**各个位求反，再加1**，便能得到我们想要的！！！
简易电路图如下![](https://raw.githubusercontent.com/hegaoxiang/ComputerCompositionExperiment/master/4.2.1_8%E4%BD%8D%E5%8F%AF%E6%8E%A7%E5%8A%A0%E5%87%8F%E6%B3%95%E8%AE%BE%E8%AE%A1/Resource/CircuitDiagram01.png )
## 溢出检测
溢出是指运算结果超出了某种数据类型的表示范围。
由此，只可能发生在同号运算的过程中。
方法1：对操作数和运算结果的符号为进行检测，当结果的符号位和操作数的符号位不同时就表明发生了溢出。
方法2：对最高数据位进位和符号位进位进行检测，当两者不同时则发生了溢出
方法3：变形补码，符号位是两位，这个可以自己去网上参考下，不再多解释。
本题中使用方法2，较为简单。
## 完整电路图
![](https://raw.githubusercontent.com/hegaoxiang/ComputerCompositionExperiment/master/4.2.1_8%E4%BD%8D%E5%8F%AF%E6%8E%A7%E5%8A%A0%E5%87%8F%E6%B3%95%E8%AE%BE%E8%AE%A1/Resource/CircuitDiagram.png)
