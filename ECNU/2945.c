#include <stdio.h>
#include <string.h>

struct Web{
    char add[100];
    int vi;
};
int main() {
    //printf("Hello, World!\n");
    int n;
    scanf("%d", &n);
    char tadd[100];
    int tvi;
    struct Web web[20];
    int maxvi = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%s", tadd);
        strcpy(web[i].add, tadd);
        //gets(web[i].add);
        scanf("%d", &tvi);
        web[i].vi = tvi;
        if (maxvi < tvi)
            maxvi = tvi;
    }
    for (int i = 0; i < n; ++i) {
        if (maxvi == web[i].vi){
            printf("%s\n", web[i].add);
        }
    }
    return 0;
}