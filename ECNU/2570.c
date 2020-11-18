#include <stdio.h>

int isP(int n){
    for (int i = 2; i*i <= n; ++i) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
int main() {
    //printf("Hello, World!\n");
    int t, n;
    int arr[10005] = {0};
    for (int i = 2; i <= 10000; ++i) {
        if (isP(i))
            arr[i] = 1;
    }
    /*for (int i = 1; i <= 50; ++i) {
        printf("%d ", arr[i]);
    }*/
    scanf("%d", &t);
    while (t--){
        int cnt = 0;
        scanf("%d", &n);
        for (int i = 2; i <= n; ++i) {
            if (arr[i] == 1 && arr[n-i+1] == 1){
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}