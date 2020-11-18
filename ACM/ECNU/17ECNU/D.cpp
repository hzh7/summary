#include <stdio.h>

long long slove(int n){
	long long sum = 0;
	for (int i = 0; i <= n; i++)
	{
		long long a = 1, b = 1, c = 1;
		for (int j = 1; j <= i; j++)
		{
			a *= j;
		}
		for (int j = 1; j <= n-i; j++)
		{
			b *= j;
		}
		for (int j = 1; j <= n; j++)
		{
			c *= j;
			//printf("c %d\n", c);
		}
		sum += (c / (a*b));
	}
	return sum;
}
int mainD(){
	int t, n;
	long long c = 1, sum = 0;
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		sum = 0;
		int tmp; 
		for (int i = 0; i < n; i++){
			scanf("%d", &tmp);
			sum += tmp;
		}
		c = slove(n - 1);
		printf("%d\n", sum * c);
	}
	return 0;
}