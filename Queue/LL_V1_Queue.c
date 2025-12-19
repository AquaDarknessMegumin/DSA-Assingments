#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
	int data;
	struct Node *next;
}Node;

typedef struct Queue{
	Node *front;
	Node *rear;
}Queue;


Queue* initialize();
bool isFull(Queue* q);
bool isEmpty(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int front(Queue* q);
void display(Queue* q);
void freeQueue(Queue *q); // pang free 

// THIS IS VERSION 1 LINKED QUEUE
// THIS IS VERSION 1 LINKED QUEUE
// THIS IS VERSION 1 LINKED QUEUE

int main(){
	
	Queue *Q = initialize();
	
	enqueue(Q,1);
	enqueue(Q,3);
	enqueue(Q,5);
	enqueue(Q,4);
	
	dequeue(Q);
	
	int value = front(Q);
	
	printf("Value at the front is: %d\n",value);
	
	display(Q);
	freeQueue(Q);
	
	return 0;	
}

Queue* initialize(){
	
	Queue *q = malloc(sizeof(Queue));
	if(q == NULL){
		printf("Memory allocatin failed!");
		return NULL;
	}
	
	q->front = NULL;
	q->rear = NULL;
	
	return q;		
}

bool isFull(Queue* q){
	return false;
}

bool isEmpty(Queue* q){
	return q->front == NULL;
}

void enqueue(Queue* q, int value){
	
	Node *newNode = malloc(sizeof(Node));
	
	if (newNode == NULL){
		printf("Memory allocatin failed!");
		return;
	}
	
	newNode->data = value;
	newNode->next = NULL;
	
	if(isEmpty(q)){
		q->front = newNode;
		q->rear = newNode;
	} else{
		q->rear->next = newNode;
	}
	q->rear = newNode;
	
}
int dequeue(Queue* q){
	
	if(isEmpty(q)){
		printf("Queue is empty!");
		return -1;
	}
	
	Node *temp = q->front;
	int value = q->front->data;
	q->front = temp->next;
	
	if(q->front == NULL){
		q->rear = NULL;
	}
	free(temp);
	
	return value;
}

int front(Queue* q){
	
	if(isEmpty(q)){
		printf("Queue is empty!");
		return -1;
	}
	
	return q->front->data;
}

void display(Queue* q){
	
	if(isEmpty(q)){
		printf("Queue is empty");
		return;
	}
	
	Node *temp = q->front;
	while(temp!=NULL){
		printf("%d -> ",temp->data);
		temp = temp->next;
	}
	printf("NULL");
	
}

void freeQueue(Queue *q){
	
	
	while(!isEmpty(q)){
		dequeue(q);
	}
	free(q);
}




