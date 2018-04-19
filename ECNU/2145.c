#include <stdio.h>

int main() {
    //printf("Hello, World!\n");
    int n, m;
    scanf("%d", &n);
    while (n--){
        int e = 2;
        int sum = 0;
        scanf("%d", &m);
        while(m>0){
            sum += (e * e - (e-2) * (e-2)) * m;
            m--;
            e += 2;
        }
        printf("%d\n", sum);
    }
    return 0;
}