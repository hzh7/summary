#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* countAndSay(int n) {
    //char cas[100000];
    //char newcas[100000];
    char* cas=(char*)malloc(sizeof(char)*100000);
    char* newcas=(char*)malloc(sizeof(char)*100000);
    cas[0] = 1;
    //strcpy(cas,"1");
    //strcpy(newcas,"");

    for (int i = 0; i < n-1; ++i) {
        int count = 1;
        int k = 0;
        for (int j = 0; j < strlen(cas); ++j) {
            if(cas[j] == cas[j+1]) {
                count++;
            } else{
                newcas[k++] = count;
                newcas[k++] = cas[j];
                count = 1;
            }
        }
        newcas[k] = '\0';
        strcpy(cas, newcas);
        strcpy(newcas, "");
    }
    //static char result[100000];
    //int t = strlen(cas);
    //printf("lenth of cas is %d\n",t);
    for (int i = 0; i < strlen(cas); ++i) {
        cas[i] = cas[i]+'0';
        //printf("%c  ", cas[i]+'0');
    }
    //result[strlen(cas)]='\0';
    //strcpy(result,cas);
    //return result;
    return cas;
}
int main() {
    //printf("Hello, World!\n");
    int n = 10;

    printf("%s", countAndSay(n));

    return 0;
}

//311311222113111231131112132112311321322112111312211312111322212311322113212221
//311311222113111231131112132112311321322112111312211312111322212311322113212221