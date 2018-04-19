#include <stdio.h>

int main() {
    //printf("Hello, World!\n");
    int t, n, x;
    int arr[30];
    int cas = 0;
    int count;
    int flag;
    scanf("%d", &t);
    while (t--){
        flag = 1;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            arr[i] = x;
        }
        while (flag){
            flag = 0;
            for (int i = 0; i < n; ++i) {
                count = 0;
                for (int j = i; j < n; ++j) {
                    if (arr[i] > arr[j]){
                        count++;
                    }
                }
                if (arr[i] != count){
                    arr[i] = count;
                    flag = 1;
                }
            }
        }
        printf("case #%d:\n%d", cas, arr[0]);
        for (int i = 1; i < n; ++i) {
            printf(" %d", arr[i]);
        }
        printf("\n");
        cas++;
    }
    return 0;
}