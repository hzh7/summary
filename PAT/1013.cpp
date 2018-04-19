#include<stdio.h>
using namespace std;

bool isP(int n){
	for (int i = 2; i*i <= n; i++)
	{
		if (n % i == 0){
			return false;
		}
	}
	return true;
}

int main(){
	int n, m;
	int cnt = 0;
	int row = 0;
	scanf("%d %d", &n, &m);
	for (int i = 2; cnt < m; i++)
	{
		if (isP(i)){
			if (++cnt >= n){
				if (++row == 1)
					printf("%d", i);
				else if (row == 10){
					printf(" %d\n", i);
					row = 0;
				}
				else
				{
					printf(" %d", i);
				}
			}
		}
	}
	return 0;
}