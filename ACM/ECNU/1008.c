#include <stdio.h>
void fun(){
    /*
     * 采用3022的方法时 一直WA，可能是数值过大
     * */
    long long n, cnt;
    int t;
    scanf("%d", &t);
    while (t--){
        scanf("%lld", &n);
        cnt = 0;
        int res = 1;
        for (int i = 2; i <= n; ++i) {
            res *= i;
            while (res % 10 == 0) {
                cnt++;
                res /= 10;
            }
            res %= 100;
        }
        printf("%lld\n", cnt);
    }
}
int main() {
    //计算n的阶乘n！末尾的“0”的个数，可以转换为计算其因式分解中“5”的个数。
    //n！= [5k * 5(k-1) * ... * 10 * 5] * a
    /*
    n<5
    f(n!)=0;
    n>=5
    f(n!)=k+f(k!),k=n/5
    */
    int t, n, cnt;
    scanf("%d", &t);
    while (t--){
        cnt = 0;
        scanf("%d", &n);
        while (n >= 5) {
            cnt += n / 5;
            n /= 5;
        }
        printf("%d\n", cnt);
    }
    return 0;
}