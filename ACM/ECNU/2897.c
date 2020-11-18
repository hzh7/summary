#include <stdio.h>
#include <string.h>

int main() {
    //printf("Hello, World!\n");
    int t =1;
    char str[105];//= "United States of America"
    while (gets(str)){
        //gets(str);
        int len = strlen(str);
        for (int i = 0; i < len; ++i) {
            char ss[105];
            int j;
            for (j = i; j < len; ++j) {
                if (str[j] == ' ' || str[j] == '-'){
                    break;
                }
            }
            int k;
            for (k = 0; k < j-i; ++k) {
                ss[k] = str[k+i];
            }
            ss[k] = '\0';
            if (strcmp(ss,"the")!=0 && strcmp(ss,"The")!=0
                && strcmp(ss,"a")!=0 &&  strcmp(ss,"A")!=0
                && strcmp(ss,"of")!=0 &&  strcmp(ss,"OF")!=0
                && strcmp(ss,"for")!=0 && strcmp(ss,"FOR")!=0
                && strcmp(ss,"and")!=0 && strcmp(ss,"AND")!=0){
                printf("%c", str[i]);
            }
            i = j;
        }
        printf("\n");
    }
    return 0;
}