#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int items[MAX];
    int top;  
} Stack;

Stack* initialize();
bool isFull(Stack* s);
bool isEmpty(Stack* s);
void push(Stack* s, int value);
int pop(Stack* s);
int peek(Stack* s);
int top(Stack *s);   
void display(Stack* s);

int main() {
    int topS, peekS, popS;

    Stack *S = initialize();

    push(S, 1);
    push(S, 3);
    push(S, 2);
    push(S, 5);


	printf("=== VARIATION 2 ====\n");
    popS = pop(S);
    printf("Popped value: %d\n", popS);

    peekS = peek(S);
    topS = top(S);

    printf("Value of (peek): %d\n", peekS);
    printf("Top index: %d\n", topS);

	display(S);

    free(S);
    return 0;
}

Stack* initialize() {
    Stack *s = malloc(sizeof(Stack));
    if (s == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    s->top = MAX;   
    return s;
}

bool isFull(Stack* s) {
    return s->top == 0;
}

bool isEmpty(Stack* s) {
    return s->top == MAX;
}

void push(Stack* s, int value) {
    if (isFull(s)) {
        printf("Error: Stack is full! Cannot push %d\n", value);
        return;
    }
    s->top--;  
    s->items[s->top] = value;
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;
    }
    int value = s->items[s->top];
    s->top++;  
    return value;
}

int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->items[s->top];
}

int top(Stack* s) {
    return s->top;  
}

void display(Stack* s) {
	
	int a;
	
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    for (a = s->top; a < MAX; a++) {
        printf("%d\n", s->items[a]);
    }
}

