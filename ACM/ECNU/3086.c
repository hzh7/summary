#include <stdio.h>

int isSxh(int n){
    int t = n;
    int s = 0;
    while (t){
        int a = t % 10;
        s += a * a * a;
        t /= 10;
    }
    if (n == s)
        return 1;
    return 0;
}
int main( )
{
    printf("153\n370\n371\n407\n");
    for (int i = 100; i < 1000; ++i) {
        if (isSxh(i)){
            //printf("%d\n", i);
        }
    }
    return 0;
}
