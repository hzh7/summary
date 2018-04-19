#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
	int n, p;
	scanf("%d%d", &n, &p);
	long long arr[100005];
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &arr[i]);
	}
	sort(arr, arr + n);
	long long sum = 0;
	long long max;
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		max = (long long)arr[i] * p;
		while (arr[j] <= max && j < n){
			j++;
		}
		if (j - i > sum)
			sum = j - i;
	}
	printf("%lld", sum);
	return 0;
}