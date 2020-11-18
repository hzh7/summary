#include <stdio.h>
#include <cstring>

int main(){
	char str[10000];
	scanf("%s", str);
	int len = strlen(str);
	int posE;
	int zhishu = 0; int c = 1;
	for (int i = 3; i < len; i++)
	{
		if (str[i] == 'E'){
			posE = i;
			break;
		}
	}
	for (int i = len-1; i > posE+1; i--)
	{
		zhishu = (str[i] - '0')*c + zhishu;
		c *= 10;
	}
	//printf("%d", zhishu);
	if (str[0] == '-')
		printf("-");
	if (str[posE + 1] == '-'){
		printf("0.");
		for (int i = 0; i < zhishu - 1; i++)
		{
			printf("0");
		}
		for (int i = 1; i < posE; i++)
		{
			if (i == 2)
				continue;
			printf("%c", str[i]);
		}
	}
	else
	{
		if (str[1] != '0')
			printf("%c", str[1]);
		if (posE - 3 < zhishu){
			for (int i = 3; i < posE; i++)
			{
				printf("%c", str[i]);
			}

			for (int i = 0; i <= zhishu - posE + 2; i++)
			{
				printf("0");
			}
		}
		else{
			for (int i = 3; i < zhishu + 3; i++)
			{
				printf("%c",str[i]);
			}
			if (zhishu+3 < posE)
				printf(".");

			for (int i = zhishu+3; i < posE; i++)
			{
				printf("%c", str[i]);
			}
		}
		
	}

	return 0;
}