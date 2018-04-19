#include <stdio.h>
#include <cstring>
int main1073(){
	char str[1030];
	int len;
	while (scanf("%s", str) != EOF){
		len = strlen(str);
		printf("%d\n", len);
	}
	return 0;
}