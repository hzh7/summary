#include <stdio.h>
#include <cstring>
using namespace std;
bool islowful(char date[]){
	int y = (date[0] - '0') * 1000 + (date[1] - '0') * 100
		+ (date[2] - '0') * 10 + (date[3] - '0');
	int m = (date[5] - '0') * 10 + (date[6] - '0');
	int d = (date[8] - '0') * 10 + (date[9] - '0');
	if (y > 2014 || y ==2014 && m > 9 || y == 2014 && m == 9 && d > 6)
		return false;
	if (y < 1814 || y == 1814 && m < 9 || y == 1814 && m == 9 && d < 6)
		return false;
	return true;

}
int main()
{
	int n;
	char name[6];
	char date[12];
	char oldname[6];
	char oldbir[12];
	char youngname[6];
	char youngbir[12];
	scanf("%d", &n);
	int cnt = 0; oldname[0] = 0;
	while (n--){
		scanf("%s %s", name, date);
		if (!islowful(date)){
			continue;
		}
		if (oldname[0] == 0){
			strcpy(oldname, name);
			strcpy(oldbir, date);
			strcpy(youngname, name);
			strcpy(youngbir, date);
		}
		else
		{
			if (strcmp(date, oldbir) < 0){
				strcpy(oldname, name);
				strcpy(oldbir, date);
			}
			if (strcmp(date, youngbir) > 0){
				strcpy(youngname, name);
				strcpy(youngbir, date);
			}
		}
		cnt++;
	}
	if (cnt == 0){
		printf("0");
	}
	else
		printf("%d %s %s",cnt, oldname, youngname);
	return 0;
}

