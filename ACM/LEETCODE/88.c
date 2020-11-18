#include <stdio.h>
#include <malloc.h>

void merge(int* nums1, int m, int* nums2, int n) {
    int i = 0, j = 0;
    int index = m;
    while (i < index && j < n){
        if(nums2[j] < nums1[i]){
            for (int k = index - 1; k >= i; --k) {
                nums1[k+1] = nums1[k];
            }
            nums1[i] = nums2[j];
            index++;
            j++;
        }
        i++;
    }
    if(j != n){
        for (int k = index; k < m+n; ++k) {
            nums1[k] = nums2[j++];
        }
    }
    for (int l = 0; l < m+n; ++l) {
        printf("%d ",nums1[l]);
    }
}
int main() {
    //printf("Hello, World!\n");
    //int* nums1 = (int*)malloc(sizeof(int*));
    //int* nums2 = (int*)malloc(5);
    int nums1[4] = {1,4};
    int nums2[2] = {2,3};
    merge(nums1, 2, nums2, 2);
    return 0;
}