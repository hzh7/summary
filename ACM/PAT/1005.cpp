#include <stdio.h>
using namespace std;

int main(){
	int n, t;
	scanf("%d", &n);
	int arr[200] = { 0 };
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t);
		if (arr[t] == 1)
			continue;
		arr[t] = 2;
		while (t != 1)
		{
			if (t % 2 == 0){
				t /= 2;
			}
			else
			{
				t = (3 * t + 1) / 2;
			}
			if (arr[t] == 2){
				arr[t] = 1;
				break;
			}
			arr[t] = 1;
		}
	}
	bool isf = true;
	for (int i = 199; i >= 0 ; i--)
	{
		if (arr[i] == 2){
			if (isf){
				printf("%d", i);
				isf = false;
			}
			else
				printf(" %d", i);
		}
	}

	return 0;
}