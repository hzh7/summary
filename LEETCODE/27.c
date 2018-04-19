#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int newSize = numsSize;
    for (int i = 0; i < newSize; ++i) {
        if(nums[i] == val){
            newSize--;
            for (int j = i; j < newSize; ++j) {
                nums[j] = nums[j + 1];
            }
            i--;
        }
    }
    /*for (int k = 0; k < newSize; ++k) {
        printf("%d ", nums[k]);
    }*/
    //printf("newsize is %d\n", newSize);
    return newSize;
}
int main() {
    //printf("Hello, World!\n");
    int nums[] = {3,2,2,3};
    int val = 3;
    int t = removeElement(nums, 4, val);
    //printf("t is %d\n", t);
    return 0;
}