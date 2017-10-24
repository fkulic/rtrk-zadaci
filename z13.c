#include <stdio.h>
#include <stdlib.h>
 
struct Node {
	int data;
	struct Node* next;
};
 
void push(struct Node** head_ref, int new_data);
void printList(struct Node *node);
void bubbleSort(struct Node** head);
void swap(struct Node** a, struct Node** b);
void merge(struct Node** first, struct Node** second);

int main()
{
    struct Node* first = NULL;
    push(&first, 6);
	push(&first, 1);
	push(&first, 7);
    push(&first, 3);
	printf("First list: ");
	printList(first);    
	
	bubbleSort(&first);
	printf("Sorted: ");
	printList(first);    

	struct Node* second = NULL;
	push(&second, 2);
	push(&second, 8);
	push(&second, 4);
	push(&second, 9);
	push(&second, 5);
	printf("Second list: ");
	printList(second);      

	bubbleSort(&second);
	printf("Sorted: ");
	printList(first);    

	merge(&first, &second);
	bubbleSort(&first);
	printf("Merged and Sorted: ");
	printList(first);

    return 0;
}

void push(struct Node** head_ref, int new_data) {
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));	
	new_node->data = new_data;	
	new_node->next = *head_ref;	
	*head_ref = new_node;
}

void printList(struct Node *node) {
    while (node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
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

void merge(struct Node** first, struct Node** second) {
	struct Node* ptr = *first;
	while(ptr->next != NULL) {
		ptr = ptr->next;
	}

	ptr->next = *second;
}
