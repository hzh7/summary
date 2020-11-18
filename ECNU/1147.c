#include <stdio.h>
#include <math.h>

int main() {
    //printf("Hello, World!\n");
    int T;
    int N, R;
    char ABC[26];
    for (int i = 0; i < 26; ++i) {
        ABC[i] = i + 'A';
    }
    scanf("%d", &T);
    while (T--){
        scanf("%d %d", &N, &R);
        if(N < 0){
            printf("-");
            N = -N;
        }
        int n = 0;
        for (; n < 32; n++) {
            if (N < pow(R, n)){
                break;
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            int temp = (pow(R, i));
            int shang = N / temp;
            if (shang >= 0 && shang <= 9)
                printf("%d", N / temp);
            else{
                printf("%c", ABC[shang - 10]);
                /*switch (shang){
                    case 10:
                        printf("A");
                        break;
                    case 11:
                        printf("B");
                        break;
                }*/
            }
            N = N % temp;
        }
        printf("\n");
    }
    return 0;
}