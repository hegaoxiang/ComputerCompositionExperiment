# CRC�������ʵ��
## CRC����
CRCУ�����ԭ������![](https://raw.githubusercontent.com/hegaoxiang/ComputerCompositionExperiment/master/3.4CRC%E7%BC%96%E7%A0%81%E8%AE%BE%E8%AE%A1%E5%AE%9E%E9%AA%8C/Resource/Principle.png "CRCУ��ԭ��")
### ȷ��У����Ϣλ��
����ʵ��������ʹ��16λ�Ļ����룬����Ӧ�����5λCRCУ��λ��P1~P5����
### ѡ�����ɶ���ʽG(x)
���ڶ���ʽ��ѡ����Ҫ����һ����������������ѡ��CRC5�е�һ��100101��Ϊ����Ķ���ʽ��
### ���16�����ⳣ����CRC������Ȼ�����CRCУ���롣
����ԭ��![](https://raw.githubusercontent.com/hegaoxiang/ComputerCompositionExperiment/master/3.4CRC%E7%BC%96%E7%A0%81%E8%AE%BE%E8%AE%A1%E5%AE%9E%E9%AA%8C/Resource/PrincipleOfRemainderInModulo-2Division.png "ģ2��������ԭ��")
����
```
��Ϊ 1101 = 1000 ^ 0100 ^ 0001
���� 1101 % 1011 = (1000 % 1011) ^ (0100 & 1011) ^ (0001 % 1011)
```
��ˣ��ڱ����У����������
����C1  0000 0000 0000 000**1** 00000��CRC����R1��
����C2  0000 0000 0000 00**1**0 00000��CRC����R2��
����C3  0000 0000 0000 0**1**00 00000��CRC����R3��
����
����C16 **1**000 0000 0000 0000 00000��CRC����R16
���У�R(n)����R(n-1)����һλ��0�ٳ������ɶ���ʽ������
������ͼԭ���������Ǹ��ݴ������ÿһλֵ������һλֵΪ1ʱ������һλ��Ӧ��CRC����Rn����������㣬�������������ԭʼ���ݵ�CRC���������������������������CRCУ���롣
ʵ�ֵ�·ͼ���£����и������Ǹ������ɶ���ʽ100101����ĸ���CRC����
![](https://raw.githubusercontent.com/hegaoxiang/ComputerCompositionExperiment/master/3.4CRC%E7%BC%96%E7%A0%81%E8%AE%BE%E8%AE%A1%E5%AE%9E%E9%AA%8C/Resource/CRCCodingCircuitDiagram.png "CRC�����·ͼ")
## CRC����
����CRC������ԡ�����**ͬһ��**���ɶ���ʽ�����е�CRCУ������CRC�����ͳ���λ��һһ��Ӧ��ϵ����16λԭʼ����Ϊ����������**һλ**������ʱ����16����ʱ����õ�CRC����һ����R16��
�������ǿ�����������������CRCУ�����CRC������Ȼ������������޸Ķ�Ӧλ�õ�ֵ
### ��CRCУ�����CRC����
����ֻ��Ҫ��ԭ��CRCԭʼ������CRC�����Ļ����ϣ��������ԭʼ���ݵ�CRC����������������CRCУ�������������·ͼ����
![](https://raw.githubusercontent.com/hegaoxiang/ComputerCompositionExperiment/master/3.4CRC%E7%BC%96%E7%A0%81%E8%AE%BE%E8%AE%A1%E5%AE%9E%E9%AA%8C/Resource/SolvingCRCRemainder.png "��CRCУ�����CRC����")
### �����������޸Ķ�Ӧλ�õ�ֵ
���ǿ������ñȽ������ж����CRC������R1��R16�Ƚϣ������ȣ���ȷ������һλ������������������Ҫ�Խ�������������ֵ�������޸ĺ��ֵ����·ͼ����
![](https://raw.githubusercontent.com/hegaoxiang/ComputerCompositionExperiment/master/3.4CRC%E7%BC%96%E7%A0%81%E8%AE%BE%E8%AE%A1%E5%AE%9E%E9%AA%8C/Resource/CRCCodeCorrection01.png "���������޸ĵ�·")
![](https://raw.githubusercontent.com/hegaoxiang/ComputerCompositionExperiment/master/3.4CRC%E7%BC%96%E7%A0%81%E8%AE%BE%E8%AE%A1%E5%AE%9E%E9%AA%8C/Resource/CRCCodeCorrection02.png "���������޸ĵ�·")

## ���н�ͼ
![](https://raw.githubusercontent.com/hegaoxiang/ComputerCompositionExperiment/master/3.4CRC%E7%BC%96%E7%A0%81%E8%AE%BE%E8%AE%A1%E5%AE%9E%E9%AA%8C/Resource/CRC%E7%BC%96%E7%A0%81%E5%AE%9E%E9%AA%8C.gif )
