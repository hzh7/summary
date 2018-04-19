#include <stdio.h>
#include <math.h>

int main() {
    //printf("Hello, World!\n");
    float x, y;
    while(scanf("%f %f", &x, &y) != EOF){
        printf("%.3f\n", pow(x, y));
    }
    return 0;
}