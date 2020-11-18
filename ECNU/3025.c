#include <stdio.h>

int main() {
    //printf("Hello, World!\n");
    int t, n;
    int cas = 0;
    scanf("%d", &t);
    while (t--){
        int count = 0;
        scanf("%d", &n);
        for (int i = 3; i <= n; ++i) {
            if (n % i == 0 && i % 2 == 1){
                count++;
            }
        }
        printf("case #%d:\n%d\n", cas, count);
        cas++;
    }
    return 0;
}