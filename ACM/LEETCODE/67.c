/*
 * 题号应该是67
 *
 * Input:
 * "1011111111110101010111111100100100011101000010001010001"
 * "1110101001110001001111100010001101011111110111011000101"
 * Output:
 * "11010101001100110100111011110110001111100111001100010110�"
 * Expected:
 * "11010101001100110100111011110110001111100111001100010110"
 *
 * 一直没有AC，为什么最后会有一个乱码呢？
 * */
#include <stdio.h>
#include <string.h>
#include <malloc.h>

char* addBinary(char* a, char* b) {
    int carry = 0;
    int len1 = strlen(a);
    int len2 = strlen(b);
    char* result;
    int k = len1 - len2;
    int t;
    if(k < 0){
        char* t = a;
        a = b;
        b = t;
        k = -k;
        int temp = len1;
        len1 = len2;
        len2 = temp;
    }
    for (int i = 1; i <= len1 - k; ++i) {
        t = a[len1 - i] + b [len2 - i] - '0' - '0' + carry;
        a[len1 - i] = t % 2 + '0';
        carry = t / 2;
    }
    for (int i = len1 - k + 1; i <= len1; ++i) {
        t = a[len1 - i] - '0' + carry;
        a[len1 - i] = t % 2 + '0';
        carry = t / 2;
    }
    if(!carry){
        return a;
    }
    result = (char*)malloc((1+len1)*sizeof(char));
    result[0] = '1';
    //strcat(result,a);
    strcpy(result+1,a);
    result[(1+len1)*sizeof(char)] = '\0';
    return result;
}
int main() {
    //printf("Hello, World!\n");
    char a[100000] = "1011111111110101010111111100100100011101000010001010001";
    char b[100000] = "1110101001110001001111100010001101011111110111011000101";
    //char a[1000] = "111111";
    //char b[1000] = "1";
    printf("%s",addBinary(a, b));

    return 0;
}