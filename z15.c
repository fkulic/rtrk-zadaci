#include <stdio.h>
#include <stdlib.h>

 struct Node {
	int data;
	struct Node* next;
};

void push(struct Node** root, int new_data);
int pop(struct Node** root);
int isEmpty(struct Node* root);
int checkParentheses(char* equation);

int main()
{
	char equation[] = "((2+3)()5*8)(4)";
	printf("Equation: %s\n", equation);
	if (!checkParentheses(equation)) {
		printf("\n***\tInvalid equation!\t***\n");
	}
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

int checkParentheses(char* equation) {
	struct Node* stack = NULL;
	char* a = equation;
	int index;
	while (*a != '\0') {
		
		if (*a == '(') {
			index = a - equation;
			push(&stack, index);
			
		} else if (*a == ')') {
			if (isEmpty(stack)) {
				return 0;
			}
			printf("( -> [%d], ", pop(&stack));
			printf(") -> [%ld]\n", (a-equation));
		}
		a++;
	}
	
	if (!isEmpty(stack)) {	
		return 0;
	}
	
	return 1;
}
