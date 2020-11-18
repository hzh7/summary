#include<stdio.h>
#include<string>
#include<cstring>
#include<stack>

using namespace std;

int main(){
	char str[100];
	
	string s;
	stack<string> sta;
	gets(str);
	int len = strlen(str);
	int pos = 0;
	char ss[100] = { 0 };
	for (int i = 0; i < len; i++)
	{
		
		if (str[i] != ' '){
			ss[pos++] = str[i];
		}
		if (str[i] == ' ' || i == len - 1)
		{
			ss[pos] = 0;
			s = ss;
			sta.push(s);
			pos = 0;
		}
	}
	bool isf = true;
	while (!sta.empty())
	{
		s = sta.top();
		sta.pop();
		if (isf){
			printf("%s", s.c_str());
			isf = false;
		}
		else
		{
			printf(" %s", s.c_str());
		}

	}
	

	return 0;
}