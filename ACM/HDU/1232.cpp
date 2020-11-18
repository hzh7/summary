#include <stdio.h>
#include <string>

using namespace std;
int city[1005];

int findRoot(int x){
	if (city[x] == -1)
		return x;
	int tmp = findRoot(city[x]);
	city[x] = tmp;
	return tmp;
}

int main(){
	int n, m;
	while (scanf("%d", &n) != EOF && n != 0)
	{
		scanf("%d", &m);
		for (int i = 1; i <= n; i++)
		{
			city[i] = -1;
		}
		for (int i = 0; i < m; i++)
		{
			int a, b, c, d;
			scanf("%d %d", &a, &b);
			c = findRoot(a);
			d = findRoot(b);
			if (c != d){
				city[c] = d;
			}
		}
		int sum = -1;
		for (int i = 1; i <= n; i++)
		{
			if (city[i] == -1)
				sum++;
		}
		printf("%d\n", sum);
	}

	return 0;
}