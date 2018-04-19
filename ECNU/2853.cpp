#include <stdio.h>
#include <algorithm>

int arr1[1005];
int arr2[1005];
int n, m;
bool isf = true;
void U(){
	int i = 0, j = 0;
	printf("{");
	while (i < n && j < m){
		if (arr1[i] < arr2[j]){
			if (isf){
				printf("%d", arr1[i]);
				isf = false;
			}
			else
			{
				printf(",%d", arr1[i]);
			}
			i++;
		}
		else if (arr1[i] > arr2[j]){
			if (isf){
				printf("%d", arr2[j]);
				isf = false;
			}
			else
			{
				printf(",%d", arr2[j]);
			}
			j++;
		}
		else
		{
			if (isf){
				printf("%d", arr1[i]);
				isf = false;
			}
			else
			{
				printf(",%d", arr1[i]);
			}
			i++, j++;
		}
	}
	while (i < n){
		if (isf){
			printf("%d", arr1[i]);
			isf = false;
		}
		else
		{
			printf(",%d", arr1[i]);
		}
		i++;
	}
	while (j < m){
		if (isf){
			printf("%d", arr2[j]);
			isf = false;
		}
		else
		{
			printf(",%d", arr2[j]);
		}
		j++;
	}
	printf("}\n");
	isf = true;
}
void N(){
	int i = 0, j = 0;
	printf("{");
	while (i < n && j < m){
		if (arr1[i] < arr2[j]){
			i++;
		}
		else if (arr1[i] > arr2[j]){
			j++;
		}
		else
		{
			if (isf){
				printf("%d", arr2[j]);
				isf = false;
			}
			else
			{
				printf(",%d", arr2[j]);
			}
			i++; j++;
		}
	}
	isf = true;
	printf("}\n");
}
void chaji(){
	int i = 0, j = 0;
	printf("{");
	while (i < n && j < m){
		if (arr1[i] < arr2[j]){
			if (isf){
				printf("%d", arr1[i]);
				isf = false;
			}
			else
			{
				printf(",%d", arr1[i]);
			}
			i++;
		}
		else if (arr1[i] > arr2[j])
		{
			j++;
		}
		else
		{
			i++; j++;
		}
	}
	while (i < n){
		if (isf){
			printf("%d", arr1[i]);
			isf = false;
		}
		else
		{
			printf(",%d", arr1[i]);
		}
		i++;
	}
	printf("}\n");
	{

	}
}
int main2853(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr1[i]);
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &arr2[i]);
	}
	std::sort(arr1, arr1 + n);
	std::sort(arr2, arr2 + m);
	N();
	U();
	chaji();
	return 0;
}