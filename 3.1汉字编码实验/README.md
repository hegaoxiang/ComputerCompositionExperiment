# ���ֱ���ʵ��
![](https://raw.githubusercontent.com/hegaoxiang/ComputerCompositionExperiment/master/3.1%E6%B1%89%E5%AD%97%E7%BC%96%E7%A0%81%E5%AE%9E%E9%AA%8C/Resource/L5BML59V.png "")
![](https://raw.githubusercontent.com/hegaoxiang/ComputerCompositionExperiment/master/3.1%E6%B1%89%E5%AD%97%E7%BC%96%E7%A0%81%E5%AE%9E%E9%AA%8C/Resource/LFK31L.png "") 
## �ַ�תGB2312��

��C++Ϊ��
```
string str = "��ɳ���1702��abc"; 
```
���������г���ʱ������������ַ����£�![ͼƬ˵��](https://raw.githubusercontent.com/hegaoxiang/ComputerCompositionExperiment/master/3.1%E6%B1%89%E5%AD%97%E7%BC%96%E7%A0%81%E5%AE%9E%E9%AA%8C/Resource/SLFU.png "") 
��Ӧ�˿μ�������ڻ�����洢��˵�������к��ֲ�����GB2312��׼��

ͨ��
```
printf("%X%X ", (unsigned char)str[i],unsigned char)str[i + 1]);
```
���ǾͿ��Ի�ö�Ӧ���ֵ�GB2312�룬�������������ǿ��Կ���������洢���ֺ���ĸ��ͨ��ASCII��׼���档��������ֱ��������ķ��������ַ���ʱ���ܻ����Խ���쳣���������ں���ʵ��ԭ������Ҳ��Ҫ�õ����ֵ�GB2312�룬����������Ҫ�ڴ�ӡ֮ǰ��һЩСС�Ĵ����ü����ͨ��GB2312����������Щ������Ҫ��������ĸ��

һ���취������`str`����ÿ����ĸ�������ֵ�λ�ý���ASCII��ת��GB2312�롣
```

void DealStrWithoutANSI(string& str)
{
	for (size_t i = 0;i < str.size();i++)
	{
		if ('0' <= str[i] && str[i] <= '9')//������
		{
			// ����0����λ�룺0316 = 0310h
			// ����0��GB2312�����룺0310h + a0a0h = a3b0h
			const char a = 0xa3;
			string temp;
			temp += a;
			str.insert(i, temp);// insert����뵽i֮ǰ

			i++;

			const char b = 0xb0 + (str[i] - '0');
			str[i] = b;
		}
		else if ('a' <= str[i] && str[i] <= 'z')
		{
			// ����a����λ�룺0365 = 0341h
			// ����a��GB2312�����룺0341h + a0a0h = a3e1h
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
			// ����A����λ�룺0333 = 0321h
			// ����A��GB2312�����룺0321h + a0a0h = a3c1h
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
���ϣ����Ǳ�õ���һ���ַ���GB2312�롣
## GB2312��ת��λ��
��`GB2312�� = ��λ�� + 0xA0A0`���ǵõ�`GB2312�� + 0x5F60 = ��λ��`
����������logsim��ֻ��Ҫ��Ӹ���������ֵΪ0x5f60�������ӷ���������λ���Ϊ16��Ȼ��ͼ����ӣ�����ʵ�������ˡ�
![](https://raw.githubusercontent.com/hegaoxiang/ComputerCompositionExperiment/master/3.1%E6%B1%89%E5%AD%97%E7%BC%96%E7%A0%81%E5%AE%9E%E9%AA%8C/Resource/A52GI179.png "") 

## ���н�ͼ
![](https://raw.githubusercontent.com/hegaoxiang/ComputerCompositionExperiment/master/3.1%E6%B1%89%E5%AD%97%E7%BC%96%E7%A0%81%E5%AE%9E%E9%AA%8C/Resource/%E6%B1%89%E5%AD%97%E7%BC%96%E7%A0%81%E5%AE%9E%E9%AA%8C.gif "") 