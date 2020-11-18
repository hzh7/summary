#include <stdio.h>

int mySqrt(int x) {
    /*if (x == 0)
        return 0;*/
    long long n = x;
    long long i = 0;
    //for (i = 0; i * i <= x; ++i) {}
    while (i * i <= n)
        i++;
    return i-1;
}
int sqrt(int x) {
    if (x == 0) return 0;
    double last = 0;
    double res = 1;
    while (res != last)
    {
        last = res;
        res = (res + x / res) / 2;
    }
    return res;
}
int main() {
    int x = 0;//214739560
    int t = mySqrt(x);
    long long y = 46341*46341;
    printf("%d\n",289398*289398);
    printf("%d\n",46340*46340);
    printf("%d\n",y);
    printf("%d", t);
    return 0;
}