#include <iostream>
#include <cmath>

int main() {

    int i = 0;

    int N;
    scanf("%d", &N);
    while(N--) {
        /*for (; i < 32; i++) {
            scanf("%d", &by[i]);
            //std::cin >> by[i];
        }*/
        char by[40];
        scanf("%s", &by);
        //getchar();
        int sum = 0;
        for (i = 0; i < 32; i++) {
            //sum += 2 ^ (i % 8);
            sum += ldexp(by[i] - '0', (31-i) % 8);
            /*
             * int num=((str[0+i*8]-'0')<<7)+((str[1+i*8]-'0')<<6)+((str[2+i*8]-'0')<<5)+((str[3+i*8]-'0')<<4)+((str[4+i*8]-'0')<<3)+((str[5+i*8]-'0')<<2)+((str[6+i*8]-'0')<<1)+((str[7+i*8]-'0')<<0);
             * */
            if ((31 - i) % 8 == 0) {
                printf("%d", sum);
                sum = 0;
                if ((31 - i) != 0) {
                    printf(".");
                }
            }
        }
        printf("\n");
    }
        //std::cout<<by;
    return 0;
}