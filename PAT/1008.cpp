#include <stdio.h>

using namespace std;

int main(){
	int n, m;
	int arr[105];
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	//printf("%d", arr[m]);
	m %= n;
	printf("%d", arr[(n - m) % n]);
	for (int i = 1; i < n; i++)
	{
		printf(" %d", arr[(i + n -m) % n]);
	}
	return 0;
}