#include <stdio.h>

int mainB(){
	int t, a, b, c;
	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &a, &b);
		c = a + b;
		if (a == 1){
			printf("LBB made a cup of coffee today.\n");
		}
		else if (a == 0)
		{
			printf("LBB made no coffee today.\n");
		}
		else
		{
			printf("LBB made %d cups of coffee today.\n", a);
		}
		if (b == 1){
			printf("JDG made a cup of coffee today.\n");
		}
		else if (b == 0)
		{
			printf("JDG made no coffee today.\n");
		}
		else
		{
			printf("JDG made %d cups of coffee today.\n", b);
		}
		if (c == 0){
			printf("BOSS had no coffee today.\n");
		}
		else if (c == 1){
			printf("BOSS had a cup of coffee today.\n");
		}
		else{
			printf("BOSS had %d cups of coffee today.\n", c);
		}

	}

	return 0;
}

/*

LBB made a cup of coffee today.
JDG made 2 cups of coffee today.
BOSS had 3 cups of coffee today.
LBB made 2 cups of coffee today.
JDG made no coffee today.
BOSS had 2 cups of coffee today.

*/