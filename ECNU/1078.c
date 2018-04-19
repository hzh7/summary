#include <stdio.h>

int main() {
    //printf("Hello, World!\n");
    int arr[10] = {31,28,31,30,31,30,31,31,30,21};
    int t, m, d;
    scanf("%d", &t);
    while (t--){
        scanf("%d %d", &m, &d);
        if (m > 10 || (m == 10) && d > 21){
            printf("What a pity, it has passed!\n");
            continue;
        }
        int sum = arr[m-1] - d;
        for (int i = m; i < 10; ++i) {
            sum += arr[i];
        }
        if (sum == 0){
            printf("It's today!!\n");
        } else{
            printf("%d\n", sum);
        }

    }
    return 0;
}