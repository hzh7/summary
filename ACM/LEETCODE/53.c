#include <stdio.h>

int maxSubArray(int* nums, int numsSize) {
    if(numsSize == 1){
        return nums[0];
    }
    int sum = nums[0];
    int temp = 0;
    for (int i = 0; i < numsSize; ++i) {
        temp += nums[i];
        if(temp>sum){
            sum = temp;
        }
        if(temp<0){
            temp = 0;
            //sum = nums[i];
        }
    }
    return sum;
}
int main() {
    //printf("Hello, World!\n");
    int arr[10] = {-2,1,-3,4,-1,2,1,-5,4};
    //int arr[] = {-2,1};
    int t = maxSubArray(arr, 9);
    printf("%d", t);
    return 0;
}