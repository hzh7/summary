#include <stdio.h>

int GCD(int a, int b){
    return b == 0 ? a : GCD(b, a % b);
}
int main() {
    //printf("Hello, World!\n");
    int n;
    int a, b;
    scanf("%d", &n);
    while (n--){
        scanf("%d %d", &a, &b);
        int gcd = GCD(a, b);
        printf("%d %d\n", gcd, a * b / gcd);
    }
    return 0;
}