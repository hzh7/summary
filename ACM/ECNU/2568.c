#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int a, b;
    while (n--) {
        scanf("%d %d", &a, &b);
        int sum = a + b;
        int k = 0;
        while (sum > 0){
            sum /= 10;
            k ++;
        }
        printf("%d\n", k);
    }
    return 0;
}