#include<stdio.h>
#include<stdlib.h>

#define max 5
typedef struct node
{
	int x;
	struct node* next;
}node;
node* a[max];
void insert()
{
	
}
void search()
{
	
}
void display()
{
	
}
void main()
{
	for (int i = 0; i < max; i++)
		a[i] = NULL;
	printf("1. Insert\n2. Search\n3. Display\n4. Exit");
	while (1)
	{
		printf("\nEnter your choice :");
		int ch;
		scanf_s("%d", &ch);
		switch (ch)
		{
		case 1:insert();
			break;
		case 2:search();
			break;
		case 3:display();
			break;
		case 4:exit(1);
		default:printf("Wrong choice\n");
		}
	}
}