#include <stdio.h>
#include <cstring>
int main2537(){
	int t;
	int cnt1, cnt2, cnt3;
	scanf("%d", &t);
	getchar();
	char str[10001];
	while (t--){
		cnt1 = cnt2 = cnt3 = 0;
		gets(str);
		int len = strlen(str);
		for (int i = 0; i < len; i++)
		{
			if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z'){
				cnt1++;
			}
			else if(str[i] >= '0' && str[i] <= '9')
			{
				cnt2++;
			}
			else
			{
				cnt3++;
			}
		}
		printf("character:%d\n", cnt1);
		printf("number:%d\n", cnt2);
		printf("others:%d\n", cnt3);
	}
	return 0;
}
/*
character:2
number:2
others:1
character:21
number:14
others:9

*/