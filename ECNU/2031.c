#include <stdio.h>

int main() {
    //printf("Hello, World!\n");
    int n;
    int arr[100];
    while(scanf("%d", &n)!=EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if ((arr[j] > 0 ? arr[j] : -arr[j]) > (arr[j + 1] > 0 ? arr[j + 1] : -arr[j + 1])) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        printf("%d", arr[0]);
        for (int i = 1; i < n; ++i) {
            printf(" %d", arr[i]);
        }
        printf("\n");
    }
    return 0;
}