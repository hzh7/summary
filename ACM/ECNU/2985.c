#include <stdio.h>
#include <math.h>

# define PI 3.1415926535

int main() {
    //printf("Hello, World!\n");
    int t, n, k;
    int cas = 0;
    float sum, a;
    scanf("%d", &t);
    while (t--){
        scanf("%d %d", &n, &k);
        a = (float)n;
        sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += (a*a - PI * (a/2.0) * (a/2.0));
            a /= sqrt(2.0);
        }
        printf("case #%d:\n%.6f\n", cas, sum);
        cas++;
    }
    return 0;
}