#include <stdio.h>

int main() {
    //printf("Hello, World!\n");
    int n, m;
    scanf("%d", &n);
    while (n--){
        scanf("%d", &m);
        printf("%d ",m/100);
        m %= 100;
        printf("%d ",m/50);
        m %= 50;
        printf("%d ",m/20);
        m %= 20;
        printf("%d ",m/10);
        m %= 10;
        printf("%d ",m/5);
        m %= 5;
        printf("%d ",m/2);
        printf("%d\n",m %= 2);
    }
    return 0;
}