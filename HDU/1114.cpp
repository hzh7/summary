#include <cstdio>
#include <algorithm>

#define INF 0x3f3f3f3f

using namespace std;

struct Money{
	int P;
	int W;
	//float wp;
	/*bool operator < (const Money & A) const {
		return wp < A.wp;
	}*/
}money[505];
int dp[10005];

int main() {
	int T, N, E, F;
	scanf_s("%d", &T);
	while (T--){
		scanf_s("%d %d", &E, &F);
		int wight = F - E;
		for (int i = 1; i < 10005; i++)
		{
			dp[i] = INF;
		}
		dp[0] = 0;
		int sum = 0;
		scanf_s("%d", &N);
		for (int i = 0; i < N; ++i) {
			scanf_s("%d %d", &money[i].P, &money[i].W);
			//money[i].wp = (float)money[i].P / money[i].W;
		}
		//sort(money, money + N);
		for (int i = 0; i < N; i++){
			for (int j = money[i].W; j <= wight; j++){
				//if (dp[j - money[i].P] < INF)
					dp[j] = min(dp[j], dp[j - money[i].W] + money[i].P);
			}
		}


		/*
		用贪心做的，不对，这是完全背包问题
		int tmp;
		for (int i = 0; i < N; ++i) {
			if (wight<0)
			break;
			tmp = wight / money[i].W;
			sum += money[i].P*tmp;
			wight = wight%money[i].W;
		}*/
		if (dp[wight] < INF)
			printf("The minimum amount of money in the piggy-bank is %d.\n", dp[wight]);
		else
			printf("This is impossible.\n");
	}
	return 0;
}