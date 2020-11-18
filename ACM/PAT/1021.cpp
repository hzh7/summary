#include <stdio.h>
#include <cstring>
using namespace std;

int main(){
	char str[1005];
	int ans[10];
	for (int i = 0; i < 10; i++){
		ans[i] = 0;
	}
	scanf("%s", str);
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		ans[str[i] - '0']++;
	}
	for (int i = 0; i < 10; i++){
		if (ans[i] != 0){
			printf("%d:%d\n", i, ans[i]);
		}

	}
	return 0;
}