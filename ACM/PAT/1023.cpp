#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
	int ans[55];
	int tmp; 
	int pos = 0;
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &tmp);
		while (tmp--){
			ans[pos++] = i;
		}
	}
	sort(ans, ans + pos);
	for (int i = 0; i < pos; i++)
	{
		if (ans[i] != 0){
			printf("%d", ans[i]);
			ans[i] = -1;
			break;
		}
	}
	for (int i = 0; i < pos; i++)
	{
		if (ans[i] != -1){
			printf("%d", ans[i]);
		}
	}
	return 0;
}