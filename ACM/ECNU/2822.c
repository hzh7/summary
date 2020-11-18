#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int len;
    char str[100];
    while (scanf("%s", str) != EOF){
        int isf = 1;
        for (int i = 0; i < strlen(str); ++i) {
            if (str[i] == '.') {
                isf = 0;
                break;
            }
        }
        if (isf){
            int n = atoi(str);
            len = sizeof(int);
            for (int i = 0; i < len; ++i) {
                printf("%02x ", ((unsigned char*)&n)[i]);
            }
        }
        else{
            double n = atof(str);
            len = sizeof(double);
            for (int i = 0; i < len; ++i) {
                printf("%02x ", ((unsigned char*)&n)[i]);
            }
        }
        printf("\n");
    }
    return 0;
}