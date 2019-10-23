#include<string>
#include<iostream>
using namespace std;
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

int main()
{
	string str = "长沙软件1702湘abcDeDDdd";

	DealStrWithoutANSI(str);
	const char* s = str.c_str();
	for (size_t i = 0; i < str.size(); i+=2)
	{
		//cout << hex << s[i] <<" "<< (unsigned char)s[i + 1] << " "<<endl;
		printf("%X%X ", (unsigned char)s[i], (unsigned char)s[i + 1]);
	}
	
	return 0;
}
// 长沙理工大学软件1702何高湘201716080215