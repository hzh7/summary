#include <stdio.h>

int main() {
    //printf("Hello, World!\n");
    int n, m;
    int cnt0, cnt1;
    int car;
    scanf("%d", &n);
    while (n--){
        scanf("%d", &m);
        cnt0 = 0;
        cnt1 = 0;
        car = 1;
        while (car <= m){
            car *= 2;
        }
        car /= 2;
        while (car){
            if (m / car == 1){
                cnt1++;
            } else
                cnt0++;
            m %= car;
            car /= 2;
        }
        printf("%d %d\n", cnt0, cnt1);
    }
    return 0;
}