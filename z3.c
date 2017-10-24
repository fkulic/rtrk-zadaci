#include <stdio.h>
#include <stdlib.h>
 
struct Node {
	int data;
	struct Node* next;
};
 
void push(struct Node** head_ref, int new_data);
void printList(struct Node *node);
void splitByValue(struct Node* list, int value);

int main()
{
	struct Node* head = NULL;
    
	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);	
	printList(head);
        
	splitByValue(head, 2); 
	return 0;
}

void push(struct Node** head_ref, int new_data) {
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));	
	new_node->data = new_data;	
	new_node->next = *head_ref;	
	*head_ref = new_node;
}

void printList(struct Node *node) {
	while (node != NULL) {
		printf("%d  ", node->data);
		node = node->next;
	}
	printf("\n");
}

void splitByValue(struct Node* node, int value) {
	
	struct Node* smaller = NULL;
	struct Node* bigger = NULL;

	while(node != NULL) {
		if (node->data < value) {
			push(&smaller, node->data);
		} else {
			push(&bigger, node->data);
		}
		node = node->next;
	}
	printf("Smaller list: \n");
	printList(smaller);
	printf("Bigger list: \n");
	printList(bigger);
	
}
