#include <stdio.h>

int main() {
    //printf("Hello, World!\n");
    int n;
    int arr[55];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    for (int i = 3; i < 55; ++i) {
        arr[i] = arr[i-1] + arr[i-3];
    }
    while (scanf("%d", &n) != EOF){
        if (n == 0)
            return 0;
        printf("%d\n", arr[n-1]);
    }
    return 0;
}