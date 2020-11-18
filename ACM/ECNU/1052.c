#include <stdio.h>

void dp1(){
    /*
     * runtime error
     * */
    int t,n,M;
    scanf("%d", &t);
    while (t--){
        int w[21] = {0};
        int p[21] = {0};
        int dp[15][10005] = {0};
        scanf("%d", &n);
        scanf("%d", &M);
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &w[i], &p[i]);
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= M; ++j) {
                if (j >= w[i-1])
                    dp[i][j] = Mymax(dp[i-1][j],dp[i-1][j-w[i-1]]+p[i-1]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        int r = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= M; ++j) {
                //printf("%d ", dp[i][j]);
                if (dp[i][j] > r)
                    r = dp[i][j];
            }
            //printf("\n");
        }
        printf("%d", r);
    }
}

int Mymax(int a, int b){
    return a>b?a:b;
}
int main() {
    int t,n,M;
    scanf("%d", &t);
    while (t--){
        int w[21] = {0};
        int p[21] = {0};
        int dp[100005] = {0};
        scanf("%d", &n);
        scanf("%d", &M);
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &w[i], &p[i]);
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = M; j >= w[i-1]; --j) {
                dp[j] = Mymax(dp[j],dp[j-w[i-1]]+p[i-1]);
            }
            /*for (int k = 1; k <= M; ++k) {
                printf("%d ", dp[k]);
            }
            printf("\n");*/
        }
        printf("%d\n", dp[M]);

    }
    return 0;
}