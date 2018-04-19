/*
难难难 没过
*/

#include <stdio.h>
#include <queue>
#include <vector>

#define INF 0x3fffffff
using namespace std;
struct Edge
{
	int next;
	int distance;
	int cost;
};

vector<Edge> edge[10005];
int V[505];//点集
vector<int> S;//收入的点
int dist[505];//距离
int Dcos[505];//花费

int main(){
	int n, m, s, d;
	scanf("%d %d %d %d", &n, &m, &s, &d);
	S.push_back(s);
	V[s] = 1;
	dist[s] = 0;
	for (int i = 0; i < m; i++)
	{
		int start, end, distan, costt;
		scanf("%d %d %d %d", &start, &end, &distan, &costt);
		Edge tmp;
		tmp.cost = costt; 
		tmp.distance = distan;
		tmp.next = end;
		edge[start].push_back(tmp);
		tmp.next = start;
		edge[end].push_back(tmp);
	}
	for (int i = 0; i < n; i++)
	{
		dist[i] = INF;
		Dcos[i] = INF;
	}
	int newP = s;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < edge[newP].size(); j++)
		{
			int t = edge[newP][j].next;
			int c = edge[newP][j].distance;
			int co = edge[newP][j].cost;
			if (V[t] == 1)
				continue;
			if (dist[t] == INF || dist[t] > dist[newP] + c ||
				dist[t] == dist[newP] + c && Dcos[t] >Dcos[newP] + co){
				dist[t] = dist[t] + c;
				Dcos[t] = Dcos[newP] + co;
			}
		}
		int min = INF;
		for (int j = 0; j < n; j++)
		{
			if (V[j] == 1)
				continue;
			if (dist[j] == INF)
				continue;
			if (dist[j] < min){
				min = dist[j];
				newP = j;
			}
		}
		V[newP] = 1;
	}
	printf("\n%d %d", dist[d], Dcos[d]);

	/*while (S.back() != d){
		for (int i = 0; i < n; i++)
		{
			int tmps = S.back();
			int mindis = INF;
			int minCost = INF;
			int tmpV = tmps;
			for (int j = 0; j < edge[tmps].size(); j++)
			{
				if (V[edge[tmps][j].next] == 1){
					continue;
				}
				if (mindis > edge[tmps][j].distance){
					mindis = edge[tmps][j].distance;
					minCost = edge[tmps][j].cost;
					tmpV = edge[tmps][j].next;
				}
				if (mindis == edge[tmps][j].distance){
					if (minCost > edge[tmps][j].cost){
						tmpV = edge[tmps][j].next;
						mindis = edge[tmps][j].distance;
					}
				}
			}
			dist[i] = min(dist[i], mindis);
			Dcos[i] = min(Dcos[i], minCost);
			V[tmpV] = 1;
			S.push_back(tmpV);
		}
	}*/
	for (int j = 0; j < S.size(); j++){
		printf("%d ", S[j]);
	}

	return 0;
}