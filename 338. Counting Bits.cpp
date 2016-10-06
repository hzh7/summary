/*
Given a non negative integer number num. For every numbers i in the range
0 �� i �� num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)).
But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount 
in c++ or in any other language.
*/
#include<iostream>
#include<vector>
using namespace std;
vector<int> countBits(int num) {
	vector<int> dp(num + 1);

	dp[0] = 0;

	for (int i = 1; i <= num; i++)
	{
		if (i % 2)
			dp[i] = dp[i / 2] + 1;
		else
			dp[i] = dp[i / 2];
	}

	return dp;
	/*fangfa 2
	vector<int> result(num+1, 0); 
    for (int i = 1; i <= num; i++)  
    {  
        result[i] = result[i&(i-1)] + 1;  //�����
    }
    return result;
	*/
}
int main() {
	vector<int>r = countBits(19);
	for (int i = 0; i < 19; i++) {
		cout << r[i] << "  ";
	}
	cout << endl;
	system("pause");
}
