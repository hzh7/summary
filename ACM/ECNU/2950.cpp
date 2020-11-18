#include <stdio.h>
#include <math.h>
using namespace std;

int main2950(){
	double a; 
	int b;
	scanf("%lf", &a);
	/*if (a >= 0){
		b = floor(a);
	}
	else
	{
		b = ceil(a);

	}*/
	b = (int)a;
	printf("%d\n", b);
	return 0;
}