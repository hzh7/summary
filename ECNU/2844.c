#include <stdio.h>

int main(){
    char AD;
    scanf("%c", &AD);
    int arr[1000] = { 0 };
    int n;
    int flag = 1;
    while (scanf("%d", &n) != EOF){
        arr[n] = 1;
    }
    if(AD == 'A'){
        for (int i = 0; i < 1000; ++i) {
            if (arr[i] == 1){
                if(flag){
                    printf("%d", i);
                    flag = 0;
                } else
                    printf(" %d", i);
            }
        }
    } else{
        for (int i = 999; i >= 0; --i) {
            if (arr[i] == 1){
                if(flag){
                    printf("%d", i);
                    flag = 0;
                } else
                    printf(" %d", i);
            }
        }
    }
    return 0;
}