#include <stdio.h>
#include <stdlib.h>
 
struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

void addToBeg(struct Node** head, int newData);
void addToEnd(struct Node** head, int newData);
void printList(struct Node* head);
void bubbleSort(struct Node** head);
void swap(struct Node** a, struct Node** b);
void readListFromFile(struct Node** a);

int main()
{
	struct Node* head = NULL;
	
	readListFromFile(&head);
	printList(head);

    return 0;
}

void addToBeg(struct Node** head, int newData) {
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = newData;
	newNode->next = *head;
	newNode->prev = NULL;
	
	(*head)->prev = newNode;
	(*head) = newNode;	
}

void addToEnd(struct Node** head, int newData) {
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	struct Node* temp = *head;
	
	newNode->data = newData;
	newNode->next = NULL;
	
	if(*head == NULL) {
		newNode->prev = NULL;
		*head = newNode;
		
	} else {
		while(temp->next != NULL) {
			temp = temp->next;
		}
		
		temp->next = newNode;
		newNode->prev = temp;		
	} 
}

void printList(struct Node *head) {
	while (head != NULL) {
		printf("%d  ", head->data);
		head = head->next;
	}
	printf("\n");
}

void bubbleSort(struct Node** head) {
	if (head == NULL) {
		return;
	}    

	struct Node* node;
	struct Node* lptr = NULL;
	int swapped;
	

	do {
		swapped = 0;
		node = *head;		
		
		while (node->next != lptr) {
			if (node->data > node->next->data) {
				swap(&node, &(node->next));
				swapped = 1;
			}
			node = node->next;
		}

		lptr = node;

	} while (swapped);
}

void swap(struct Node** a, struct Node** b) {
	int temp = (*a)->data;
	(*a)->data = (*b)->data;
	(*b)->data = temp;
}

void readListFromFile(struct Node** head) {
	int data;
	FILE *file;
	file = fopen("list.txt", "r");
	if (file) {
		while(fscanf(file, "%d", &data) == 1) {			
			addToEnd(head, data);
		}
		fclose(file);
	}
	bubbleSort(head);
}
