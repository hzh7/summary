#include <stdio.h>
#include <string.h>

struct Student{
    char num[11];
    int score;
};
int main() {
    //printf("Hello, World!\n");
    int t, n, m, g, s;
    int count;
    /*long long snum;
    scanf("%lld", snum);
    printf("%01lld", snum);*/

    struct Student student[100];
    int am[10];//每题分值
    scanf("%d", &t);
    int cas = 0;
    while (t--){
        count = 0;
        scanf("%d %d %d", &n, &m, &g);
        for (int i = 0; i < m; ++i) {
            int temp;
            scanf("%d", &temp);
            am[i] = temp;
        }
        for (int i = 0; i < n; ++i) {
            char temp[11];
            scanf("%s", &temp);
            student[i].score = 0;
            strcpy(student[i].num, temp);
            scanf("%d", &s);
            while (s--){
                int temp;
                scanf("%d", &temp);
                student[i].score += am[temp-1];
            }
            if (student[i].score >= g)
                count++;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n - i - 1; ++j) {
                if (student[j].score < student[j+1].score){
                    struct Student temp = student[j];
                    student[j] = student[j+1];
                    student[j+1] = temp;
                }
                if (student[j].score == student[j+1].score && strcmp(student[j].num, student[j+1].num) > 0){
                    struct Student temp = student[j];
                    student[j] = student[j+1];
                    student[j+1] = temp;
                }
            }
        }
        printf("case #%d:\n%d\n", cas, count);
        for (int i = 0; i < n; ++i) {
            if (student[i].score < g) {
                break;
            }
            printf("%s", student[i].num);
            printf(" %d\n", student[i].score);
        }

        cas++;
    }
    return 0;
}