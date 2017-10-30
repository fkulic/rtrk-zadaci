#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 8
#define COLUMNS 10
 
struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

void enQueue(struct Node** front, int newData);
int deQueue(struct Node** front);
void printList(struct Node* node);
void readImageIntoMatrix(int matrix[][COLUMNS]);
void printMatrix(int matrix[][COLUMNS]);

int main()
{
	struct Node* q = NULL;
	int img[ROWS][COLUMNS];
	
	
	
	enQueue(&q, 1);
	enQueue(&q, 2);
	enQueue(&q, 3);
	enQueue(&q, 4);
	enQueue(&q, 5);
	enQueue(&q, 6);
	printList(q);
	
	deQueue(&q);
	deQueue(&q);
	deQueue(&q);
	printList(q);
	

	readImageIntoMatrix(img);
	printMatrix(img);
	
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

int deQueue(struct Node** front) {
	if (*front != NULL) {
		int value;
		
		if((*front)->next == NULL) {
			printf("One element.");
			value = (*front)->data;
			free(*front);
			*front = NULL;
			return value;
		}
		
		struct Node* node = *front;
		
		while(node->next != NULL) {
			node = node->next;
		}
		
		value = node->data;
		node->prev->next = NULL;		
		free(node);
		
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
void readImageIntoMatrix(int matrix[][COLUMNS]) {
	// use fgets() to get one line at a time
	// use sscanf() with strtok to extract integers
	
	FILE* img;
	char line[200];
	img = fopen("image.txt", "r");
	char *token;
	
	if (img) {
		for (int i = 0; fgets(line, 200, img); i++) {
			token = strtok(line, " ");
			for (int j = 0; token != NULL; j++) {
				sscanf(token, "%d", &matrix[i][j]);
				printf("%d ", matrix[i][j]);
				token = strtok(NULL, " ");
			}
			printf("\n");
			
		}
		fclose(img);
	}
}

void printMatrix(int matrix[][COLUMNS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; i < COLUMNS; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
} 

