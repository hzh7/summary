#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;
int main(){
	int n, m, cnt;
	while (scanf("%d%d", &n, &m) != EOF){
		int deg[105] = { 0 };
		vector<int> edge[105];
		queue<int> que;
		cnt = 0;
		if (n == 0 && m == 0)
			return 0;
		//memset(deg, 0, sizeof(deg));
		/*for (int i = 0; i < n; i++)
		{
			deg[i] = 0;
		}*/
		for (int i = 0; i < m; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			edge[a].push_back(b);
			deg[b]++;
		}
		for (int i = 0; i < n; i++)
		{
			if (deg[i] == 0){
				que.push(i);
			}
		}
		while (!que.empty()){
			int tmp = que.front();
			que.pop();
			cnt++;
			for (int i = 0; i < edge[tmp].size(); i++)
			{
				if (--deg[edge[tmp][i]] == 0)
					que.push(edge[tmp][i]);
			}
		}
		/*bool flag = true;
		for (int i = 0; i < n; i++)
		{
			if (deg[i] != 0){
				flag = false;
				break;
			}
		}*/
		if (cnt == n)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}