#include <iostream>
#include <cstring>
//#include <string>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        int lena = a.length();
        int lenb = b.length();
        int k = lena - lenb;
        int carry = 0;
        int temp;
        if (k < 0){
            a.swap(b);
            //strcpy(c,a);
            int t = lena;
            lena = lenb;
            lenb = t;
            k = -k;
        }
        for (int i = 1; i <= lenb; ++i) {
            temp = a[lena - i] + b[lenb - i] - '0' - '0' + carry;
            a[lena - i] = temp % 2 + '0';
            carry = temp / 2;
        }
        for (int i = lenb+1; i <= lena; ++i) {
            temp = a[lena - i] - '0' +carry;
            a[lena - i] = temp % 2 + '0';
            carry = temp / 2;
        }
        if (!carry){
            return a;
        }
        return "1"+ a;
        cout << "hello world!\n";
    }
};
int main() {
    //std::cout << "Hello, World!" << std::endl;
    string a = "1100";
    string b = "100000";
    Solution solution;
    cout << solution.addBinary(a, b) <<endl;

    return 0;
}