#include <stdio.h>
#include <string.h>

int main() {
    //printf("Hello, World!\n");
    int t;
    char str[100];
    scanf("%d", &t);
    while (t--){
        scanf("%s", &str);
        for (int i = 0; i < strlen(str); ++i) {
            printf("%02d", str[i] - 'a' + 1);
        }
        printf("\n");
    }
    return 0;
}