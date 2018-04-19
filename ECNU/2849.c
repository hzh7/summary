#include <stdio.h>
struct student{
    long long num;
    int score;
};
int main() {
    //printf("Hello, World!\n");
    int n;
    struct student str[100];
    long long snum;
    int sscore;
    int i = 0;
    scanf("%d", &n);
    while (i < n){
        scanf("%lld", &snum);
        scanf("%d", &sscore);
        str[i].num = snum;
        str[i++].score = sscore;
    }
    for (int j = 0; j < n; ++j) {
        for (int k = 0; k < n - 1; ++k) {
            if (str[k].score < str[k + 1].score) {
                struct student temp = str[k];
                str[k] = str[k + 1];
                str[k + 1] = temp;
            }
            if (str[k].score == str[k + 1].score) {
                if (str[k].num > str[k + 1].num) {
                    struct student temp = str[k];
                    str[k] = str[k + 1];
                    str[k + 1] = temp;
                }
            }
        }
    }
    for (int j = 0; j < n && str[j].score >= 60; ++j) {
        printf("%lld %d\n", str[j].num, str[j].score);
    }
    return 0;
}