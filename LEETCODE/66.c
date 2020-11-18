#include <stdio.h>
#include <malloc.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int carry = 1;
    int i;
    int temp;
    for (i = digitsSize-1; i >= 0; --i) {
        temp = digits[i]+carry;
        digits[i] = temp % 10;
        carry = temp / 10;
    }
    *returnSize = digitsSize+carry;
    //printf("returnSize is %d\n",returnSize);
    int* array = (int*)malloc(sizeof(int)*(*returnSize));
    i = 0;
    if(carry){
        array[0] = 1;
        printf("%d",array[0]);
        i = 1;
    }
    for (; i < *returnSize; ++i) {
        array[i] = digits[i-carry];
        printf("%d",array[i]);
    }
    return array;
}
int main() {
    //printf("Hello, World!\n");
    int arr [] = {9,9,9,9,9,9};
    int* retutnSize = (int*)malloc(sizeof(int));
    plusOne(arr, 6, retutnSize);
    printf("\n%d",*retutnSize);
    return 0;
}