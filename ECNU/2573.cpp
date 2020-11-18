#include <stdio.h>
#include <algorithm>
struct Edge
{
	int a, b, cost;
	bool operator < (const Edge &A)const{
		return cost < A.cost;
	}
}edge[15005];
int Tree[1005];
int find(int n){
	if (Tree[n] == -1){
		return n;
	}
	else
	{
		int tmp = find(Tree[n]);
		Tree[n] = tmp;
		return tmp;
	}
}
int main2573(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		edge[i].a = a;
		edge[i].b = b;
		edge[i].cost = c;
	}
	for (int i = 0; i <= n; i++)
	{
		Tree[i] = -1;
	}
	std::sort(edge, edge + m);
	int sum = 0;
	for (int i = 0; i < m; i++)
	{
		int a = find(edge[i].a);
		int b = find(edge[i].b);
		if (a != b){
			sum += edge[i].cost;
			Tree[a] = b;
		}
	}
	printf("%d", sum);

	return 0;
}
/*
3 3
1 2 1
1 3 2
2 3 4

4 6
1 2 1
1 3 4
1 4 1
2 3 3
2 4 2
3 4 5
*/