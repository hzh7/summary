
#include <stdio.h>
#include <string.h>

int main() {
    //printf("Hello, World!\n");
    char str[105];
    scanf("%s", &str);
    int lenstr = strlen(str);
    int n;
    scanf("%d", &n);
    int a, b;
    char s[105];
    int lens;
    int count;
    while (n--){
        count = 0;
        scanf("%d %d", &a, &b);
        scanf("%s", &s);
        lens = strlen(s);
        int j = 0;
        for (int i = a; i <= b; ++i) {
            if (str[i] == s[j]){
                j++;
                if (j == lens){
                    count++;
                    i = i - j + 1 ;
                    j = 0;
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}