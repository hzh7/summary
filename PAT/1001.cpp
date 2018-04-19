#include<stdio.h>

int main(){
	int n;
	int cnt = 0;
	scanf("%d", &n);
	while (n != 1)
	{
		if (n % 2 == 0)
			n /= 2;
		else
		{
			n = (n * 3 + 1) / 2;
		}
		cnt++;
	}
	printf("%d", cnt);
	//scanf("%d", &n);

	return 0;
} 