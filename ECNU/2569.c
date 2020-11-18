#include <stdio.h>
#include <string.h>

int main() {
    //printf("Hello, World!\n");
    char str[1024];
    gets(str);
    //printf("a - A is %d",'a'-'A');
    for (int i = 0; i < strlen(str); ++i) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
        printf("%c", str[i]);
    }
    return 0;
}