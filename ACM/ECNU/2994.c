#include <stdio.h>

int main() {
    //printf("Hello, World!\n");
    int t, n, x, index;
    scanf("%d", &t);
    int cas = 0;
    while (t--){
        index = 0;
        int arr[500] = {0};
        int isfirst = 1;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            arr[x]++;
        }
        printf("case #%d:\n", cas);
        for (int i = 0; i < 500; ++i) {
            for (int j = 0; j < 500; ++j) {
                if ((arr[j] > arr[index]) || (arr[j] == arr[index] && j < index)){
                    index = j;
                }
            }
            if (arr[index] == 0) {
                break;
            }
            while (arr[index]--){
                if (isfirst){
                    printf("%d", index);
                    isfirst = 0;
                } else{
                    printf(" %d", index);
                }
            }
        }
        printf("\n");
        cas++;
    }
    return 0;
}