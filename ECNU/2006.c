#include <stdio.h>

int isLone(int n){
    int sum;
    int temp = n;
    int len = 0;
    while (temp){
        len++;
        temp /= 10;
    }
    for (int i = n - 9 * len; i < n; ++i) {
        sum = 0;
        temp = i;
        while (temp > 0){
            sum += temp % 10;
            temp /= 10;
        }
        if (i + sum == n){
            return 0;
        }
    }
    return 1;
}
int main() {
    for (int i = 1; i <= 1000000; ++i) {
        if (isLone(i)){
            printf("%d\n", i);
        }
    }
    return 0;
}