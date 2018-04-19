#include <stdio.h>
#include <string.h>


int strStr(char* haystack, char* needle) {
    int i, j;
    int pti;
    int sizeHay = strlen(haystack);
    int sizeNeed = strlen(needle);
    if (needle == "") {
        return -1;
    }
    for (i = 0; i <= sizeHay-sizeNeed; ++i) {
        pti = i;j = 0;
        while (j < sizeNeed){
            if(haystack[pti] == needle[j]){
                pti++;
                j++;
            } else
                break;
        }
        if(j == sizeNeed)
            return i;
    }
    return -1;
}
int main() {
    //printf("Hello, World!\n");
    char haystack[] = {"mississippi"};
    char needle[] = {"issip"};
    printf("%d", strStr(haystack, needle));
    return 0;
}