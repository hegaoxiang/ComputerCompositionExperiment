#include<string>
#include<iostream>
using namespace std;
void DealStrWithoutANSI(string& str)
{
	for (size_t i = 0;i < str.size();i++)
	{
		if ('0' <= str[i] && str[i] <= '9')//������
		{
			const char a = 0xa3;
			const char b = 0xb0 + (str[i] - '0');
			string temp;
			temp += a;
			str[i] = b;
			str.insert(i,temp);// insert����뵽i֮ǰ
		}
	}
}

int main()
{
	string str;
	cin >> str;
	
	DealStrWithoutANSI(str);
	const char* s = str.c_str();
	for (size_t i = 0; i < str.size(); i+=2)
	{
		printf("%X%X ", (unsigned char)s[i], (unsigned char)s[i + 1]);
	}
	
	return 0;
}
// ��ɳ����ѧ���1702�θ���201716080215