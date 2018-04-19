#include <stdio.h>
#include <math.h>
using namespace std;
/*
AC»¹Ã»
*/
int main3081(){
	int d, p, r;
	scanf("%d%d%d", &d, &p, &r);
	double a = log10((double)p / (p - d*r));
	double b = log10((double)r + 1.0);

	//printf("%f\n", a);
	//printf("%f\n", b);

	int m = (double)a / b + 0.5;
	printf("%d", m);
	return 0;
}