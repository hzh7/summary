#include <stdio.h>

int climbStairs(int n) {
    /*
     * 超时！
    if(n == 1)
        return 1;
    if(n == 2)
        return 2;
    return climbStairs(n-1) + climbStairs(n-2);*/
    int a = 0;
    int b = 1;
    for (int i = 0; i < n; ++i) {
        b = a + b;
        a = b - a;
    }
    return b;
}
int main() {
    //printf("Hello, World!\n");
    int n = 1;
    int t = climbStairs(n);
    printf("%d", t);
    return 0;
}