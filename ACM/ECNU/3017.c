#include <stdio.h>

int FactorialZeros(int n){
    long long m = 1;
    int count = 0;
    for (int i = 2; i <= n; ++i) {
        m *= i;
    }
    while (m % 10 == 0){
        m /= 10;
        count++;
    }
    return count;
}
int main() {
    //printf("Hello, World!\n");
    int n;
    scanf("%d", &n);
    int i = 0;
    while (i++ < n){
        int t;
        scanf("%d", &t);
        printf("case #%d:\n", i-1);
        int count = FactorialZeros(t);
        printf("%d\n", count);
    }
    return 0;
}