// CPP program to implement direct index mapping 
// with negative values allowed. 
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX 1000 

// Since array is global, it is initialized as 0. 
bool has[MAX + 1][2];

// searching if X is Present in the given array or not. 
bool search(int X)
{
	





}

void insert(int a[], int n)
{
	




}

// Driver code 
int main()
{
	int a[] = { -1, 9, -5, -8, -5, -2 };
	int n = sizeof(a) / sizeof(a[0]);
	insert(a, n);
	int X = -5;
	if (search(X) == true)
		printf("Present");
	else
		printf("Not Present");
	return 0;
}
