#include <stdio.h>
#include <algorithm>
using namespace std;
struct MoonPai
{
	float kucun;
	float zongjia;
	float danjia;
	bool operator < (const MoonPai &A)const{
		return danjia > A.danjia;
	}
};
MoonPai moonpai[1005];
int main(){
	int n;
	float m;
	scanf("%d %f", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%f", &moonpai[i].kucun);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%f", &moonpai[i].zongjia);
		moonpai[i].danjia = (float)moonpai[i].zongjia / moonpai[i].kucun;
	}
	sort(moonpai, moonpai + n);
	float sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (m >= moonpai[i].kucun){
			m -= moonpai[i].kucun;
			sum += moonpai[i].zongjia;
		}
		else
		{
			sum += moonpai[i].danjia * m;
			break;
		}
	}
	printf("%.2f\n", sum);
	return 0;
}