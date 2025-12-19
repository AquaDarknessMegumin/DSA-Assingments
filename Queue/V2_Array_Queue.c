#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX 10

typedef struct{
	int items[MAX];
	int front;
	int rear;
	
}Queue;


Queue* initialize();
bool isFull(Queue* q);
bool isEmpty(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int front(Queue* q);
void display(Queue* q);



int main(){
	
	int valFront;
	
	Queue *Q = initialize();
	
	enqueue(Q,1);
	enqueue(Q,3);
	enqueue(Q,2);
	enqueue(Q,5);
	
	dequeue(Q);
	dequeue(Q);

	valFront = front(Q);
	printf("=== VARIATION 2 ====\n");
	printf("The value at the front is %d\n",valFront);
	printf("ITEMS:\n");
	display(Q);

	return 0;	
}


Queue* initialize(){
	
	Queue *q= malloc(sizeof(Queue));
	if(q == NULL){
		printf("Memory allocation failed!");
		exit(1);
	}

	q->front= 1;
	q->rear= 0;
	
	return q;
}

bool isEmpty(Queue* q){
    return (q->front == (q->rear + 1) % MAX);
}

bool isFull(Queue* q){
    return (q->front == (q->rear + 2) % MAX);
}



void enqueue(Queue* q, int value){
	
	if(isFull(q)){
		printf("Queue is full");
		return;
	}

	q->rear = (q->rear + 1) % MAX;
	q->items[q->rear] = value;
}
int dequeue(Queue* q){
	
	if(isEmpty(q)){
		printf("Queue is empty");
		return -1;
	}
	
	int value = q->items[q->front];
	q->front = (q->front + 1) % MAX;
	
	return value;
}

int front(Queue* q){
	
	if(isEmpty(q)){
		printf("Queue is empty");
		return -1;
	}
		
	return q->items[q->front];
}

void display(Queue* q){
	
	int a = q->front;
	
	if(isEmpty(q)){
		printf("Queue is empty");
		return;
	}
	
	while(a != (q->rear + 1) % MAX){
		printf("%d ", q->items[a]);
		a = (a + 1) % MAX; 
		
	}

	
}
