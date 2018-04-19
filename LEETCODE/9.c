#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    if(x < 0)
        return false;
    int t = 0;
    int y = x;
    while (y){
        t = t * 10 + y%10;
        y /= 10;
    }
    if(t == x)
        return true;
    return false;
}
int main() {
    // printf("Hello, World!\n");
    int n;
    while(scanf("%d", &n) != EOF){
        printf("%d\n", isPalindrome(n));
    }
    return 0;
}