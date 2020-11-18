#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
bool has(struct TreeNode* ptr, int sum, int k){
    if (ptr == NULL)
        return false;
    if (sum == k + ptr->val && ptr->left == NULL && ptr->right == NULL)
        return true;
    if (has(ptr->left, sum, k + ptr->val) ||
            has(ptr->right, sum, k + ptr->val))
        return true;
    return false;
}
bool hasPathSum(struct TreeNode* root, int sum) {
    if (root == NULL)
        return false;
    return has(root,sum,root->val);
}
int main() {
    printf("Hello, World!\n");
    return 0;
}