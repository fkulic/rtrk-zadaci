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
    addToEnd(&head, 1);
	addToEnd(&head, 2);
	addToEnd(&head, 3);
    addToEnd(&head, 4);
    addToEnd(&head, 5);
    addToEnd(&head, 6);
	printList(head); 
	
	printFromMiddle(head);

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

void printFromMiddle(struct Node* head) {
	if (head == NULL) {
		printf("Empty list.");
		return;
	}
	
	struct Node* middleNode = head;
	struct Node* fastPtr = head;
		
	// todo  - ne radi kak treba
	while(fastPtr != NULL) {
		if(fastPtr->next == NULL) {
			middleNode = middleNode->prev;
			break;
		}
		fastPtr = fastPtr->next->next;
		middleNode = middleNode->next;
	}
	
	printf("%d\n", middleNode->data);
}


