#include <stdio.h>

using namespace std;
struct Node
{
	int data, next;
}node[100001];
int n, k, start = -2;
int s;
int reversal(int f){
	int p0 = f;
	int p1 = node[p0].next;
	int p2 = node[p1].next;
	for (int i = 1; i < k; i++)
	{
		node[p1].next = p0;
		p0 = p1;
		p1 = p2;
		p2 = node[p2].next;
	}
	node[f].next = p1;
	if (start == -2){
		start = p0;
	}
	else
	{
		node[s].next = p0;
	}
	s = f;
	return p1;
}
int main(){
	int first;
	scanf("%d %d %d", &first, &n, &k);
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		node[a].data = b;
		node[a].next = c;
	}
	if (first == -1) 
	{
		printf("-1\n");
		return 0;
	}
	for (int i = 0; i < n/k; i++)
	{
		first = reversal(first);
	}
	int p = start;
	for (int i = 0; i < n-1; i++)
	{
		printf("%05d %d %05d\n", p, node[p].data, node[p].next);
		p = node[p].next;
	}
	printf("%05d %d %d\n", p, node[p].data, node[p].next);
	return 0;
}

/*
1 4 2
1 1 2
2 2 3
3 3 4
4 4 -1

00100 6 3
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
*/