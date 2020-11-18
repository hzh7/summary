#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct Phone{
    char num[8];
};

bool Mystrcpy(char num1[], char num2[]){
    for (int i = 0; i < 8; ++i) {
        if (num1[i] != num2[i])
            return false;
    }
    return true;
}
int main() {
    //printf("Hello, World!\n");
    char arr[26] = {'2','2','2','3','3','3','4','4','4',
                    '5','5','5','6','6','6','7','7','7','7',
                    '8','8','8','9','9','9','9'};
    char str[80];
    struct Phone phone[100];
    int n;
    int index;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", str);
        index = 0;
        for (int j = 0; j < strlen(str); ++j) {
            if (str[j]>= 'A' && str[j] <='Z'){
                phone[i].num[index++] = arr[str[j]-'A'];
            }
            if (str[j]>= '0' && str[j] <='9'){
                phone[i].num[index++] = str[j];
            }
            //phone[i].num[index] = '\0';
        }
    }
    /*for (int i = 0; i < n; ++i) {
        printf("%c%c%c%c-%c%c%c%c\n", phone[i].num[0], phone[i].num[1],
               phone[i].num[2], phone[i].num[3], phone[i].num[4],
               phone[i].num[5], phone[i].num[6], phone[i].num[7]);
    }*/

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n-i-1; ++j) {
            if (strcpy(phone[j].num,phone[j+1].num)>0){
                char temp;// = phone[j].num;
                for (int k = 0; k < 8; ++k) {
                    temp = phone[j].num[i];
                    phone[j].num[i] = phone[j+1].num[i];
                    phone[j+1].num[i] = temp;
                }
                /*struct Phone temp = phone[j];
                phone[j] = phone[j+1];
                phone[j+1] = temp;*/
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        printf("%c%c%c%c-%c%c%c%c\n", phone[i].num[0], phone[i].num[1],
               phone[i].num[2], phone[i].num[3], phone[i].num[4],
               phone[i].num[5], phone[i].num[6], phone[i].num[7]);
    }

    int cnt = 1;
    if (n==1){
        printf("%c%c%c%c-%c%c%c%c %d\n", phone[0].num[0], phone[0].num[1],
               phone[0].num[2], phone[0].num[3], phone[0].num[4],
               phone[0].num[5], phone[0].num[6], phone[0].num[7], cnt);
    } else {
        for (int i = 1; i < n; ++i) {
            if (Mystrcpy(phone[i-1].num, phone[i].num))
                cnt++;
            else {
                printf("%c%c%c%c-%c%c%c%c %d\n", phone[i].num[0], phone[i].num[1],
                       phone[i].num[2], phone[i].num[3], phone[i].num[4],
                       phone[i].num[5], phone[i].num[6], phone[i].num[7], cnt);
                cnt = 1;
            }
        }
    }
    return 0;
}