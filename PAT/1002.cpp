// 1002.cpp : 定义控制台应用程序的入口点。
//

#include <stdio.h>
#include <cstring>
#include <string>
using namespace std;

int main()
{
	char str[105];
	scanf("%s", str);
	string s[10] = { "ling", "yi", "er", "san", "si",
		"wu", "liu", "qi", "ba", "jiu" };
	int ans = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		ans += str[i] - '0';
	}
	int len = 0;
	int tmp = ans;
	int carry = 1;
	while (tmp)
	{
		tmp /= 10;
		len++;
		carry *= 10;
	}
	bool isf = 1;
	for (int i = len-1; i >= 0; i--)
	{		
		ans %= carry;
		carry /= 10;
		if (isf){
			printf("%s", s[ans / carry].c_str());
			isf = 0;
		}
		else
		{
			printf(" %s", s[ans / carry].c_str());
		}
	}
	//printf("\n%d", ans);
	system("pause");
	return 0;
}

