#include<iostream>
#include<string>
//#include<srting>
using namespace std;

	string reverseString(string s) {
		int len = s.size();
		string r;
		for (int i = len - 1; i >= 0; i--) {
			r.push_back(s[i]);
		}
		return r;
	}
void main() {
	string s = "hello";
	string r = reverseString(s);
	int len = r.size();
	for (int i = 0; i < len; i++) {
		cout << r[i];
	}
	system("pause");
}