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
void printFromMiddle(struct Node* head);

int main()
{
	struct Node* head = NULL;
	printf("Odd number of elements: \n");
	addToBeg(&head, 0);
    addToEnd(&head, 1);
	addToEnd(&head, 2);
	addToEnd(&head, 3);
    addToEnd(&head, 4);
    addToEnd(&head, 5);
    addToEnd(&head, 6);
    addToEnd(&head, 7);
	printList(head);
	printFromMiddle(head);
	
	printf("\n\nEven number of elements: \n");
    addToEnd(&head, 8);
	printList(head);
	printFromMiddle(head);

    return 0;
}

void addToBeg(struct Node** head, int newData) {
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = newData;
	newNode->next = *head;
	newNode->prev = NULL;
	
	if(*head != NULL) {
		(*head)->prev = newNode;
	}
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

void printFromMiddle(struct Node* head) {
	if (head == NULL) {
		printf("Empty list.");
		return;
	}
	
	struct Node* middleNode = head;
	struct Node* fastPtr = head;
	
	
	printf("Print from middle: \n");
		
	// todo  - ne radi kak treba
	while (fastPtr != NULL && fastPtr->next != NULL && fastPtr->next->next != NULL) {
		fastPtr = fastPtr->next->next;
		middleNode = middleNode->next;
	}
	
	fastPtr = middleNode; // fastPtr - left side, middleNode - right side
	printf("%d  ", middleNode->data);
	
	while (middleNode->next != NULL) {
		middleNode = middleNode->next;
		printf("%d  ", middleNode->data);
		if(fastPtr->prev == NULL) {			
			break;
		}
		fastPtr = fastPtr->prev;
		printf("%d  ", fastPtr->data);
	}
}


