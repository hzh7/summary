#include <stdio.h>

using namespace std;

int main(){
	int A1 = 0, A2 = 0, A3 = 0, A5 = 0;
	float A4 = 0;
	int C2 = 1;
	int lenA3 = 0;
	int N, t, k;
	int flagA2 = 0;
	int flagA5 = 0;
	scanf("%d", &N);
	while (N--)
	{
		scanf("%d", &t);
		k = t % 5;
		if (k == 0 && t % 2 == 0){
			A1 += t;
		}
		if (k == 1){
			A2 += t*C2;
			C2 *= -1;
			flagA2 = 1;
		}
		if (k == 2){
			A3++;
		}
		if (k == 3){
			A4 += t;
			lenA3++;
		}
		if (k == 4){
			if (A5 < t){
				A5 = t;
			}
			flagA5 = 1;
		}
	}
	if (A1 == 0)
		printf("N");
	else
	{
		printf("%d", A1);
	}
	if (!flagA2)
		printf(" N");
	else
	{
		printf(" %d", A2);
	}
	if (A3 == 0)
		printf(" N");
	else
	{
		printf(" %d", A3);
	}
	if (lenA3 == 0)
		printf(" N");
	else
	{
		printf(" %.1f", A4/lenA3);
	}
	if (flagA5 == 0)
		printf(" N");
	else
	{
		printf(" %d", A5);
	}
	return 0;
}