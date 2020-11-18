#include <stdio.h>
using namespace std;

int main(){
	long long a, b;
	long long d;
	scanf("%lld %lld %lld", &a, &b, &d);
	a = a + b;
	if (a == 0)
		printf("0");
	long long carry = 1;
	while (carry <= a)
	{
		carry *= d;
	}
	carry /= d;
	while (carry)
	{
		long long tmp = a / carry;
		a %= carry;
		carry /= d;
		printf("%lld", tmp);
	}
	return 0;
}