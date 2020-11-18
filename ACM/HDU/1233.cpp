#include <stdio.h>
#include <algorithm>

using namespace std;

struct Edge
{
	int a, b;//一条边的两点
	int cost;
	bool operator < (const Edge &A)const{
		return cost < A.cost;
	}
} edge[5005];
int Tree[5005];
int findRoot(int x){
	if (Tree[x] == -1){
		return x;
	}
	int tmp = findRoot(Tree[x]);
	Tree[x] = tmp;
	return tmp;	
}
int main(){
	int n;
	int sum;
	while (scanf("%d", &n) != EOF && n != 0)
	{
		for (int i = 1; i <= n*(n - 1) / 2; i++)
		{
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			edge[i].a = a;
			edge[i].b = b;
			edge[i].cost = c;
			Tree[i] = -1;
		}
		for (int i = 1; i <= n; i++)
		{
			Tree[i] = -1;
		}
		sort(edge + 1, edge + n*(n - 1) / 2 + 1);
		sum = 0;
		//Tree[edge[1].a] = edge[1].b;
		for (int i = 1; i <= n*(n - 1) / 2; i++)
		{
			int seta = findRoot(edge[i].a);
			int setb = findRoot(edge[i].b);
			if (seta != setb){
				sum += edge[i].cost;
				Tree[seta] = setb;
			}
		}
		printf("%d\n", sum);
	}

	return 0;
}