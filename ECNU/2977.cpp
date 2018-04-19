#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
struct Stduent
{
	char num[13];
	int score;
	bool operator< (const Stduent &A)const{
		if (score == A.score){
			return strcmp(num, A.num) < 0;
		}
		return score > A.score;
	}
};

int main2977(){
	int t, n, m, g;
	int cas = 0;
	int am[11];
	Stduent studens[500];
	scanf("%d", &t);
	while (t--){
		scanf("%d%d%d", &n, &m, &g);
		for (int i = 0; i < m; i++)
		{
			scanf("%d", &am[i]);
		}
		int pos = 0;
		for (int i = 0; i < n; i++){
			char snum[13];
			scanf("%s", snum);
			int s; int sum = 0; int tmp;
			scanf("%d", &s);
			for (int j = 0; j < s; j++)
			{
				scanf("%d", &tmp);
				sum += am[tmp - 1];
			}
			if (sum >= g){
				strcpy(studens[pos].num, snum);
				studens[pos++].score = sum;
			}
		}
		sort(studens, studens + pos);
		printf("case #%d:\n%d\n", cas++, pos);
		for (int i = 0; i < pos; i++)
		{
			printf("%s %d\n", studens[i].num, studens[i].score);
		}
	}
	return 0;
}