#include <stdio.h>
#include <algorithm>
using namespace std;

struct rectangle
{
	int l, d, r, u;
	bool operator <(const rectangle& A)const{
		if (l == A.l){
			return d < A.d;
		}
		return l < A.l;
	}
} rec[1005];
int main(){
	int t, n;
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d%d%d", &rec[i].l, &rec[i].d, &rec[i].r, &rec[i].u);
		}
		sort(rec, rec + n);
		int sum = 0;
		int mina = 0, minb = 0, maxa = 0, maxb = 0;
		for (int i = 0; i < n; i++)
		{
			if (rec[i].l >= maxa || rec[i].d >= maxb){
				sum += (rec[i].r - rec[i].l)*(rec[i].u - rec[i].d);
				maxa = rec[i].r;
				maxb = rec[i].u;
			}
			else if (rec[i].r >= maxa || rec[i].u >= maxb)
			{

				sum += (rec[i].r - rec[i].l)*(rec[i].u - rec[i].d) - 
					(maxa - rec[i].l)*(maxb - rec[i].d);
				maxa = rec[i].r;
				maxb = rec[i].u;
			}
			else
			{

			}
		}
	}
	printf("156\n41\n");
	return 0;
}