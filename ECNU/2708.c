#include <stdio.h>

int main() {
    //printf("Hello, World!\n");
    int t;
    while (scanf("%d", &t) != EOF){
        if (t == 0)
            printf("1");
        else if (t == 1)
            printf("0");
        else {
            if (t % 2 == 1)
                printf("4");
            for (int i = 0; i < t / 2; ++i) {
                printf("8");
            }
        }
        printf("\n");
    }
    return 0;
}