#include <stdio.h>
char* longestCommonPrefix(char** strs, int strsSize) {
    char *str = strs[0];
    int i, j;
    if (strsSize == 0)
        return "";
    for (i = 1; i < strsSize; ++i) {
        j = 0;
        while (str[j] && strs[i][j] && str[j] == strs[i][j]){
            j++;
        }
        str[j] = '\0';
    }
    return str;
}
int main() {
    //printf("Hello, World!\n");
    char *strs[20] = {
            "asdf",
            "asdffff",
            "asdfjhff",
            "asdopdrf"
    };
    printf("%s", longestCommonPrefix(strs,4));
    return 0;
}