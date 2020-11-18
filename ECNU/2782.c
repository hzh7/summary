#include <stdio.h>
#include <string.h>

int main() {
    //printf("Hello, World!\n");
    int n;
    scanf("%d", &n);
    char str[15];
    while (n--){
        scanf("%s", &str);
        if (strcmp(str,"E") == 0){
            printf("Excellent\n");
        } else if (strcmp(str,"C") == 0){
            printf("Cheer\n");
        }else if (strcmp(str,"N") == 0){
            printf("Nice\n");
        }else if (strcmp(str,"U") == 0){
            printf("Ultimate\n");
        }else if (strcmp(str,"Impossible") == 0){
            printf("I'm possible\n");
        }else if (strcmp(str,"ACM") == 0){
            printf("Accept More\n");
        }
    }
    return 0;
}