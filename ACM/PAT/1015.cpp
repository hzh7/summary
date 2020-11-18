#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;
struct Student
{
	char sno[10];
	int de;
	int cai;
	bool operator <(const Student &A) const{
		if ((de + cai) == (A.de + A.cai)){
			if (de == A.de){
				return strcmp(sno, A.sno) < 0;
			}
			return de > A.de;
		}
		return (de + cai) > (A.de + A.cai);
	}
};
Student s1[100005];
Student s2[100005];
Student s3[100005];
Student s4[100005];
int cnt1 = 0;
int cnt2 = 0;
int cnt3 = 0;
int cnt4 = 0;
int main(){
	char str[10] = { 0 };
	int a, b;
	int n, l, h;
	scanf("%d %d %d", &n, &l, &h);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", str);
		scanf("%d %d", &a, &b);
		if (a < l || b < l)
			continue;
		if (a >= h && b >= h)
		{
			strcpy(s1[cnt1].sno, str);
			s1[cnt1].de = a;
			s1[cnt1++].cai = b;
		}
		else if (a >= h && b < h)
		{
			strcpy(s2[cnt2].sno, str);
			s2[cnt2].de = a;
			s2[cnt2++].cai = b;
		}
		else if (a < h && b < h &&a >= b)
		{
			strcpy(s3[cnt3].sno, str);
			s3[cnt3].de = a;
			s3[cnt3++].cai = b;
		}
		else
		{
			strcpy(s4[cnt4].sno, str);
			s4[cnt4].de = a;
			s4[cnt4++].cai = b;
		}
	}	
	sort(s1, s1 + cnt1);
	sort(s2, s2 + cnt2);
	sort(s3, s3 + cnt3);
	sort(s4, s4 + cnt4);
	printf("%d\n", cnt1 + cnt2 + cnt3 + cnt4);
	for (int i = 0; i < cnt1; i++)
	{
		printf("%s", s1[i].sno);
		printf(" %d %d\n", s1[i].de, s1[i].cai);
	}
	for (int i = 0; i < cnt2; i++)
	{
		printf("%s", s2[i].sno);
		printf(" %d %d\n", s2[i].de, s2[i].cai);
	}
	for (int i = 0; i < cnt3; i++)
	{
		printf("%s", s3[i].sno);
		printf(" %d %d\n", s3[i].de, s3[i].cai);
	}
	for (int i = 0; i < cnt4; i++)
	{
		printf("%s", s4[i].sno);
		printf(" %d %d\n", s4[i].de, s4[i].cai);
	}
	return 0;
}