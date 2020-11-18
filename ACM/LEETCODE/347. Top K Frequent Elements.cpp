/*Given a non - empty array of integers, return the k most frequent elements.

For example,
Given[1, 1, 1, 2, 2, 3] and k = 2, return[1, 2].

Note:
You may assume k is always valid, 1 ¡Ü k ¡Ü number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
vector<int> topKFrequent(vector<int>& nums, int k) {
	/*vector<int> result;
	int len = nums.size();
	for (int i = 0; i < len; i++) {

	}*/
	unordered_map<int, int> hash;
	vector<int> result;
	for (auto val : nums) hash[val]++;
	priority_queue<pair<int, int>> que;
	for (auto val : hash) que.push(make_pair(val.second, val.first));
	while (k--)
	{
		auto val = que.top();
		result.push_back(val.second);
		que.pop();
	}
	return result;
}
void display(vector<int> result) {
	cout << "[";
	for (int i = 0; i < result.size() - 1; i++) {
		cout << result[i] << ",";
	}
	cout << result[result.size() - 1] << "]" << endl;
}
int main() {
	vector<int> num = { 1, 1, 1, 2, 2, 3 };
	int k = 2;
	vector<int> result = topKFrequent(num, k);
	display(result);
	system("pause");
}