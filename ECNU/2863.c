#include <stdio.h>
#include <math.h>

int main() {
    //printf("Hello, World!\n");
    int n;
    float h, t;
    scanf("%d", &n);
    if (n<4)
        h = (n-1)*5 + 1.75;
    else
        h = 11.75 + (n-3)*3;
    t = sqrt(h * 2.0 / 9.8);

    printf("%.3f\n", t);
    return 0;
}