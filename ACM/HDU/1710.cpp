#include <stdio.h>

using namespace std;

struct Node
{
	Node *left;
	Node *right;
	int data;
};
int arr1[1005];
int arr2[1005];
bool isf = true;
Node *build(Node *T, int p, int s, int e){
	if (T == NULL){
		T = new Node;
		T->left = T->right = NULL;
		T->data = arr1[p];
	}
	int k = 0;
	for (int i = s; i <= e; i++)
	{
		if (arr2[i] == arr1[p]){
			k = i;
			break;
		}
	}
	if (k > s){
		T->left = build(T->left, p + 1, s, k - 1);
	}
	if (k < e){
		T->right = build(T->right, p + k - s + 1, k + 1, e);
	}
	return T;
}
void PostOrd(Node *T){
	if (T == NULL){
		return;
	}
	if (T->left != NULL){
		PostOrd(T->left);
	}
	if (T->right != NULL){
		PostOrd(T->right);
	}
	if (isf){
		printf("%d", T->data);
		isf = false;
	}
	else
	{
		printf(" %d", T->data);
	}
}
int main(){
	int n; 
	while (scanf("%d", &n) != EOF)
	{
		if (n < 1 || n > 1000)
			return 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr1[i]);
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr2[i]);
		}
		isf = true;
		Node *T = NULL;
		T = build(T, 0, 0, n - 1);
		PostOrd(T);
		printf("\n");
	}
	return 0;
}