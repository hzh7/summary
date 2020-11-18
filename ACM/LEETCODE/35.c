#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
    for (int i = 0; i < numsSize; ++i) {
        if(nums[i] >= target)
            return i;
    }
    return numsSize;
}
int main() {
    //printf("Hello, World!\n");
    int arr[] = {1,3,5,6};
    int val = 0;
    printf("%d", searchInsert(arr, 4, val));
    return 0;
}