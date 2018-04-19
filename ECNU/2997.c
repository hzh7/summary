#include <stdio.h>

int main() {
    //printf("Hello, World!\n");
    int t, n;
    int cas = 0;
    int arr[37];
    arr[0] = 0;
    arr[1] = arr[2] = 1;
    for (int i = 3; i < 37; ++i) {
        arr[i] = arr[i-3] + arr[i-2] + arr[i-1];
    }
    scanf("%d", &t);
    while (t--){
        scanf("%d", &n);
        printf("case #%d:\n%d\n", cas, arr[n]);
        cas++;
    }
    return 0;
}