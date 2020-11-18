#include <stdio.h>

using namespace std;

int arr1[350];
int arr2[350];
int n;
bool isOnly = true;
bool isf = true;
struct Node
{
	Node *left;
	Node *right;
	int c;
};

Node *build(Node *T, int p, int s, int e){
	if (p >= n){
		return T;
	}
	if (T == NULL){
		T = new Node();
		T->left = NULL;
		T->right = NULL;
		T->c = arr1[p];
	}
	if (s == n - 1 || e == 0 || e-s == 0)
		return T;
	if (arr1[p + 1] == arr2[e - 1]){
		isOnly = false;
	}
	int k = 0;
	for (int i = s; i <= e; i++)
	{
		if (arr1[p + 1] == arr2[i]){
			k = i; 
			break;
		}
	}
	T->left = build(T->left, p + 1, s, k);
	T->right = build(T->right, p + k - s + 2, k + 1, e - 1);
	return T;
}
void inOrd(Node *T){
	if (T->left != NULL){
		inOrd(T->left);
	}
	if (isf){
		printf("%d", T->c);
		isf = false;
	}
	else
	{
		printf(" %d", T->c);
	}
	if (T->right != NULL){
		inOrd(T->right);
	}
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr1[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr2[i]);
	}
	Node *T = NULL;
	T = build(T, 0, 0, n-1);
	if (isOnly){
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	inOrd(T);
	printf("\n");
	return 0;
}