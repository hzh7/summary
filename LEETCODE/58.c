#include <stdio.h>
#include <string.h>
int lengthOfLastWord(char* s) {
    int len = strlen(s);
    int flag = 0;
    int cnt = 0;
    for (int i = len - 1; i >= 0; --i) {
        if (s[i] != ' '){
            cnt++;
            flag = 1;
        }
        if(s[i] == ' ' && flag)
            break;
    }
    return cnt;
}
int main() {
    //printf("Hello, World!\n");
    char str[1000];
    gets(str);
    int t = lengthOfLastWord(str);
    printf("%d",t);
    return 0;
}