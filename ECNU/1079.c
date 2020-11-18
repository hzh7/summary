#include <stdio.h>
/*
long C(int n, int m){
    //int result;
    long a = 1;
    long b = 1;
    int i = 1;
    while (i++ <= n){
        a *= i;
    }
    i = m - n;
    while (i++ <= m){
        b *= i;
    }
    //printf("a is %d  b is %d", a, b);
    return b / a;
}*/
int main() {
    int N;
    int map[30][30];
    for (int k = 0; k < 30; ++k) {
        map[k][0] = 1;
        map[k][k] = 1;
    }
    for (int i = 2; i < 30; ++i) {
        for (int j = 1; j < i; ++j) {
            map[i][j] = map[i - 1][j - 1] + map[i - 1][j];
        }
    }
    for (int i = 0; i < 30; ++i) {
        for (int j = 0; j <= i; ++j) {
            printf("%d  ", map[i][j]);
        }
        printf("\n");
    }
    while (scanf("%d", &N) != EOF){
        if(N == 0){
            return 0;
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j <= i; ++j) {
                if(j == 0){
                    printf("1");
                    if(i == 0)
                        printf("\n");
                }
                else{
                    //printf(" %d", C(j-1, i-1));
                    printf(" %d", map[i][j]);
                    if( j == i)
                        printf("\n");
                }
            }
        }
        printf("\n");
    }

    return 0;
}