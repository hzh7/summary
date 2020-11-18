#include <stdio.h>

int main() {
    //printf("Hello, World!\n");
    int t, n, x, r;
    int cas = 0;
    int arr1[1000], arr2[1000];
    scanf("%d", &t);
    while (t--){
        scanf("%d", &n);
        r = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            arr1[i] = x;
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            arr2[i] = x;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n - i - 1; ++j) {
                if (arr1[j] > arr1[j+1]){
                    int temp = arr1[j];
                    arr1[j] = arr1[j+1];
                    arr1[j+1] = temp;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n - i - 1; ++j) {
                if (arr2[j] < arr2[j+1]){
                    int temp = arr2[j];
                    arr2[j] = arr2[j+1];
                    arr2[j+1] = temp;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            r += arr1[i]*arr2[i];
        }
        printf("case #%d:\n%d\n", cas, r);
        cas++;
    }
    return 0;
}