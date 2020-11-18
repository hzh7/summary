#include <stdio.h>

int main() {
    //printf("Hello, World!\n");
    int t, n, cin;
    int arr[1000][50];
    scanf("%d", &t);
    while (t--){
        scanf("%d", &n);
        int i = 0;
        int nn = n;
        while (n--){
            int j = 0;
            scanf("%d", &cin);
            while (cin != -1){
                arr[i][j++] = cin;
                scanf("%d", &cin);
            }
            arr[i][j] = -1;
            i++;
        }
        int m = 0;
        for (i = 0; i < nn; ++i) {
            for (int j = 0; arr[i][j] != -1; ++j) {
                if (arr[i][j] > m){
                    m
                }
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }

        /*
        for (i = 0; i < nn; ++i) {
            for (int j = 0; arr[i][j] != -1; ++j) {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
         */
    }
    return 0;
}