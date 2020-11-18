#include <stdio.h>
#define INF 0x3f3f3f3f
int ans[105][105];
int max[105][105];
/*
看清题目啊 有向图~

*/
int main1818(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++){
			ans[i][j] = INF;
			max[i][j] = 0;
		}
		ans[i][i] = 0;
	}
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		ans[a][b] = c;
		max[a][b]++;
	}
	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (ans[i][k] + ans[k][j] < ans[i][j]){
					ans[i][j] = ans[i][k] + ans[k][j];
					max[i][j] = max[i][k] * max[k][j];
				}
				else if (ans[i][k] + ans[k][j] == ans[i][j]){
					max[i][j] += max[i][k] * max[k][j];
				}
			}
		}
	}
	if (ans[1][n] == INF){
		printf("-1 0");
	}
	else
	{
		printf("%d %d", ans[1][n], max[1][n]);
	}
	return 0;
}