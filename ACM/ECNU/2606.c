#include <stdio.h>
int main() {
    int t, a, b, h;
    float x;
    scanf("%d", &t);
    while (t--){
        scanf("%d %d %d", &a, &b, &h);
        x = (float)b*h/(float)a;
        printf("%0.2f\n", x);
    }
    return 0;
}