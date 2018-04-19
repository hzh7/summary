#include <stdio.h>
#include <cstring>
char ss[105];
char str[105];

bool solve(){
	if (strcmp(ss, "the") == 0 || strcmp(ss, "a") == 0 ||
		strcmp(ss, "an") == 0 || strcmp(ss, "of") == 0 ||
		strcmp(ss, "for") == 0 || strcmp(ss, "and") == 0)
		return false;
	return true;
}
int main2974(){
	int n;
	int cas = 0;
	scanf("%d", &n);
	getchar();
	while (n--){
		gets(str);
		int len = strlen(str);
		int cnt = 0;
		int pos = 0;
		ss[pos] = 0;
		for (int i = 0; i < len; i++)
		{
			if (str[i] == ' '){
				ss[pos] = 0;
				if (solve()){
					cnt++;
				}
				pos = 0;
			}
			else
			{
				if (str[i] <= 'Z')
					ss[pos++] = str[i] + 'a' - 'A';
				else
				{
					ss[pos++] = str[i];
				}
			}
		}
		ss[pos] = 0;
		if (solve() && pos != 0){
			cnt++;
			pos = 0;
		}
		printf("case #%d:\n%d\n", cas++, cnt);
	}
	return 0;
}