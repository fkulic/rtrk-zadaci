#include <stdio.h>
#include <stdlib.h>
 
struct Node {
	int data;
	struct Node* next;
};
 
void push(struct Node** root, int new_data);
int pop(struct Node** root);
void printList(struct Node *node);
int isEmpty(struct Node* root);

int main()
{
    struct Node* root = NULL;
    push(&root, 6);
	push(&root, 1);
	push(&root, 7);
    push(&root, 3);
	printList(root);

	pop(&root);
	printList(root);

	push(&root, 5);
	printList(root);    

    return 0;
}

void push(struct Node** root, int new_data) {
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));	
	new_node->data = new_data;	
	new_node->next = *root;	
	*root = new_node;
}

int pop(struct Node** root) {
	if(isEmpty(*root)) {
		return 0;
	}

	struct Node* temp = *root;
	*root = (*root)->next;
	int popped = temp->data;
	free(temp);
	return popped;
}

int isEmpty(struct Node* root) {
	return !root;
}

void printList(struct Node *node) {
    while (node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
    }
	printf("\n");
}

