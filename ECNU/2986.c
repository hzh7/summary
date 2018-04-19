#include <stdio.h>

int main() {
    //printf("Hello, World!\n");
    int t;
    scanf("%d", &t);
    int cas = 0;
    int n;
    while (t--){
        scanf("%d", &n);
        int r = 1;
        for (int i = 0; i < n; ++i) {
            r *= 2;
        }
        printf("case #%d:\n%d\n", cas, r);
        cas++;
    }
    return 0;
}