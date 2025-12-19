#include <stdio.h> 
#include <stdlib.h>

#define LENGTH 10

typedef struct{
	int *elemPtr;
	int count;
	int max;
	
}List;

void initialize(List *L);
void insertPos(List *L, int data, int position);
void deletePos(List *L, int position);
int locate(List *L, int data);

int retrieve(List *L, int position);
void insertSorted(List *L, int data);

void display(List *L);
void resize(List *L);

void makeNULL(List *L);



int main(){
	
	List L;
	int found,ret;
	
	initialize(&L);
	
	insertPos(&L,1,0);
	insertPos(&L,3,1);
//	insertPos(&L,2,2);
	insertPos(&L,5,2);
	
	insertPos(&L,10,3);
	
	insertSorted(&L,8);
	
//	insertPos(&L,4,2);
	
//	deletePos(&L,1);	
	
//	found = locate(&L,5);
//	if (found !=-1){
//		 printf("Data found at position %d!\n", found);
//	} else {
//    printf("Data NOT found!\n");
//	}
	
	ret = retrieve(&L,2);
	
	printf("Data retrieved is %d\n",ret);
	
	
	display(&L);
	
	makeNULL(&L);
}

void initialize(List *L){
	
	L->elemPtr = malloc(sizeof(int) * LENGTH);
	if (L->elemPtr==NULL){
		printf("Memory allocation failed!");
		exit(1);
	}
	
	L->max = LENGTH;
	L->count = 0;
}

void resize(List *L) {
    int *temp = realloc(L->elemPtr, sizeof(int) * 2 * L->max);
    if (temp == NULL) {
        printf("Memory reallocation failed!");
        exit(1);
    }
    L->elemPtr = temp;
    L->max *= 2;
}


void insertPos(List *L, int data, int position) {
	
	int a;
	
    if (position < 0 || position > L->count) {
        printf("Invalid position!\n");
        return;
    }
    if (L->count == L->max) {
        resize(L);
    }
    for (a = L->count - 1; a >= position; a--) {
        L->elemPtr[a + 1] = L->elemPtr[a];
    }
    L->elemPtr[position] = data;
    L->count++;
}

void display(List *L){
	
	int a;
	for(a=0;a<L->count;a++){
		printf("%d | ",L->elemPtr[a]);
	}
}

void deletePos(List *L, int position){
	
	int a;
	
	if (position < 0 || position >= L->count) {
    	printf("Invalid position!\n");
    	return;
	}

	
	for(a=position;a<L->count-1;a++){
		L->elemPtr[a] = L->elemPtr[a+1];
	}
	L->count--;
}

int locate(List *L, int data){
	
	int a;
	
	for(a=0;a<L->count;a++){
		if(L->elemPtr[a]==data){
			return a;
		}
	}
	return -1;
}

int retrieve(List *L, int position) {
	
    if (position < 0 || position >= L->count) {
        printf("Invalid position!\n");
        exit(1);
    }
    return L->elemPtr[position];
}


void insertSorted(List *L, int data){
	int a;
	
	if (L->count == L->max){
		resize(L);
	}
	
	
	for(a=L->count-1; a >=0 && L->elemPtr[a] > data;a--){
		L->elemPtr[a+1] = L->elemPtr[a];
	}
	L->elemPtr[a+1] = data;
	L->count++;
	
}
void makeNULL(List *L){
	
	free(L->elemPtr);
	L->elemPtr = NULL;
    L->count = 0;
    L->max = 0;
	
}
