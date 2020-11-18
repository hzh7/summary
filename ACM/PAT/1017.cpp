#include <stdio.h>
#include <cstring>

using namespace std;

int main(){
	char arr[1005];
	char ans[1005];
	int pos = 0;
	int b;
	scanf("%s %d", arr, &b);
	int len = strlen(arr);
	int q = 0;
	int tmp, carry = 0;
	tmp = arr[0] - '0';
	if (tmp / b > 0)
		ans[pos++] = tmp / b + '0';
	carry = tmp % b;
	for (int i = 1; i < len; i++){
		tmp = carry * 10 + arr[i] - '0';
		ans[pos++] = tmp / b + '0';
		carry = tmp % b;
	}
	ans[pos] = 0;
	if (ans[0] == 0){
		printf("0 %d", carry);
	}
	else{
		printf("%s %d", ans, carry);
	}
	return 0;
}