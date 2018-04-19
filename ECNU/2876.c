#include <stdio.h>

int main() {
    //printf("Hello, World!\n");
    int t;
    scanf("%d", &t);
    int x, y;
    int count;
    while (t--){
        count = 0;
        scanf("%d %d", &x, &y);
        while (x != 0 || y != 0){
            if (x % 2 != y % 2){
                count++;
            }
            x >>= 1;
            y >>= 1;
        }
        printf("%d\n", count);
    }
    return 0;
}