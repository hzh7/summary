#include <stdio.h>

int isPer(int n){
    int sum = 1;
    for (int i = 2; i <= n/2; ++i) {
        if (n % i == 0){
            sum += i;
        }
    }
    if (sum == n){
        printf("%d its factors are", n);
        for (int i = 1; i <= n/2; ++i) {
            if (n % i == 0){
                printf(" %d", i);
            }
        }
        printf("\n");
        return 1;
    }
    return 0;
}
int main() {
    for (int i = 2; i <= 4000; ++i) {
        isPer(i);
    }
    return 0;
}