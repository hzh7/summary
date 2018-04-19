#include <stdio.h>

int main() {
    //printf("Hello, World!\n");
    int t, p, e, i, d;
    int cas = 0;
    scanf("%d", &t);
    while (t--){
        scanf("%d %d %d %d", &p, &e, &i, &d);
        p %= 23;
        e %= 28;
        i %= 33;
        for (int k = 1; k <= 21252; ++k) {
            if ((d+k-p)%23 == 0 && (d+k-e)%28 == 0 &&(d+k-i)%33 == 0){
                printf("case #%d:\nthe next triple peak occurs in %d days.\n", cas, k);
                break;
            }
        }
        cas++;
    }
    return 0;
}