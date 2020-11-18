#include <stdio.h>
int tree[1000000] = { 0 };
int findroot(int n){
	if (tree[n] == 0){
		return n;
	}
	int tmp = findroot(tree[n]);
	tree[n] = tmp;
	return tmp;
}
int main1816(){
	int n, m;
	int a, b;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &a, &b);
		a = findroot(a);
		b = findroot(b);
		if (a != b)
			tree[a] = b;
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (tree[i] == 0)
			cnt++;
	}
	if (cnt > 1){
		printf("no");
	}
	else
	{
		printf("yes");
	}
	return 0;
}