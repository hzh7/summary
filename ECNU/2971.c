#include <stdio.h>

int main() {
    //printf("Hello, World!\n");
    int t, c, w, count;
    int cas = 0;
    scanf("%d", &t);
    while (t--){
        count = 0;
        scanf("%d %d", &c, &w);
        int min = 1,max = 1;
        for (int i = 1; i < c; ++i) {
            min *= 10;
            max *= 10;
        }
        max *= 10;
        for (int i = min + w; i < max + w; i+=10) {
            if (i % 3 == 0){
                count++;
            }
        }
        printf("case #%d:\n%d\n", cas, count);
        cas++;
    }
    return 0;
}