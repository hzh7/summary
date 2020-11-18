#include <stdio.h>
#include <string.h>
using namespace std;

int k, m, n;
int arr[505][505];
int used[505];
int nxt[505];
bool find(int x){
	for (int i = 1; i <= n; i++)
	{
		if (arr[x][i] == 1 && used[i] == 0){
			used[i] = 1;
			if (nxt[i] == 0 || find(nxt[i])){
				nxt[i] = x;
				return true;
			}
		}
	}
	return false;
}
int main(){
	while (scanf("%d", &k)!=EOF)
	{
		if (k == 0)
			break;
		scanf("%d %d", &m, &n);
		memset(arr, 0, sizeof(arr));
		memset(nxt, 0, sizeof(nxt));
		while (k--)
		{
			int i, j;
			scanf("%d %d", &i, &j);
			arr[i][j] = 1;
		}
		int sum = 0;
		for (int i = 1; i <= m; i++)
		{
			memset(used, 0, sizeof(used));
			if (find(i))
				sum++;
		}
		printf("%d\n", sum);
	}
	return 0;
}