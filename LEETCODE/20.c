#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char* s){
    char stack[1024];
    int p = 0;
    for (int i = 0; i < strlen(s); ++i) {
        if(p == 0) {
            stack[p++] = s[i];
        }
        else if(s[i] - stack[p-1] == 2 || s[i] - stack[p-1] == 1)
            p--;
        else
            stack[p++] = s[i];
    }
    if(p == 0)
        return true;
    else
        return false;
}
int main() {
    //printf("Hello, World!\n");
    char *s = "{[())]}";
    printf("%d\n", isValid(s));
    //printf("%d\n", ')'-'(');
    return 0;
}