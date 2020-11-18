#include <stdio.h>

int main() {
    //printf("Hello, World!\n");
    int n;
    while (scanf("%d", &n) != EOF){
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - i; ++j) {
                printf(" ");
            }
            for (int k = 0; k < 2*i+1; ++k) {
                printf("*");
            }
            for (int j = 0; j < n - i; ++j) {
                printf(" ");
            }
            printf("\n");
        }
        for (int i = n; i < 2 * n + 1; ++i) {
            for (int j = 0; j < i - n; ++j) {
                printf(" ");
            }
            for (int k = 0; k < 2*n+1 - 2*(i-n); ++k) {
                printf("*");
            }
            for (int j = 0; j < i - n; ++j) {
                printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}