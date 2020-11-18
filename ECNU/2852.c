#include <stdio.h>
#include <string.h>

int main() {
    //printf("Hello, World!\n");
    char str[1000];
    int arr[26] = {0};
    int cnt = 0;
    gets(str);
    for (int i = 0; i < strlen(str); ++i) {
        if (str[i] >= 'a' && str[i] <= 'z'){
            arr[str[i]-'a']++;
            cnt++;
        }
    }
    int max = 0;
    for (int i = 1; i < 26; ++i) {
        if (arr[i] > arr[max])
            max = i;
    }
    char rest = max + 'a';
    float p = (float)arr[max] / cnt;
    printf("%c %.2f\n", rest, p);
    return 0;
}