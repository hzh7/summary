/*Given an array of integers, every element appears twice except for one. Find that single one.
Note:
Your algorithm should have a linear runtime complexityx线性时间复杂度. Could you implement it without using extra memory?*/

#include<iostream>
#include<vector>
using namespace std;

//class Solution {
//public:
	int singleNumber(vector<int>& nums) {
		int result;
		/***************  Time Limit Exceeded  ****************/
		/*for (int i = 0; i < nums.size(); i++) {
			for (int j = i; j < nums.size(); j++) {
				if(nums[i]>nums[j]){
					int temp = nums[i];
					nums[i] = nums[j];
					nums[j] = temp;
				}
			}
			for (int i = 0; i < nums.size(); i++) {
				if (nums[0] != nums[1]){
					result = nums[0]; 
					break;
				}
				if (nums[int(nums.size()) - 1] != nums[int(nums.size()) - 2]) {
					result = nums[int(nums.size()) - 1];
					break;
				}
				if (nums[i] != nums[i + 1]) {
					result = nums[i + 1];
					break;
				}
			}
			
		}
		/*******************************************************************************/
		//使用异或运算
		int n1 = 0;
		for (int i = 0; i<nums.size(); ++i)
		{
			n1 ^= nums[i];
		}
		return n1;
		return result;
	}
//};
int main() {
	vector<int> nums = { 12,5,5,8,9,12,9,7,6,7,8 };
	int r = singleNumber(nums);
	cout << r << endl;
	system("pause");
}