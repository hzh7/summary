#include <stdio.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
struct Node
{
	Node *left;
	Node *right;
	char data;
};
char arr1[15];
char arr2[15];
Node *build(Node *T, int p){
	if (T == NULL){
		T = new Node;
		T->left = T->right = NULL;
		T->data = p;
	}
	else if (p < T->data){
		T->left = build(T->left, p);
	}
	else if (p > T->data){
		T->right = build(T->right, p);
	}
	return T;
}
bool isSame(Node *T1, Node *T2){
	if (T1 == T2 && T1 == NULL){
		return true;
	}
	if (T1 == NULL && T2 != NULL || T1 != NULL && T2 == NULL){
		return false;
	}
	if (T1->data == T2->data){
		return (isSame(T1->left, T2->left) && isSame(T1->right, T2->right));
	}
	return false;
}
void PerOrd(Node *T){
	if (T == NULL){
		return;
	}
	printf("%c ", T->data);
	if (T->left != NULL){
		PerOrd(T->left);
	}
	if (T->right != NULL){
		PerOrd(T->right);
	}
}
void freedom(Node *node){
	if (node == NULL){
		return;
	}
	freedom(node->left);
	freedom(node->right);
	free(node);
}
int main(){
	int n;
	Node *T1;
	Node *T2;
	while (scanf("%d", &n) != EOF && n != 0)
	{
		T1 = NULL;
		T2 = NULL;
		memset(arr1, 0, sizeof(arr1));
		scanf("%s", arr1);
		int len = strlen(arr1);
		for (int i = 0; i < len; i++)
		{
			T1 = build(T1, arr1[i]);
		}
		for (int i = 0; i < n; i++)
		{
			memset(arr2, 0, sizeof(arr2));
			scanf("%s", arr2);
			len = strlen(arr2);
			T2 = NULL;
			for (int i = 0; i < len; i++)
			{
				T2 = build(T2, arr2[i]);
			}
			if (isSame(T1, T2)){
				printf("YES\n");
				/*PerOrd(T1);
				printf("\n");
				PerOrd(T2);*/
			}
			else
			{
				printf("NO\n");
				/*PerOrd(T1);
				printf("\n");
				PerOrd(T2);*/
			}
			freedom(T2);
		}
	}
	freedom(T1);
	return 0;
}