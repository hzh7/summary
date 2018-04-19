#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

int main(){
	string s[7] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
	char str1[65];
	char str2[65];
	char str3[65];
	char str4[65];
	scanf("%s %s %s %s", str1, str2, str3, str4);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int len3 = strlen(str3);
	int len4 = strlen(str4);
	int i = 0;
	char day = 0, hour = 0;
	int min = 0;
	while (i<len1 && i<len2)
	{
		if (str1[i] == str2[i] && str1[i] >= 'A' && str1[i] <= 'G'){
			day = str1[i];
			break;
		}
		i++;
	}
	while (i<len1 && i<len2)
	{
		i++;
		if (str1[i] == str2[i] && (str1[i] >= '0'&&str1[i] <= '9' || str1[i] >= 'A'&&str1[i] <= 'N')){
			hour = str1[i];
			break;
		}
	}
	i = 0;
	while (i<len3 && i<len4)
	{
		if ((str3[i] == str4[i]) && (str3[i] >= 'a' && str3[i] <= 'z' || str3[i] >= 'A' && str3[i] <= 'Z')){
			min = i;
			break;
		}
		i++;
	}
	printf("%s", s[day - 'A'].c_str());
	if (hour >= '0' && hour <= '9')
		printf(" %c", hour);
	else
	{
		printf(" %d", hour - 'A' + 10);
	}
	printf(":%02d", min);

	return 0;
}