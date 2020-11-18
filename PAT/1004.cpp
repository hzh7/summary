#include <stdio.h>
#include <cstring>

using namespace std;

struct Student
{
	char name[11];
	char sno[11];
	int score;
};
int main(){
	int n;
	scanf("%d", &n);
	Student students;
	Student smax;
	smax.score = 0;
	Student smin;
	smin.score = 100;
	for (int i = 0; i < n; i++)
	{
		scanf("%s %s %d", students.name, students.sno, &students.score);
		if (smax.score < students.score){
			strcpy(smax.name, students.name);
			strcpy(smax.sno, students.sno);
			smax.score = students.score;
		}
		if (smin.score > students.score){
			strcpy(smin.name, students.name);
			strcpy(smin.sno, students.sno);
			smin.score = students.score;
		}
	}
	printf("%s %s\n", smax.name, smax.sno);
	printf("%s %s", smin.name, smin.sno);
	//system("pause");
}