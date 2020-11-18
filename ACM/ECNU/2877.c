#include <stdio.h>
#include <stdbool.h>

bool isPrim(int n){
    for (int i = 2; i*i <= n; ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}
int main() {
    //printf("Hello, World!\n");
    int n;
    int a, b;
    while (scanf("%d", &n) != EOF){
        a = b = n/2;
        if (a % 2 == 0){
            a -= 1;
            b += 1;
        }
        while (!(isPrim(a) && isPrim(b)) && a > 1){
            a -= 2;
            b += 2;
        }
        printf("%d %d\n", a, b);
    }
    return 0;
}