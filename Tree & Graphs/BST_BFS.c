#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *LC;
    struct node *RC;
} Node, *BST;

typedef struct {
    BST q[100];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

void enqueue(Queue *q, BST n) {
    q->q[q->rear++] = n;
}

BST dequeue(Queue *q) {
    return q->q[q->front++];
}

void bfsTraversal(BST root) {
    if (root == NULL) return;

    Queue q;
    initQueue(&q);

    enqueue(&q, root);

    while (!isEmpty(&q)) {
        BST curr = dequeue(&q);
        printf("%d ", curr->data);

        if (curr->LC != NULL)
            enqueue(&q, curr->LC);

        if (curr->RC != NULL)
            enqueue(&q, curr->RC);
    }
}

int main() {
    BST root = malloc(sizeof(Node));
    root->data = 10;
    root->LC = malloc(sizeof(Node));
    root->LC->data = 5;
    root->LC->LC = NULL;
    root->LC->RC = NULL;
    root->RC = malloc(sizeof(Node));
    root->RC->data = 15;
    root->RC->LC = NULL;
    root->RC->RC = NULL;

    bfsTraversal(root);
    return 0;
}

