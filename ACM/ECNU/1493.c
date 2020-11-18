#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    //printf("Hello, World!\n");
    char str[50];
    double n;
    scanf("%s", str);
    n = atof(str);
    /*printf("n is %f\n",n);
    printf("sqrt(n) is %f\n", sqrt(n));
    printf("sqrt(n)*sqrt(n) is %f\n", sqrt(n)*sqrt(n));*/
    if ((long long)sqrt(n) == sqrt(n))
        printf("%lld\n", (long long)sqrt(n));
    else
        printf("%lld\n", (long long)sqrt(n)+1);

    return 0;
}