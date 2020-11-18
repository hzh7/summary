#include <stdio.h>


using namespace std;

int main2970(){
	int t, n, m;
	int cas = 0;
	scanf("%d", &t);
	while (t--){
		scanf("%d %d", &n, &m);
		int a, b;
		a = (4 * n - m) / 2;
		b = (m - 2 * n) / 2;
		if (a < 0 || b < 0 || m % 2 != 0){
			printf("case #%d:\nImpossible\n", cas++);
		}
		else{
			printf("case #%d:\n%d %d\n", cas++, a, b);
		}

	}
	return 0;
}