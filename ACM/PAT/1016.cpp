#include <stdio.h>

using namespace std;

int main(){
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int cnt = 0, pa = 0, pb = 0;
	while (a){
		if (a % 10 == b)
			cnt++;
		a /= 10;
	}
	while (cnt--){
		//b += (b * 10);
		pa = pa*10+b;
	}
	cnt = 0;
	while (c){
		if (c % 10 == d)
			cnt++;
		c /= 10;
	}
	while (cnt--){
		pb = pb*10+d;
	}
	printf("%d", pa+pb);

	return 0;
}