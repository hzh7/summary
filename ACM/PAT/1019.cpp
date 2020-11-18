#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[4];
int small(){
	int c = 1;
	int res = 0;
	for (int i = 3; i >= 0; i--)
	{
		res = res + arr[i] * c;
		c *= 10;
	}
	return res;
}
int big(){
	int c = 1;
	int res = 0;
	for (int i = 0; i < 4; i++)
	{
		res = res + arr[i] * c;
		c *= 10;
	}
	return res;
}
int main(){
	int n;
	int ab = -1;
	int a, b, c;
	scanf("%d", &n);
	if (n == 6174){
		printf("7641 - 1467 = 6174\n");
		return 0;
	}
	while (ab != n){
		ab = n;
		c = 1000;
		for (int i = 0; i < 4; i++)
		{
			arr[i] = n / c;
			n %= c;
			c /= 10;
		}
		sort(arr, arr + 4);
		a = big();
		b = small();
		n = a - b;
		if (ab != n)
			printf("%04d - %04d = %04d\n", a, b, n);
	}
	return 0;
}