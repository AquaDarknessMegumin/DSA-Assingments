#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 4
#define NIL -1

typedef struct {
    int elem;
    int next;
} Cell, HeapSpace[MAX];

typedef struct {
    HeapSpace H;
    int avail;
} VHeap;

typedef int List;

void initialize(VHeap *V);
int allocSpace(VHeap* V);
void deallocSpace(VHeap* V, int index);
void insertFirst(int* L, VHeap* V, int elem);
void insertLast(int* L, VHeap* V, int elem);
void insertSorted(int* L, VHeap* V, int elem);
void delete(int* L, VHeap* V, int elem);
void deleteAllOccurrence(int* L, VHeap* V, int elem);
void display(int L, VHeap V);

int main() {
    VHeap V;
    List L = NIL;

    initialize(&V);

    insertFirst(&L, &V, 10);
    insertLast(&L, &V, 30);
    insertSorted(&L, &V, 20);
    insertSorted(&L, &V, 20);

    display(L, V);

    delete(&L, &V, 20);
    display(L, V);

    deleteAllOccurrence(&L, &V, 20);
    display(L, V);

    return 0;
}

void initialize(VHeap *V){
    int i;
    V->avail = 0;
    for(i = 0; i < MAX - 1; i++){
        V->H[i].next = i + 1;
    }
    V->H[MAX - 1].next = NIL;
}

int allocSpace(VHeap* V){
    int idx = V->avail;
    if(idx != NIL){
        V->avail = V->H[idx].next;
    }
    return idx;
}

void deallocSpace(VHeap* V, int index){
    V->H[index].next = V->avail;
    V->avail = index;
}

void insertFirst(int* L, VHeap* V, int elem){
    int idx = allocSpace(V);
    if(idx != NIL){
        V->H[idx].elem = elem;
        V->H[idx].next = *L;
        *L = idx;
    }
}

void insertLast(int* L, VHeap* V, int elem){
    int idx = allocSpace(V);
    if(idx != NIL){
        V->H[idx].elem = elem;
        V->H[idx].next = NIL;

        if(*L == NIL){
            *L = idx;
        } else {
            int trav = *L;
            while(V->H[trav].next != NIL){
                trav = V->H[trav].next;
            }
            V->H[trav].next = idx;
        }
    }
}

void insertSorted(int* L, VHeap* V, int elem){
    int *trav = L;
    while(*trav != NIL && V->H[*trav].elem < elem){
        trav = &V->H[*trav].next;
    }

    int idx = allocSpace(V);
    if(idx != NIL){
        V->H[idx].elem = elem;
        V->H[idx].next = *trav;
        *trav = idx;
    }
}

void delete(int* L, VHeap* V, int elem){
    int *trav = L;
    while(*trav != NIL && V->H[*trav].elem != elem){
        trav = &V->H[*trav].next;
    }

    if(*trav != NIL){
        int temp = *trav;
        *trav = V->H[temp].next;
        deallocSpace(V, temp);
    }
}

void deleteAllOccurrence(int* L, VHeap* V, int elem){
    int *trav = L;
    while(*trav != NIL){
        if(V->H[*trav].elem == elem){
            int temp = *trav;
            *trav = V->H[temp].next;
            deallocSpace(V, temp);
        } else {
            trav = &V->H[*trav].next;
        }
    }
}

void display(int L, VHeap V){
    int trav = L;
    while(trav != NIL){
        printf("%d ", V.H[trav].elem);
        trav = V.H[trav].next;
    }
    printf("\n");
}

