#include <stdio.h>

int main() {
    //printf("Hello, World!\n");
    int n;
    scanf("%d", &n);
    int t;
    int data[31] = {0};
    while (n--){
        while (scanf("%d", &t) != EOF){
            if(t == -1)
                break;
            data[t] = 1;
        }
    }
    int flag = 1;
    for (int i = 1; i < 31; ++i) {
        if (data[i] == 0){
            flag = 0;
            printf("no");
            break;
        }
    }
    if(flag)
        printf("yes");
    return 0;
}