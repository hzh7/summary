#include <stdio.h>

int main() {
    //printf("Hello, World!\n");
    int m, n;
    int arr[500] = {0};
    int index;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &index);
        arr[index] = 1;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &index);
        if (arr[index] == 1)
            printf("yes!\n");
        else
            printf("no!\n");
    }
    return 0;
}