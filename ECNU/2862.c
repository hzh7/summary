#include <stdio.h>
#include <math.h>

int main() {
    //printf("Hello, World!\n");
    int a, b;
    float c;
    scanf("%d %d", &a, &b);
    c = a*a + b*b;
    printf("%.3f", sqrt(c));
    return 0;
}