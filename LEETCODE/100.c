/*
 * 本地跑有bug，但是放到leetcode上AC了，
 * 可能是我main里面有问题，函数对的应该。
 *
 * */

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL)
        return true;
    if ((p == NULL && q != NULL) || (q == NULL && p != NULL))
        return false;
    if (p->val == q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right))
        return true;
    return false;
}
int main() {
    //printf("Hello, World!\n");
    //struct TreeNode* p;
    struct TreeNode* p = (struct TreeNode*)malloc(sizeof(struct TreeNode*));
    p->val = 1;
    struct TreeNode* ptr = (struct TreeNode*)malloc(sizeof(struct TreeNode*));
    ptr->val = 2;
    p->left = ptr;
    ptr = (struct TreeNode*)malloc(sizeof(struct TreeNode*));
    ptr->val = 3;
    p->right = ptr;
    p->left->left = NULL;
    p->left->right = NULL;
    p->right->left = NULL;
    p->right->right = NULL;
    struct TreeNode* q = (struct TreeNode*)malloc(sizeof(struct TreeNode*));
    q->val = 1;
    ptr = (struct TreeNode*)malloc(sizeof(struct TreeNode*));
    ptr->val = 2;
    q->left = ptr;
    ptr = (struct TreeNode*)malloc(sizeof(struct TreeNode*));
    ptr->val = 3;
    q->right = ptr;
    q->left->left = NULL;
    q->left->right = NULL;
    q->right->left = NULL;
    q->right->right = NULL;
    bool t = isSameTree(p, q);
    printf("%d\n",t);
    return 0;
}