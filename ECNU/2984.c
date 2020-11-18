#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    int k, n;
    int cas = 0;
    int youjie;
    while (t--){
        scanf("%d %d", &n, &k);
        int sum;
        youjie = 0;
        int flag = 0;
        printf("case #%d:\n",cas);
        for (int m = 0; m <= n; ++m) {
            flag = 0;
            for (int w = n; w >= 0; --w) {
                if (flag == 1) {
                    break;
                }
                for (int c = n - m - w; c <= n; ++c) {
                    sum = 3*m + 2*w + c;
                    if (sum == k){
                        youjie = 1;
                        printf("%d %d %d\n", m, w, c);
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if(!youjie)
            printf("-1\n");
        cas++;
    }
    return 0;
}