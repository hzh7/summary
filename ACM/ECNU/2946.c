#include <stdio.h>

int isP(int n){
    for (int i = 2; i*i <= n; ++i) {
        if(n % i == 0)
            return 0;
    }
    return 1;
}
int main() {
    //printf("Hello, World!\n");
    int t, a;
    scanf("%d", &t);
    while (t--){
        int arr[20000] = {0};
        scanf("%d", &a);
        for (int i = 2; i <= a; ++i) {
            if (isP(i)){
                while (a % i == 0){
                    a /= i;
                    arr[i]++;
                }
            }
        }
        for (int i = 2; i < 20000; ++i) {
            if (arr[i] != 0){
                printf("(%d,%d)",i, arr[i]);
            }
        }
        printf("\n");
    }
    return 0;
}