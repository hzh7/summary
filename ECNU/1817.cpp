#include <stdio.h>
#define INF -1
int ans[600][600];
/*
看清题目啊 有向图~

*/
int main1817(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++){
			ans[i][j] = INF;
		}
		ans[i][i] = 0;
	}
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		ans[a][b] = c;
		//ans[b][a] = c;
	}
	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (ans[i][k] == INF || ans[k][j] == INF)
					continue;
				if (ans[i][j] == INF || ans[i][k] + ans[k][j] < ans[i][j]){
					ans[i][j] = ans[i][k] + ans[k][j];
				}
			}
		}
	}
	if (ans[1][n] == INF){
		printf("-1");
	}
	else
	{
		printf("%d", ans[1][n]);
	}
	return 0;
}