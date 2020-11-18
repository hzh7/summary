#include <stdio.h>

int getBack(int n){
    int m = 0;
    while (n){
        m = m * 10 + n % 10;
        n /= 10;
    }
    //printf("m is %d\n", m);
    return m;
}
int main() {
    //printf("Hello, World!\n");
    int n, m, s;
    scanf("%d", &n);
    int cnt = 1;
    m = getBack(n);
    s = n + m;
    int k = getBack(s);
    while (k != s){
        n = s;
        m = k;
        s = n + m;
        k = getBack(s);
        cnt++;
    }
    printf("%d %d\n", cnt, s);
    return 0;
}