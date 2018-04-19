#include <stdio.h>

using namespace std;
int ans[201][201];
int mymin(int a, int b){
	return a < b ? a : b;
}
int main(){
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				ans[i][j] = -1;
			}
			ans[i][i] = 0;
		}
		for (int i = 0; i < m; i++){
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			if (ans[a][b] == -1)
				ans[a][b] = c;
			else
				ans[a][b] = mymin(c, ans[a][b]);
			if (ans[b][a] == -1)
				ans[b][a] = c;
			else
				ans[b][a] = mymin(c, ans[b][a]);
		}
		for (int k = 0; k < n; k++){
			for (int i = 0; i < n; i++){
				for (int j = 0; j < n; j++){
					if (ans[i][k] == -1 || ans[k][j] == -1)
						continue;
					if (ans[i][j] == -1 || (ans[i][j] > ans[i][k] + ans[k][j])){
						ans[i][j] = ans[i][k] + ans[k][j];
					}
				}
			}
		}
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", ans[a][b]);
	}
	return 0;
}