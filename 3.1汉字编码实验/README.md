# 汉字编码实验
![](https://raw.githubusercontent.com/hegaoxiang/ComputerCompositionExperiment/master/3.1%E6%B1%89%E5%AD%97%E7%BC%96%E7%A0%81%E5%AE%9E%E9%AA%8C/Resource/L5BML59V.png "")
![](https://raw.githubusercontent.com/hegaoxiang/ComputerCompositionExperiment/master/3.1%E6%B1%89%E5%AD%97%E7%BC%96%E7%A0%81%E5%AE%9E%E9%AA%8C/Resource/LFK31L.png "") 
## 字符转GB2312码

以C++为例
```
string str = "长沙软件1702湘abc"; 
```
当我们运行程序时，计算机储存字符如下：![图片说明](https://raw.githubusercontent.com/hegaoxiang/ComputerCompositionExperiment/master/3.1%E6%B1%89%E5%AD%97%E7%BC%96%E7%A0%81%E5%AE%9E%E9%AA%8C/Resource/SLFU.png "") 
对应了课件上面关于机内码存储的说明，其中汉字采用了GB2312标准。

通过
```
printf("%X%X ", (unsigned char)str[i],unsigned char)str[i + 1]);
```
我们就可以获得对应汉字的GB2312码，但是在上面我们可以看到计算机存储数字和字母是通过ASCII标准储存。导致我们直接用上面的方法处理字符串时可能会出现越界异常。并且由于后续实验原因我们也需要得到数字的GB2312码，所以我们需要在打印之前做一些小小的处理，让计算机通过GB2312码来储存这些我们想要的数字字母。

一个办法就是在`str`储存每个字母或者数字的位置讲其ASCII码转成GB2312码。
```

void DealStrWithoutANSI(string& str)
{
	for (size_t i = 0;i < str.size();i++)
	{
		if ('0' <= str[i] && str[i] <= '9')//是数字
		{
			// 数字0的区位码：0316 = 0310h
			// 数字0的GB2312机内码：0310h + a0a0h = a3b0h
			const char a = 0xa3;
			string temp;
			temp += a;
			str.insert(i, temp);// insert会插入到i之前

			i++;

			const char b = 0xb0 + (str[i] - '0');
			str[i] = b;
		}
		else if ('a' <= str[i] && str[i] <= 'z')
		{
			// 数字a的区位码：0365 = 0341h
			// 数字a的GB2312机内码：0341h + a0a0h = a3e1h
			const char a = 0xa3;
			string temp;
			temp += a;
			str.insert(i, temp);

			i++;

			const char b = 0xe1 + (str[i] - 'a');
			str[i] = b;
		}
		else if ('A' <= str[i] && str[i] <= 'Z')
		{
			// 数字A的区位码：0333 = 0321h
			// 数字A的GB2312机内码：0321h + a0a0h = a3c1h
			const char a = 0xa3;
			string temp;
			temp += a;
			str.insert(i, temp);

			i++;

			const char b = 0xc1 + (str[i] - 'A');
			str[i] = b;
		}
	}
}
```
以上，我们便得到了一段字符的GB2312码。
## GB2312码转区位码
由`GB2312码 = 区位码 + 0xA0A0`我们得到`GB2312码 + 0x5F60 = 区位码`
所以我们在logsim中只需要添加个常量，数值为0x5f60，并将加法器的数据位宽改为16。然后和简单连接，本次实验就完成了。
![](https://raw.githubusercontent.com/hegaoxiang/ComputerCompositionExperiment/master/3.1%E6%B1%89%E5%AD%97%E7%BC%96%E7%A0%81%E5%AE%9E%E9%AA%8C/Resource/A52GI179.png "") 

## 运行截图
![](https://raw.githubusercontent.com/hegaoxiang/ComputerCompositionExperiment/master/3.1%E6%B1%89%E5%AD%97%E7%BC%96%E7%A0%81%E5%AE%9E%E9%AA%8C/Resource/%E6%B1%89%E5%AD%97%E7%BC%96%E7%A0%81%E5%AE%9E%E9%AA%8C.gif "") 