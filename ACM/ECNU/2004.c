#include <stdio.h>
#include <math.h>

int main() {
    int sum;
    int temp;
    int falg = 1;
    for (int i = 1000; i < 10000; ++i) {
        sum = 0;
        temp = i;
        while (temp){
            sum += pow(temp % 10, 4);
            temp /= 10;
        }
        //printf("sum id %d\n", sum);

        if (sum == i) {
            printf("%d\n", i);
            falg = 0;
        }
    }
    if (falg)
        printf("no answer\n");
    return 0;
}