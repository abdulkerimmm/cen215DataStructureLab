#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct data{
	int key;
	int value;
};

struct hashtable_item{
	int flag;
	/*
	 * flag = 0 : data not present
	 * flag = 1 : some data already present
	 * flag = 2 : data was present,but deleted
	*/
	struct data *item;

};

struct hashtable_item *array;
int max = 10;
int size = 0;
int prime = 3;

int hashcode1(int key){
	return (key % max);
}

int hashcode2(int key){
	return (prime - (key % prime));
}

void insert(int key, int value)
{
	int hash1 = hashcode1(key);
	int hash2 = hashcode2(key);

	int index = hash1;

	/* create new data to insert */
	struct data *new_item = (struct data*) malloc(sizeof(struct data));
	new_item->key = key;
	new_item->value = value;

	if (size == max){
		printf("\n Hash Table is full, cannot insert more items \n");
		return;
	}

	/* probing through other array elements */
	while (array[index].flag == 1) {
		if (array[index].item->key == key){
			printf("\n Key already present, hence updating its value \n");
			array[index].item->value = value;
			return;
		}
		index = (index + hash2) % max;
		if (index == hash1){
			printf("\n Add is failed \n");
			return;
		}
		printf("\n probing \n");

	}

	array[index].item = new_item;
	array[index].flag = 1;
	size++;
	printf("\n Key (%d) has been inserted \n", key);

}

/* to remove an element from the array */
void remove_element(int key){
	int hash1 = hashcode1(key);
	int hash2 = hashcode2(key);
	int index = hash1;

	if (size == 0){
		printf("\n Hash Table is empty \n");
		return;
	}

	/* probing through other elements */
	while (array[index].flag != 0){
		if (array[index].flag == 1 && array[index].item->key == key){
			array[index].item = NULL;
			array[index].flag = 2;
			size--;
			printf("\n Key (%d) has been removed \n", key);
			return;
		}
		index = (index + hash2) % max;
		if (index == hash1){
			break;
		}
	}

	printf("\n Key (%d) does not exist \n", key);

}

int size_of_hashtable(){
	return size;
}

/* displays all elements of array */
void display(){
	for (int i = 0; i < max; i++){
		if (array[i].flag != 1)
			printf("\n Array[%d] --> \n", i);
		else
			printf("\n Array[%d] --> Key (%d) Value (%d) \n", i, array[i].item->key, array[i].item->value);
	}
}

/* returns largest prime number less than size of array */
int get_prime(){
	for (int i = max - 1; i >= 1; i--)	{
		int flag = 0;
		for (int j = 2; j <= (int)sqrt(i); j++)		{
			if (i % j == 0)
				flag++;
		}
		if (flag == 0)
			return i;
	}
	return 3;
}

/* initializes array */
void init_array(){
	array = (struct hashtable_item*) malloc(max * sizeof(struct hashtable_item));
	for (int i = 0; i < max; i++){
		array[i].item = NULL;
		array[i].flag = 0;
	}
	prime = get_prime();
}

void main(){
	int choice, key, value, n;

	init_array();
	printf("Implementation of Hash Table in C with Double Hashing.\n\n");
	do {
		printf("MENU: \n1.Insert"
			"\n2.Remove"
			"\n3.Check size"
			"\n4.Display\n");

		scanf("%d", &choice);

		switch (choice){
		case 1:
			printf("Enter key and value:\t");
			scanf("%d %d", &key, &value);
			insert(key, value);
			break;
		case 2:
			printf("Enter the key to delete:");
			scanf("%d", &key);
			remove_element(key);
			break;
		case 3:
			n = size_of_hashtable();
			printf("Size of Hash Table is:%d\n", n);
			break;
		case 4:
			display();
			break;
		default:
			return 0;
		}
	} while (1);
}