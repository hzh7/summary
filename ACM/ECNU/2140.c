#include <stdio.h>

int main() {
    //printf("Hello, World!\n");
    int c;
    scanf("%d", &c);
    int n, m;
    int arr[100][100];
    int t;
    while (c--){
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d", &t);
                arr[i][j] = t;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d", &t);
                arr[i][j] += t;
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}