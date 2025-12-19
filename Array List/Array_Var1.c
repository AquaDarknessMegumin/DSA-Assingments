#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} List;

List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);

int main() {
    List L = initialize(L);
    int found;

    L = insertPos(L, 1, 0);
    L = insertPos(L, 3, 1);
//  L = insertPos(L, 2, 2); 
    L = insertPos(L, 5, 2);
//  L = insertPos(L, 4, 2);

 	L = insertPos(L, 10, 3);


//  L = deletePos(L, 1);

     found = locate(L, 5);
     if (found != -1) {
         printf("Data found at position %d!\n", found);
     } else {
         printf("Data NOT found!\n");
     }
//
    L = insertSorted(L, 8);
    display(L);

    return 0;
}

List initialize(List L) {
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int position) {
    int a;

    if (L.count < MAX && position >= 0 && position <= L.count) {
        for (a = L.count - 1; a >= position; a--) {
            L.elem[a + 1] = L.elem[a];
        }
        L.elem[position] = data;
        L.count++;
    } else {
        printf("Invalid position or list full.\n");
    }
    return L;
}

void display(List L) {
    int a;
    for (a = 0; a < L.count; a++) {
        printf("%d | ", L.elem[a]);
    }
    printf("\n");
}

List deletePos(List L, int position) {
    int a;

    if (position >= 0 && position < L.count) {
        for (a = position; a < L.count - 1; a++) {
            L.elem[a] = L.elem[a + 1];
        }
        L.count--;
    } else {
        printf("Invalid position.\n");
    }
    return L;
}

int locate(List L, int data) {
    int a;

    for (a = 0; a < L.count; a++) {
        if (L.elem[a] == data) {
            return a;  
        }
    }
    return -1; 
}

List insertSorted(List L, int data) {
    int a;

    if (L.count >= MAX) {
        printf("List is full.\n");
        return L;
    }

    for (a = L.count - 1; a >= 0 && L.elem[a] > data; a--) {
        L.elem[a + 1] = L.elem[a];
    }
    L.elem[a + 1] = data;
    L.count++;

    return L;
}

