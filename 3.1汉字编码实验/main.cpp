#include<string>
#include<iostream>
using namespace std;
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

int main()
{
	string str = "��ɳ���1702��abcDeDDdd";

	DealStrWithoutANSI(str);
	const char* s = str.c_str();
	for (size_t i = 0; i < str.size(); i+=2)
	{
		//cout << hex << s[i] <<" "<< (unsigned char)s[i + 1] << " "<<endl;
		printf("%X%X ", (unsigned char)s[i], (unsigned char)s[i + 1]);
	}
	
	return 0;
}
// ��ɳ����ѧ���1702�θ���201716080215