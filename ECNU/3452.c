#include <stdio.h>

int main() {
    //printf("Hello, World!\n");
    int p;
    int parr[4] = {0};
    int flag = 1;
    scanf("%d", &p);
    int a[6], b[6];
    for (int i = 0; i < 6; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < 6; ++i) {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < 6; ++i) {
        for (int j = 0;j < 6; ++j){
            parr[(a[i] + b[j]) % p]++;
            //parr[ % p]++;
        }
    }

    int temp = parr[0];
    for (int i = 1; i < p; ++i) {
        if (parr[i] != temp)
            flag = 0;
    }
    if (flag)
        printf("YES");
    else
        printf("NO");
    return 0;
}