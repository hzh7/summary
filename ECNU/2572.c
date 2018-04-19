#include <stdio.h>

void fun1(){
    /*
     * 使用的是插入排序，超时
     * */
    int arr[100000];
    int n, k, t;
    int maxind, ind;
    scanf("%d", &n);
    maxind = 0;
    while (n--){
        scanf("%d", &t);
        ind = maxind;
        for (int i = 0; i < maxind; ++i) {
            if (t < arr[i]){
                ind = i;
                break;
            }
        }
        for (int j = maxind - 1; j >= ind; --j) {
            arr[j+1] = arr[j];
        }
        arr[ind] = t;
        maxind++;
    }
    scanf("%d", &k);
    while (k--){
        scanf("%d", &t);
        printf("%d\n",arr[t-1]);
    }
    /*for (int l = 0; l < maxind; ++l) {
        printf("%d ", arr[l]);
    }*/
}
int main() {
    int arr[100005] = { 0 };
    int arr1[100005];
    int n, k, t;
    int index = 1;
    scanf("%d", &n);
    while (n--){
        scanf("%d", &t);
        arr[t]++;
    }
    for (int i = 0; i < 100005 ; ++i) {
        if(arr[i] != 0){
            for (int j = 0; j < arr[i]; ++j) {
                arr1[index++] = i;
            }
        }
    }
    scanf("%d", &k);
    while (k--){
        scanf("%d", &t);
        printf("%d\n", arr1[t]);
    }
    return 0;
}