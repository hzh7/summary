#include <stdio.h>
#include <math.h>

using namespace std;

double area(double n){
	return (n*n - 3.14159265359 * (n / 2.0)*(n / 2.0));
}
int main2985(){
	int t, n, k;
	int cas = 0;
	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &n, &k);
		double a = n*1.0;
		double sum = 0.0;
		while (k--){
			sum += area(a);
			a = a / sqrt(2.0);
		}
		printf("case #%d:\n%.6f\n", cas++, sum);
	}
	return 0;
}