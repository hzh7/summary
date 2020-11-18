#include <stdio.h>

int main() {
    //printf("Hello, World!\n");
    int t;
    scanf("%d", &t);
    int m, k;
    int arr[1000];
    int i;
    int temp;
    int sum;
    while (t--){
        i = 0;sum = 0;
        scanf("%d %d", &m, &k);
        while (m--){
            scanf("%d", &temp);
            arr[i++] = temp;
        }
        while (k--){
            sum += arr[k];
        }
        printf("%d\n", sum);
    }
    return 0;
}