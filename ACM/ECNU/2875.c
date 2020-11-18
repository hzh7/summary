#include <stdio.h>
#include <string.h>
#include <math.h>

struct Student{
    char sno[11];
    int score;
};
int main() {
    //printf("Hello, World!\n");
    int n;
    struct Student student[100];
    float s = 0.0;
    float fx = 0;
    scanf("%d", &n);
    char tpno[11];
    int temp;
    for (int i = 0; i < n; ++i) {
        scanf("%*s", &tpno);
        strcpy(student[i].sno, tpno);
        scanf("%d", &temp);
        student[i].score = temp;
        s += temp;
    }
    s = s / n;
    printf("%.2f",s);
    for (int i = 0; i < n; ++i) {
        fx += (student[i].score - s)*(student[i].score - s);
    }
    fx /= (n-1);
    fx = sqrt(fx);
    printf(" %.2f\n", fx);
    return 0;
}