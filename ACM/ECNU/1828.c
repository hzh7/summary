#include <stdio.h>

int main() {
    int N;
    int h, m, s;
    while (scanf("%d", &N)){
        if(N == -1){
            return 0;
        }
        h = N / 3600;
        N %= 3600;
        m = N / 60;
        s = N % 60;
        //printf("hour is %d minent is %dand scond is%d\n", h, m, s);
        printf("%02d:%02d:%02d\n", h, m, s);
    }
    return 0;
}