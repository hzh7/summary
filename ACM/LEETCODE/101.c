#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
bool isSame(struct TreeNode* l,struct TreeNode* r){
    if (l == NULL && r == NULL){
        return true;
    }
    if ((l == NULL && r != NULL) || (l != NULL && r == NULL)){
        return false;
    }
    if (l->val == r->val && isSame(l->left,r->right)
        && isSame(l->right, r->left)){
        return true;
    }
    return false;
}
bool isSymmetric(struct TreeNode* root) {
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
        return true;
    return isSame(root->left, root->right);
}
int main() {
    printf("Hello, World!\n");
    return 0;
}