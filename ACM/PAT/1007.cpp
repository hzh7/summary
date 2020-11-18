#include<stdio.h>

using namespace std;

int main(){
	int n;
	int cnt = 0;
	int arr[100000] = {0};
	scanf("%d", &n);
	for (int i = 2; i <= n; i++)
	{
		if (arr[i] == 0){
			for (int j = i+i; j <= n; j+=i)
			{
				arr[j] = 1;
			}
		}
	}
	for (int i = 2; i < n - 1; i++)
	{
		if (arr[i] == 0 && arr[i + 2] == 0){
			cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}