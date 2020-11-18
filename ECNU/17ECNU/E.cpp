#include <stdio.h>
/*
JDG will get takeaways!
LJJ will get takeaways!
*/
int ans[100005] = { 0 };
void slove(){
	ans[1] = 1;
	int k = 1;
	for (int i = 2; i < 100001; i++)
	{
		k = 1;
		while (k*k <= i)
		{
			if (ans[i - k*k] == 0){
				ans[i] = 1;
				break;
			}
			k++;
		}
	}

}
int mainE(){
	int t, n;
	int cnt;
	scanf("%d", &t);
	slove();
	while (t--){
		scanf("%d", &n);
		//printf("%d\n", ans[n]);
		if (ans[n]){
			printf("JDG will get takeaways!\n");
		}
		else
		{
			printf("LJJ will get takeaways!\n");
		}

		/*cnt = 0;
		while (n != 0){
			int i = 1;
			while (i * i <= n){
				i++;
			}
			i--;
			n -= i*i;
			cnt++;
		}
		if (cnt % 2 == 0){
			printf("LJJ will get takeaways!\n");
		}
		else
		{
			printf("JDG will get takeaways!\n");
		}*/
	}
	return 0;
}