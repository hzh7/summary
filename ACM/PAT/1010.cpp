#include<stdio.h>

using namespace std;

int main(){
	int a, b, pos = 0;
	int flag = 1;
	while (scanf("%d %d", &a, &b) != EOF)
	{
		if (b == 0){
			if (flag)
				printf("0 0");
			return 0;
		}
		
		if (flag)
			printf("%d", a * b);
		else
		{
			printf(" %d", a * b);
		}
		printf(" %d", b - 1);
		flag = 0;
	}
	return 0;
}