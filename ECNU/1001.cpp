#include <iostream>
#include <cstring>

int main() {
    //std::cout << "Hello, World!" << std::endl;
    char num1[1024];
    char num2[1024];
    int k;
    int sum[1024];
    int temp;
    while (scanf("%s %s",num1,num2)!=EOF){
        int carry = 0;
        k = strlen(num1) - strlen(num2);
        if(k > 0){
            for(int i = strlen(num1) - 1; i >= 0; i--){
                if(i >= k)
                    temp = num1[i] + num2[i - k] + carry - '0' - '0';
                else
                    temp = num1[i] + carry - '0';
                sum[i] = temp % 10;
                carry = temp / 10;
            }
            if(carry == 1){
                printf("1");
            }
            for (int j = 0; j < strlen(num1); ++j) {
                printf("%d", sum[j]);
            }
        }
        else{
            k = -k;
            for(int i = strlen(num2) - 1; i >= 0; i--){
                if(i >= k)
                    temp = num2[i] + num1[i - k] + carry - '0' - '0';
                else
                    temp = num2[i] + carry - '0';
                sum[i] = temp % 10;
                carry = temp / 10;
            }
            if(carry == 1){
                printf("1");
            }
            for (int j = 0; j < strlen(num2); ++j) {
                printf("%d", sum[j]);
            }
        }

        printf("\n");
    }
    return 0;
}