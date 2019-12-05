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
	int d;
	printf("Enter the element to be inserted : ");
	scanf_s("%d", &d);
	int x = d % max;
	node* newnode = (node*)malloc(sizeof(node));
	newnode->x = d;
	newnode->next = NULL;
	if (a[x] == NULL)
		a[x] = newnode;
	else
	{
		node *ptr;
		ptr = a[x];
		int flag = 1;
		while (ptr->next != NULL)
		{
			if (ptr->x == d)
				flag = 0;
			ptr = ptr->next;
		}
		if (ptr->x == d)
			flag = 0;
		if (flag == 1)
			ptr->next = newnode;
		else
			printf("Element already exists !");
	}
}
void search()
{
	printf("Enter the element you want to search :");
	int d;
	scanf_s("%d", &d);
	int x = d % max;
	node* ptr = a[x];
	int flag = 0;
	while (ptr != NULL)
	{
		if (ptr->x == d)
			flag = 1;
		ptr = ptr->next;
	}
	if (flag == 1)
		printf("Element present");
	else
		printf("Element not found");
}
void display()
{
	for (int i = 0; i < max; i++)
	{
		node* ptr = a[i];
		printf("Index %d - ", i);
		while (ptr != NULL)
		{
			printf("%d, ", ptr->x);
			ptr = ptr->next;
		}
		printf("\n");
	}
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