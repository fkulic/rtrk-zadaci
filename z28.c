#include <stdio.h>
#include <stdlib.h>

#define rows 8
#define columns 10
 
struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

void enQueue(struct Node** front, int newData);
int deQueue(struct Node* node);
void printList(struct Node* node);
void readImageIntoMatrix(int matrix[][columns], int row, int column);

int main()
{
	struct Node* q = NULL;
	int img[rows][columns];
	enQueue(&q, 1);
	enQueue(&q, 2);
	enQueue(&q, 3);
	enQueue(&q, 4);
	enQueue(&q, 5);
	enQueue(&q, 6);
	printList(q);
	
	deQueue(q);
	deQueue(q);
	deQueue(q);
	printList(q);

	readImageIntoMatrix(img, rows, columns);
	
    return 0;
}

void enQueue(struct Node** front, int newData) {
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = newData;
	newNode->prev = NULL;
	
	if (*front == NULL) {
		newNode->next = NULL;		
		(*front) = newNode;
		
	} else {
		newNode->next = (*front);
		(*front)->prev = newNode;
		(*front) = newNode;	
	}
}

int deQueue(struct Node* node) {
	if (node != NULL) {
		int value;
		struct Node* newLast;
		
		while(node->next != NULL) {
			node = node->next;
		}
		
		value = node->data;
		newLast = node->prev;
		
		free(node);
		newLast->next = NULL;
		
		return value;
	}
	return 0;
}

void printList(struct Node *node) {
	while (node != NULL) {
		printf("%d  ", node->data);
		node = node->next;
	}
	printf("\n");
}

void readImageIntoMatrix(int matrix[][columns], int row, int column) {
	// use fgets() to get one line at a time
	// use sscanf() with strtok to extract integers
	
	FILE* img;
	char line[200];
	img = fopen("image.txt", "r");
	
	if (img) {
		while (fgets(line, 200, img)) {
			puts(line);
		}
		fclose(img);
	}
}

