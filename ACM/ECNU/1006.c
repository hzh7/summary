#include <stdio.h>
#include <math.h>

int isPrime(int n){
    int flag = 1;
    if(n == 1)
        return 0;
    for (int i = 2; i <= sqrt(n); ++i) {
        if(n%i == 0){
            flag = 0;
            break;
        }
    }
    return flag;
}
int main() {
    //printf("Hello, World!\n");
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF){
        int count = 0;
        for (int i = n; i <= m; ++i) {
            if(isPrime(i)){
                count++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}