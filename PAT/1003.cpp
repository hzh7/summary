#include <stdio.h>
#include <string>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	char str[105];
	string s;
	while (n--)
	{
		scanf("%s", str);
		s = str;
		int len = s.size();
		if (s == "PAT"){
			printf("YES\n");
			continue;
		}
		if (len < 3){
			printf("NO\n");
			continue;
		}
		bool flag = false;
		for (int i = 0; i <= len - 3; i++){
			if (s[i] != 'P' && s[i] != 'A' && s[i] != 'T'){
				flag = false;
				break;
			}
			if (s[i] == 'P' && s[i + 1] == 'A' && s[i + 2] == 'T'){
				//printf("YES\n");
				flag = true;
				//break;
			}
			if (s[i] == 'P' && s[i + 1] == 'A'&& s[i + 2] == 'A' && s[i + 3] == 'T'){
				//printf("YES\n");
				flag = true;
				//break;
			}
			else if (s[i] != 'A')
			{
				//printf("NO\n");
				break;
			}
		}
		for (int i = len - 2; i < len; i++){
			if (s[i] != 'P' && s[i] != 'A' && s[i] != 'T'){
				flag = false;
				break;
			}
		}
		if (flag){
			printf("YES\n");
		}
		else
		{
			printf("NO\n");

		}
	}
	return 0;
}