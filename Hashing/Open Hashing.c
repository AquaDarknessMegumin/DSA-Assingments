#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct node {
    int key;
    struct node* next;
} Node;

Node* table[SIZE];

int hash(int key) {
    return key % SIZE;
}

void initialize() {
    int i;
    for(i = 0; i < SIZE; i++) {
        table[i] = NULL;
    }
}

void insert(int key) {
    int index = hash(key);
    Node* temp = malloc(sizeof(Node));
    temp->key = key;
    temp->next = table[index];
    table[index] = temp;
}

void delete(int key) {
    int index = hash(key);
    Node* curr = table[index];
    Node* prev = NULL;

    while(curr != NULL && curr->key != key) {
        prev = curr;
        curr = curr->next;
    }

    if(curr != NULL) {
        if(prev == NULL) {
            table[index] = curr->next;
        } else {
            prev->next = curr->next;
        }
        free(curr);
    }
}

void search(int key) {
    int index = hash(key);
    Node* curr = table[index];

    while(curr != NULL) {
        if(curr->key == key) {
            printf("Found %d\n", key);
            return;
        }
        curr = curr->next;
    }
    printf("Not Found %d\n", key);
}

void display() {
    int i;
    for(i = 0; i < SIZE; i++) {
        printf("%d: ", i);
        Node* curr = table[i];
        while(curr != NULL) {
            printf("%d -> ", curr->key);
            curr = curr->next;
        }
        printf("NULL\n");
    }
}

int main() {
    initialize();

    insert(10);
    insert(20);
    insert(15);
    insert(25);
    insert(35);

    display();

    search(15);
    delete(20);

    display();

    return 0;
}

