#include <stdio.h>
#include <algorithm>
using namespace std;
bool cmp(int a, int b){
	return a > b;
}
int main3003(){
	int t, n;
	int cas = 0;
	int arr[1005];
	int arr2[1005];
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr2[i]);
		}
		sort(arr, arr + n);
		sort(arr2, arr2 + n, cmp);
		int tmp;
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += arr[i] * arr2[i];
		}
		printf("case #%d:\n%d\n", cas++, sum);
	}
	return 0;
}