#include <stdio.h>

int main() {
    //printf("Hello, World!\n");
    float a;
    while (scanf("%f", &a) != EOF){
        int b = (int)a;
        printf("%d\n", b);
    }
    return 0;
}