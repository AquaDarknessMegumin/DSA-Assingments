#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define EMPTY -1
#define DELETED -2

int table[SIZE];

int hash(int key) {
    return key % SIZE;
}

void initialize() {
    int i;
    for(i = 0; i < SIZE; i++) {
        table[i] = EMPTY;
    }
}

void insert(int key) {
    int index = hash(key);
    int start = index;

    while(table[index] != EMPTY && table[index] != DELETED) {
        index = (index + 1) % SIZE;
        if(index == start) return;
    }
    table[index] = key;
}

void delete(int key) {
    int index = hash(key);
    int start = index;

    while(table[index] != EMPTY) {
        if(table[index] == key) {
            table[index] = DELETED;
            return;
        }
        index = (index + 1) % SIZE;
        if(index == start) return;
    }
}

void search(int key) {
    int index = hash(key);
    int start = index;

    while(table[index] != EMPTY) {
        if(table[index] == key) {
            printf("Found %d\n", key);
            return;
        }
        index = (index + 1) % SIZE;
        if(index == start) break;
    }
    printf("Not Found %d\n", key);
}

void display() {
    int i;
    for(i = 0; i < SIZE; i++) {
        if(table[i] == EMPTY)
            printf("%d: EMPTY\n", i);
        else if(table[i] == DELETED)
            printf("%d: DELETED\n", i);
        else
            printf("%d: %d\n", i, table[i]);
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

