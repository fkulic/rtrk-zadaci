#include <stdio.h>
#include <stdlib.h>
 
struct Node {
	int data;
	struct Node* next;
};
 
void add(struct Node** root, int new_data);
void printList(struct Node* head);
void printAndDeleteNth(struct Node** head, int n);

int main()
{
	int n;
	
    struct Node* head = NULL;
    add(&head, 1);
	add(&head, 2);
	add(&head, 3);
    add(&head, 4);
    add(&head, 5);
    add(&head, 6);
    add(&head, 7);
	printList(head); 
	
	printf("Enter number: ");
	scanf("%d", &n); 
	printAndDeleteNth(&head, n);
	printList(head); 

    return 0;
}

void add(struct Node** head, int new_data) {
	if(*head == NULL) {
		*head = (struct Node*) malloc(sizeof(struct Node));
		(*head)->data = new_data;
		(*head)->next = *head;	
	
	} else {
		struct Node* temp = (*head);
		while(temp->next != *head) {
			temp = temp->next;	
		}
		struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));	
		temp->next = new_node;
		new_node->data = new_data;
		new_node->next = *head;
	}	
}

void printList(struct Node* node) {
	if (!node) {
		printf("Empty list.\n");
		return;
	}

	struct Node* head = node;
    do {
        printf("%d  ", node->data);
        node = node->next;
    } while(node != head);
	printf("\n");
}

void printAndDeleteNth(struct Node** head, int n) {
	if (n<1) {		
		printf("Invalid number.\n");
		return;
	}

	struct Node* node = *head;
	if (n == 1) {
		while(node->next != *head) {
			struct Node* temp;
			temp = node;		
			node = node->next;
			printf("%d  ", temp->data);
			free(temp);
		}

	} else {
		for(int i=0; node->next != node; i = (i + 1) % n) {      
			if(i == (n-2)) {
				struct Node* nthNode = node->next;		
				printf("%d  ", nthNode->data);
				node->next = node->next->next;
				free(nthNode);
			} else {		
				node = node->next;		
			}
		}
	}	
	printf("%d\n", node->data);
	free(node);
	*head = NULL;
}

