#include<stdio.h>
#include<stdlib.h>
#define max 5
int a[max];
void insert()
{
	
}
void display()
{
	
}
void main()
{
	for (int i = 0; i < max; i++)
		a[i] = -1;
	printf("1. Insert\n2. Display\n3. Exit");
	int n;
	while (1)
	{
		printf("\nEnter your choice : ");
		scanf_s("%d", &n);
		switch (n)
		{
		case 1: 
			insert();
			break;
		case 2: 
			display();
			break;
		case 3:
			exit(0);
		default:
			printf("Wrong choice\n");
		}
	}
}