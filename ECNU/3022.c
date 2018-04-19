#include <stdio.h>

int main() {
    //printf("Hello, World!\n");
    int t, n;
    scanf("%d", &t);
    int cas = 0;
    int count, sum;
    while (t--){
        count = 0;
        sum = 1;
        scanf("%d", &n);
        for (int i = 2; i <= n; ++i) {
            sum *= i;
            while (sum % 10 == 0){
                count++;
                sum /= 10;
            }
            sum %= 100;
        }
        printf("case #%d:\n%d\n", cas, count);
        cas++;
    }
    return 0;
}