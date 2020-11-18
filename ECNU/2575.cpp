#include <stdio.h>
#include <algorithm>

int arr[18][18];
int ans[20] = { 0 };
int main2575(){
	int t, n;
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				char c;
				scanf("%c", &c);
				if (c == 'Y'){
					arr[i][j] = 1;
				}
				else
				{
					arr[i][j] = 0;
				}
			}
		}
		for (int i = 0; i < n; i++){
			for (int j = i+1; j < n; j++){
				if (arr[i][j] == 1){
					ans[i]++;
					ans[j]++;
				}
			}
		}
		std::sort(ans, ans + n);

	}

	return 0;
}