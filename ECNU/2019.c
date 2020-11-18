#include <stdio.h>

int main() {
    int arr[6];
    for (int i = 0; i < 6; ++i) {
        arr[i] = 'A' + i;
    }
    unsigned int t;
    unsigned short a, b;
    while (scanf("%d", &t) != EOF){
        b = t >> 16;
        a = t & 0xFFFF;
       //printf("1 a is %d b is %d \n", a ,b);
        b = ~b;
        //printf("2 a is %d b is %d \n", a ,b);
        a = a^b;
        /*int c = 1;
        while (c < a){
            c *= 16;
        }
        if (c != 1)
            c /= 16;
        int t;
        while (a){
            t = a / c;
            if (t < 10)
                printf("%d", t);
            else {
                printf("%c", arr[t-10]);
            }
            a = a % c;
            c /= 16;
        }
        c = 4096;
        int j = 4;
        while (j--){
            t = b / c;
            if (t < 10)
                printf("%d", t);
            else {
                printf("%c", arr[t-10]);
            }
            b = b % c;
            c /= 16;
        }

        printf("\n");*/
        t = 0;
        t = a<<16;
        t = t|b;
        printf("%X\n", t);
    }

    return 0;
}