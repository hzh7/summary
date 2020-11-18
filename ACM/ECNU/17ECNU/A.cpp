#include <stdio.h>

int mainA(){
	int t, n;
	int cnt = 0;
	scanf("%d", &t);
	while (t--){
		cnt = 0;
		int tmp;
		scanf("%d", &n);
		while (n--){
			scanf("%d", &tmp);
			if (tmp <= 10)
				cnt++;
		}
		printf("%d\n", cnt);
	}

	return 0;
}