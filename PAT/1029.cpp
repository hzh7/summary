#include <stdio.h>
#include <cstring>
using namespace std;
int main(){
	char str1[85];
	char str2[85];
	int arr[26] = { 0 };
	int nub[11] = { 0 };
	scanf("%s %s", str1, str2);
	int i = 0, j = 0;
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	while (i < len1 && j < len2)
	{
		if (str1[i] != str2[j]){
			if (str1[i] >= '0' && str1[i] <= '9' && nub[str1[i]-'0'] == 0){
				printf("%c", str1[i]);
				nub[str1[i] - '0'] = 1;
			}
			else if (str1[i] == '_' && nub[10] == 0){
				printf("_");
				nub[10] = 1;
			}
			else if (str1[i] >= 'a' && str1[i] <= 'z' 
				&& nub[str1[i] - 'a'] == 0){
				printf("%c", str1[i]+'A'-'a');
				nub[str1[i] - 'a'] = 1;
			}
			else if (str1[i] >= 'A' && str1[i] <= 'Z'
				&& nub[str1[i] - 'A'] == 0){
				printf("%c", str1[i]);
				nub[str1[i] - 'A'] = 1;
			}
			i++;
		}
		else
		{
			i++; j++;
		}
	}
	while (i < len1){
		if (str1[i] >= '0' && str1[i] <= '9'
			&& nub[str1[i] - '0'] == 0){
			printf("%c", str1[i]);
			nub[str1[i] - '0'] = 1;
		}
		else if (str1[i] == '_' && nub[10] == 0){
			printf("_");
			nub[10] = 1;
		}
		else if (str1[i] >= 'a' && str1[i] <= 'z'
			&& nub[str1[i] - 'a'] == 0){
			printf("%c", str1[i] + 'A' - 'a');
			nub[str1[i] - 'a'] = 1;
		}
		else if (str1[i] >= 'A' && str1[i] <= 'Z'
			&& nub[str1[i] - 'A'] == 0){
			printf("%c", str1[i]);
			nub[str1[i] - 'A'] = 1;
		}
		i++;
	}
	return 0;
}