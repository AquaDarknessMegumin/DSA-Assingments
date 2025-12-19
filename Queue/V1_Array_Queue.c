#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX 10

typedef struct{
	int items[MAX];
	int count;
	
}List;

typedef struct{
	List list;
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
	enqueue(Q,2);
	enqueue(Q,3);
	enqueue(Q,4);
	
	dequeue(Q);
	dequeue(Q);

	valFront = front(Q);
	printf("=== VARIATION 1 ====\n");
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
	q->list.count=0;
	q->front=-1;
	q->rear=-1;
	
	return q;
}

bool isFull(Queue* q){
	return q->list.count == MAX;
}

bool isEmpty(Queue* q){
	return q->list.count == 0;
}

void enqueue(Queue* q, int value){
	
	if(isFull(q)){
		printf("Queue is full");
		return;
	}

	if (isEmpty(q)){
		q->front=0;
		q->rear=0;
	} else{
		q->rear = (q->rear + 1) % MAX;
	}
	
	q->list.items[q->rear] = value;
	q->list.count++;
}
int dequeue(Queue* q){
	
	if(isEmpty(q)){
		printf("Queue is empty");
		return -1;
	}
	
	int value = q->list.items[q->front];
	
	if (q->list.count == 1){
		q->front = -1;
		q->rear = -1;
	} else{
		q->front = (q->front + 1) % MAX;
	}
	
	q->list.count--;
	
	return value;
	
}
int front(Queue* q){
	
	if(isEmpty(q)){
		printf("Queue is empty");
		return -1;
	}
	
	return q->list.items[q->front];
}

void display(Queue* q){
	
	int a,idx=0;
	
	if(isEmpty(q)){
		printf("Queue is empty");
		return;
	}
	
	for(a=0; a < q->list.count; a++){
		idx = (q->front + a) % MAX;
		
		printf("%d ",q->list.items[idx]);
	}
	
	
	
}
