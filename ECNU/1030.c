#include <stdio.h>

int main() {
    //printf("Hello, World!\n");
    int N;
    int arr[50];
    arr[0] = arr[1] = arr[2] = 1;
    while (scanf("%d", &N) != EOF){
        if(N == 0)
            return 0;
        for (int i = 3; i < N; ++i) {
            arr[i] = arr[i - 1] + arr[i - 3];
        }
        printf("%d\n", arr[N - 1]);
    }

    return 0;
}