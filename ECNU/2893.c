#include <stdio.h>
#include <string.h>

int main() {
    //printf("Hello, World!\n");
    char str[300];
    int len;
    int cnt;
    while(gets(str)){
        len = strlen(str);
        cnt = 0;
        char ch;
        for (int i = 0; str[i] != '\0'; ++i) {
            ch = (unsigned char)str[i];
            while (ch) {
                if (ch % 2) {
                    cnt++;
                }
                ch /= 2;
            }
        }
        len *= 8;
        for (int i = cnt; i > 0; ++i) {
            if (cnt % i == 0 && len % i == 0){
                cnt /= i;
                len /= i;
                break;
            }
        }

        printf("%d/%d\n",cnt, len);
    }
    return 0;
}