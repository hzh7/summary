#include <stdio.h>
#include <cstring>
#include <string>
using namespace std;

int mainh(){
	char s[105];
	char z[105];
	int n, a, b;
	int cnt;
	scanf("%s", s);
	scanf("%d", &n);
	int len = strlen(s);
	while (n--){
		scanf("%d%d", &a, &b);
		scanf("%s", z);
		int lenz = strlen(z);
		cnt = 0;
		for (int i = a; i <= b+1 - lenz && i <= b; i++)
		{
			bool flag = true;
			int k = i;
			for (int j = 0; j < lenz; j++)
			{
				if (s[k] != z[j] || j > b - a){
					flag = false;
					break;
				}
				k++;
			}
			if (flag){
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
/*
thisisagarbagecompetitionhahaha
5
0 30 a
1 5 is
25 30 hah
6 12 ag
7 12 ag

*/