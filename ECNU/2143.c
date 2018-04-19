#include <stdio.h>

int main() {
    //printf("Hello, World!\n");
    int N;
    int A, B;
    int num;
    scanf("%d", &N);
    while (N--){
        scanf("%d %d", &A, &B);
        num = A / B;
        num += A / B / 5 * 2;
        num += A / B % 5 / 3;
        printf("%d\n", num);
    }
    return 0;
}