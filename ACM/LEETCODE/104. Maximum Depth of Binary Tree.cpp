/*Given a binary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.*/
#include<iostream>
using namespace std;
int max_dep = 0;
/*Definition for a binary tree node.*/
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 void Depth(TreeNode* root, int dep) {
	 int result = 0;
	 if (root == NULL) {
		 if (max_dep < dep)
			 max_dep = dep;
		 return;
	 }
	 Depth(root->left, dep+1);
	 Depth(root->right, dep+1);
 }
//class Solution {
//public:
	int maxDepth(TreeNode* root) {
		//int result=0;
		Depth(root, max_dep);
		return max_dep;
	}
//};
int main() {
	TreeNode* root = NULL;
	int t =maxDepth( root);
	cout << t;
	system("pause");
}