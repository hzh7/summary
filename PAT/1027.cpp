#include <stdio.h>
#include <cmath>

using namespace std;
int main(){
	int N;
	char c;
	scanf("%d %c", &N, &c);
	int n = sqrt((N + 1) / 2);
	//printf("%d", n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++){
			printf(" ");
		}
		for (int j = 0; j < 2*n-1-2*i; j++){
			printf("%c", c);
		}
		printf("\n");
	}
	for (int i = n-2; i >= 0; i--)
	{
		for (int j = 0; j < i; j++){
			printf(" ");
		}
		for (int j = 0; j < 2 * n - 1 - 2*i; j++){
			printf("%c", c);
		}
		printf("\n");
	}
	printf("%d", N - 2 * n * n + 1);
	return 0;
}