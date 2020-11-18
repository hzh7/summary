#include <stdio.h>

int main() {
    //printf("Hello, World!\n");
    int e, f, c;
    int count;
    while (scanf("%d %d %d", &e, &f, &c) != EOF){
        count = 0;
        int sum = e + f;
        while (sum >= c){
            count += sum / c;
            sum = (sum % c + sum / c);
        }
        printf("%d\n", count);
    }
    return 0;
}