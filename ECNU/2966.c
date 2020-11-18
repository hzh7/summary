#include <stdio.h>
#include <stdlib.h>

void prtB(int n){
    if (n == 0){
        printf("0");
        return;
    }
    int t = 1;
    while ( t <= n){
        t *= 2;
    }
    t /= 2;
    while (t){
        printf("%d", n/t);
        n %= t;
        t /= 2;
    }
}
void prtH(int n){
    if (n == 0){
        printf("0");
        return;
    }
    char arr[6];
    for (int i = 0; i < 6; ++i) {
        arr[i] = 'A' + i;
    }
    int t = 1;
    while ( t <= n){
        t *= 16;
    }
    t /= 16;
    while (t){
        if (n/t < 10)
            printf("%d", n/t);
        else
            printf("%c", arr[n/t -10]);
        n %= t;
        t /= 16;
    }
}
int main() {
    //printf("Hello, World!\n");
    int T;
    int n;
    scanf("%d", &T);
    int i = 0;
    while (i < T){
        scanf("%d", &n);
        printf("case #%d:\n",i);
        //prtB(n);
        //itoa(n,n,2);
        //printf("%s",n);
        printf(" ");
        printf("%X",n);
        //prtH(n);
        i++;
        printf("\n");
    }
    return 0;
}