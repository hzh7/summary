#include <stdio.h>

int main() {
    //printf("Hello, World!\n");
    int t, a, n, r;
    scanf("%d", &t);
    int cas = 0;
    while (t--){
        scanf("%d %d", &a, &n);
        int arr[100];
        arr[0] = 1;
        int len = 1;
        int carry = 0;
        r = 1;
        for (int i = 0; i < n; ++i) {
            carry = 0;
            for (int j = 0; j < len; ++j) {
                int temp = arr[j]*a;
                arr[j] = (temp + carry)%10;
                carry = (temp + carry)/10;
            }
            if (carry){
                arr[len] = carry;
                len++;
            }
        }
        /*if (arr[len-1] == 0)
            len--;*/
        printf("case #%d:\n", cas);
        for (int k = len-1; k >= 0; --k) {
            printf("%d", arr[k]);
        }
        printf("\n");
        cas++;
    }
    return 0;
}