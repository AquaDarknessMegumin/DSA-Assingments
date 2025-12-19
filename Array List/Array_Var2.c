#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct{
	int elem[MAX];
	int count;
}Etype, *EPtr;

void initialize(EPtr L); 
void insertPos(EPtr L, int data, int position);
void deletePos(EPtr L, int position);

int locate(EPtr L, int data);
int retrieve(EPtr L, int position);
void insertSorted(EPtr L, int data);
void display(EPtr L);
void makeNULL(EPtr L);


int main(){
	
	EPtr L =(EPtr)malloc(sizeof(Etype));
	int found;
	
	initialize(L);
	
	insertPos(L,1,0);
	insertPos(L,3,1);
//	insertPos(L,2,2);
	insertPos(L,5,2);
	
//	insertPos(L,4,2);

	insertPos(L,10,3);
	insertSorted(L,8);

//	deletePos(L,1);
	found = locate(L,5);
	
	if (found != -1){
    printf("Data found at position %d!\n", found);
	} else {
    printf("Data NOT found!\n");
	}
	display(L);
}

void initialize(EPtr L){
	L->count=0;
}

void insertPos(EPtr L, int data, int position){
	int a;
    if(L->count < MAX && position >= 0 && position <= L->count) {
        for(a = L->count - 1; a >= position; a--) {
            L->elem[a + 1] = L->elem[a];
        }
        L->elem[position] = data;
        L->count++;
    } else {
        printf("Invalid position or list full.\n");
    }
}


void display(EPtr L){
	int a;
	for(a=0;a<L->count;a++){
		printf("%d | ",L->elem[a]);
	}
	
}


void deletePos(EPtr L, int position){
    int a = 0;

    if(position >= 0 && position < L->count) {
        for(a = position; a < L->count - 1; a++) {
            L->elem[a] = L->elem[a + 1];
        }
        L->count--;
    } else {
        printf("Invalid position.\n");
    }
}


int locate(EPtr L, int data){
	
	int a=0;
	
	for(a=0;a<L->count;a++){
		if (L->elem[a] == data){
			return a;
		}
	}
	return -1;
}

void insertSorted(EPtr L, int data){
	int a;
	
	if (L->count >= MAX) {
        printf("List is full.\n");
        return;
    }

	
	for(a=L->count-1;a>=0 && L->elem[a] > data;a--){
		L->elem[a+1] = L->elem[a]; 
	} 
	L->elem[a+1] = data;
	L->count++;
}





