#include <iostream>
#include <string>

using namespace std;
int solve(char s){
	int cnt = 0;
	if (s < 0)
		s = -s;
	while (s)
	{
		if (s % 2 == 1){
			cnt++;
		}
		s >>= 1;
	}
	return cnt;
}

int gcd(int a, int b){
	if (b == 0)
		return a;
	return gcd(b, a%b);
}
int main2893(){
	int n;
	scanf("%d", &n);
	string str;
	while (n--){
		cin >> str;
		//printf("%s\n", str);
		int len = str.size();
		int cnt1 = 0, cnt2 = len * 8;
		for (int i = 0; str[i] != '\0'; i++)
		{
			cnt1 += solve(str[i]);
		}
		int t = gcd(cnt1, cnt2);
		printf("%d\n", t);
		printf("%d/%d\n", cnt1 / t, cnt2 / t);
	}
	/*int n;
	char str[125];
	scanf("%d", &n);
	getchar();
	while (n--){
		gets(str);
		//printf("%s\n", str);
		int len = strlen(str);
		int cnt1 = 0, cnt2 = len * 8;
		for (int i = 0; str[i] != '\0'; i++)
		{
			cnt1 += solve(str[i]);
		}
		int t = gcd(cnt1, cnt2);
		//printf("%d", t);
		printf("%d/%d\n", cnt1 / t, cnt2 / t);
	}*/
	return 0;
}