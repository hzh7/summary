#include<iostream>
#include<vector>
using namespace std;

string reverseVowels(string s) {
	string a;
	vector<int> b;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'a' || s[i] == 'e'|| s[i] == 'o' || s[i] == 'u' || s[i] == 'i') {
			a.push_back(s[i]);
			b.push_back(i);
		}
	}

	for (int i = 0; i < a.size(); i++) {
		s[b[i]] = a[a.size()-1 - i];
	}
	return s;
}
void display(string r) {
	for (int i = 0; i < r.size(); i++) {
		cout << r[i];
	}
	cout << endl;
}
int main() {
	string s = "ai";
	string r = reverseVowels(s);
	display(r);
	system("pause");
}