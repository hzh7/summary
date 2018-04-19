#include <stdio.h>
#include <algorithm>
#include <vector>
//int ans[1005][55];
std::vector<int > ans[1005];
bool cmp(std::vector<int > arr1, std::vector<int > arr2){
	int i = 0, j = 0;
	while (arr1[i]!=-1 && arr2[i]!=-1)
	{
		if (arr1[i] > arr2[j])
			return true;
		else if (arr1[i] < arr2[j])
		{
			return false;
		}
		else
		{
			i++; j++;
		}
	}
	return true;
}
int main(){
	int t, n, tmp;
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			int pos = 0;
			while (scanf("%d", &tmp) != EOF){
				
				ans[i].push_back(tmp);
				if (tmp == -1)
					break;
			}
		}
		std::sort(ans, ans + n, cmp);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; ans[i][j] != -1; j++){
				printf("%d ", ans[i][j]);
			}
		}
	}

	return 0;
}