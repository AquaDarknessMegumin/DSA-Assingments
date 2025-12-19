#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
	int data;
	struct Node *next;
}Node;

typedef struct Stack{
	Node *top;
}Stack;

Stack* initialize();
bool isFull(Stack* s);
bool isEmpty(Stack* s);
void push(Stack* s, int value);
int pop(Stack* s);
int peek(Stack* s);
void display(Stack* s);

void freeStack(Stack* s); //para free

int main(){
	
	
	Stack *S = initialize();
	
    push(S,1);
	push(S,2);
	push(S,5);
	push(S,4);

	pop(S);
	
	int value = peek(S);
	printf("Value at the top is: %d\n",value);

	display(S);
	freeStack(S);
	
}



Stack* initialize(){
	
	Stack *s = malloc(sizeof(Stack));
	if (s == NULL){
		printf("Memory allocation failed");
		return NULL;
	}
	s->top = NULL;
	
	return s;
}

bool isFull(Stack* s){
	return false;
}

bool isEmpty(Stack* s){
	return s->top == NULL;
}

void push(Stack* s, int value){
	
	Node *newNode = malloc(sizeof(Node));
	if (newNode == NULL){
		printf("Memory allocation failed");
		return;
	}
	newNode->data = value;
	newNode->next = s->top;
	s->top = newNode;
	
	
}
int pop(Stack* s){
	
	if (isEmpty(s)){
		printf("Stack is empty");
		return -1;
	}
	
	Node *temp = s->top;
	int value = temp->data;
	s->top = temp->next;
	free(temp);
	
	return value;
}
int peek(Stack* s){
	
	if (isEmpty(s)){
		printf("Stack is empty");
		return -1;
	}
	
	return s->top->data;
}

void display(Stack* s){
	
	if (isEmpty(s)){
		printf("Stack is empty");
		return;
	}
	
	Node *temp = s->top;
	
	while(temp!=NULL){
		printf("%d\n",temp->data);
		temp = temp->next;
	}
	
}
void freeStack(Stack* s){
	
	while(!isEmpty(s)){
		pop(s);
	}
	
	free(s);
}

