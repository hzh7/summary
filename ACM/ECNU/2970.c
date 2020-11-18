#include <stdio.h>

int main() {
    //printf("Hello, World!\n");
    int t;
    scanf("%d", &t);
    int cas = 0;
    int n, m;
    int temp;
    while (t--){
        scanf("%d %d", &n, &m);
        if (m > n*4 || m < n*2)
            printf("case #%d:\nImpossible\n", cas);
        else{
            temp = (m - 2 * n) / 2;
            printf("case #%d:\n%d %d\n", cas, n - temp, temp);
        }
        cas++;
    }
    return 0;
}