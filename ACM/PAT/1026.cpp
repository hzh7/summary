#include <stdio.h>

using namespace std;
const int CLK_TCK = 100;
int main(){
	int C1, C2;
	scanf("%d%d", &C1, &C2);
	int c = (int)((float)(C2 - C1) / CLK_TCK + 0.5);
	//printf("c is %d\n", c);
	int h, m, s;
	h = c / 3600;
	c %= 3600;
	m = c / 60;
	s = c % 60;
	printf("%02d:%02d:%02d", h, m, s);
	return 0;
}