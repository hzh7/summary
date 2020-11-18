#include <stdio.h>

int getMax(int a, int b){
    return b == 0 ? a : getMax(b, a % b);
}
int main() {
    //printf("Hello, World!\n");
    int x, n;
    scanf("%d %d", &x, &n);
    /*Time Limit Exceeded
     * for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if(j * x % i == 0){
                printf("%d\n", j);
                break;
            }
        }
    }*/
    for (int i = 2; i <= n; ++i) {
        int max = getMax(i, x);
        printf("max is %d\n", max );
        printf("%d\n", i / max );
    }
    return 0;
}