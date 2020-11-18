#include <stdio.h>

int main() {
    //printf("Hello, World!\n");
    float n, k, m;
    float price;
    float sum;
    int flag;
    while(scanf("%f %f %f", &n, &k, &m) != EOF){
        flag = 1;
        price = 270;
        sum = n;
        k /= 100;
        m /= 100;
        for (int i = 2; i <= 30; ++i) {
            n *= (1 + m);
            sum += n;
            price *= (1 + k);
            //printf("sum is %f price is %f\n", sum, price);
            if (sum >= price){
                printf("%d\n", i);
                flag = 0;
                break;
            }
        }
        if (flag){
            printf("Impossible\n");
        }
    }

    return 0;
}