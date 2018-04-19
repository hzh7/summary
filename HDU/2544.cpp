#include <stdio.h>
using namespace std;
int arr[105][105];
int main(){
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF){
		if (n == 0 && m == 0){
			return 0;
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++)
			{
				arr[i][j] = -1;
			}
			arr[i][i] = 0;
		}
		for (int i = 0; i < m; i++)
		{
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			arr[a][b] = c;
			arr[b][a] = c;
		}
		for (int k = 1; k <= n; k++){
			for (int i = 1; i <= n; i++){
				for (int j = 1; j <= n; j++)
				{
					if (arr[i][k] == -1 || arr[k][j] == -1)
						continue;
					if (arr[i][j] == -1 || (arr[i][j] > arr[i][k] + arr[k][j]))
						arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
		printf("%d\n", arr[1][n]);
	}
	return 0;
}