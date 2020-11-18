#include <stdio.h>

int main() {
    //printf("Hello, World!\n");
    int t, a, sum;
    scanf("%d", &t);
    while (t--){
        sum = 0;
        scanf("%d", &a);
        while (a > 9){
            while (a){
                sum += a % 10;
                a /= 10;
            }
            a = sum;
            sum = 0;
        }
        printf("%d\n", a);
    }
    return 0;
}