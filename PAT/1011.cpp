#include<stdio.h>

using namespace std;

int main(){
	int n;
	long long a, b, c;
	scanf("%d", &n);
	int cas = 0;
	while (n--)
	{
		scanf("%lld %lld %lld", &a, &b, &c);
		printf("Case #%d: ", ++cas);
		if (a + b > c)
			printf("true\n");
		else
		{
			printf("false\n");
		}
	}

	return 0;
}