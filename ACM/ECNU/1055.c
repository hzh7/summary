#include <stdio.h>

int gcd(int a, int b){
    if (a == 0)
        return b;
    return b == 0 ? a : gcd(b , a % b);
}
int main() {
    int a, b;
    while (scanf("%d %d", &a, &b) != EOF) {
        int c = gcd(a, b);
        printf("%d\n", c);
    }
    return 0;
}