#include <stdio.h>
#include <stdlib.h>
 
struct Node {
	int data;
	struct Node* next;
};
 
void push(struct Node** head_ref, int new_data);
void printList(struct Node *node);
void splitOddEven(struct Node* list);

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
        
	splitOddEven(head); 
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

void splitOddEven(struct Node* node) {
	
	struct Node* odd = NULL;
	struct Node* even = NULL;

	for(int i=1; node != NULL; i++, node = node->next) {
		if (i & 1) {
			push(&odd, node->data);
		} else {
			push(&even, node->data);
		}
	}
	printf("Odd list: \n");
	printList(odd);
	printf("Even list: \n");
	printList(even);
	
}
