#include <stdio.h>

int main() {
    //printf("Hello, World!\n");
    int arr[100005] = {0};
    int m, n;
    int t;
    scanf("%d", &m);
    while (m--){
        scanf("%d", &t);
        arr[t] = 1;
    }
    scanf("%d", &n);
    while (n--){
        scanf("%d", &t);
        if (arr[t] == 1){
            printf("yes!\n");
        } else
            printf("no!\n");
    }
    return 0;
}