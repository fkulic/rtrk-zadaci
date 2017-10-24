#include <stdio.h>
#include <stdlib.h>
 
struct Node {
	int data;
	struct Node* next;
};
 
void push(struct Node** head_ref, int new_data);
void printList(struct Node *node);
int detectLoop(struct Node* node);

int main()
{
    struct Node* head = NULL;
    push(&head, 6);
	push(&head, 5);
	push(&head, 4);
    push(&head, 3);
	push(&head, 2);
	push(&head, 1);
    head->next->next->next->next->next = head->next;
 
    detectLoop(head);
    printList(head);
     
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
}

int detectLoop(struct Node* node) {
    struct Node* slow_p = node;
	struct Node* fast_p = node;
 
    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p  = fast_p->next->next;
 
        if (slow_p == fast_p) {
            slow_p->next = NULL;
        }
    }
 
    return 0;
}
