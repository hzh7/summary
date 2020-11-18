#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    //std::cout << "Hello, World!" << std::endl;
    int n;
    float s;
    float t;
    cin >> n;
    while (n != 0){
        if(n < 1 || n > 17)
            return 0;
        if(n <= 3)
            s = (n - 1) * 5 + 1.75;
        if(n > 3)
            s = (n - 3) * 3 + 11.75;
        t = sqrt(s * 2 / 9.8);
        printf("%.3f\n", t);
        //cout << setprecision(4) << t << endl;
        cin >> n;
    }
    return 0;
}