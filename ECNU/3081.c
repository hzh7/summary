#include <stdio.h>
#include <math.h>

int main() {
    //printf("Hello, World!\n");
    double d, p, r;
    double a, b, m;
    scanf("%lf %lf %lf", &d, &p, &r);
    a = p / (p - d * r);
    printf("%lf\n", a);

    a = log10(a);
    printf("%lf\n", a);
    b = log10(1.0 + r);
    printf("%lf\n", b);
    m = a / b;
    printf("%lf\n", m);
    return 0;
}