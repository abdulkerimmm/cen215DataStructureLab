#include<stdio.h>
#include<stdlib.h>
#define max 5
int a[max];
void insert()
{
	int d;
	printf("Enter the value to be entered : ");
	scanf_s("%d", &d);
	int x = d % max;
	if (a[x] == -1)
		a[x] = d;
	else
	{
		int flag = 1, pos;
		for (int i = x; i < max; i++)
		{
			if (a[i] == -1)
			{
				pos = i;
				flag = 0;
				break;
			}
			else if (a[i] == d)
			{
				flag = 2;
				break;
			}
		}
		if (flag == 1)
		{
			for (int i = 0; i < x; i++)
			{
				if (a[i] == -1)
				{
					pos = i;
					flag = 0;
					break;
				}
				else if (a[i] == d)
				{
					flag = 2;
					break;
				}
			}
		}
		if (flag == 1)
			printf("Hash table is full !");
		else if (flag == 2)
			printf("element already exists !");
		else
			a[pos] = d;
	}
}
void display()
{
	for (int i = 0; i < max; i++)
		printf("%d-%d\n", i, a[i]);
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