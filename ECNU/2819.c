#include <stdio.h>

int main() {
    //printf("Hello, World!\n");
    int T;
    int n;
    int sum;
    scanf("%d", &T);
    while (T--){
        scanf("%d", &n);
        sum = n;
        while (n > 2){
            sum += n / 3;
            n = n / 3 + n % 3;
        }
        printf("%d\n", sum);
    }
    return 0;
}