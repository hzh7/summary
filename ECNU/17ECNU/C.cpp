#include <stdio.h>
#include <algorithm>
struct Paper
{
	int num;
	int hand;
	bool operator< (const Paper &A)const{
		return hand > A.hand;
	}
}paper[1005];

int mainC(){
	int t, n, k, tmp;
	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++){
			scanf("%d", &tmp);
			paper[i - 1].num = i;
			paper[i - 1].hand = tmp;
		}
		std::sort(paper, paper + n);
		int ans[1005];
		int pos = 0;
		for (int i = 0; i < k; i++)
		{
			ans[i] = paper[i].num;
		}
		std::sort(ans, ans + k);

		printf("%d", ans[0]);
		for (int i = 1; i < k; i++)
		{
			printf(" %d", ans[i]);
		}
		printf("\n");
	}
	return 0;
}