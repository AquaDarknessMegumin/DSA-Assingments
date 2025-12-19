#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct{
	int *elemPtr;
	int count;
	int max;
}List;

List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);

int locate(List L, int data);
List  insertSorted(List L, int data);
void display(List L);
List resize(List L);


int main(){
	
	int found;
	List L;
	
	L =initialize(L);
	
	
	L = insertPos(L,1,0);
	L = insertPos(L,3,1);
//	L = insertPos(L,2,2);
	L = insertPos(L,5,2);
//	L = insertPos(L,4,3);

//	L = deletePos(L,1);	

	L = insertPos(L,10,3);
	L = insertSorted(L,8);
//	
	found = locate(L,5);
	if (found !=-1){
		 printf("Data found at position %d!\n", found);
	} else {
    printf("Data NOT found!\n");
	}

	display(L);
}

List initialize(List L){
    L.count = 0;
    L.max = LENGTH;
  	L.elemPtr = malloc(sizeof(int)* LENGTH);
  	if (L.elemPtr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    return L;
}

List insertPos(List L, int data, int position){
	
	int a;
	
	if (L.count >= L.max) {
        L = resize(L);
    }
	if(position<=L.count){
		for(a=L.count-1;a>=position;a--){ 
			L.elemPtr[a+1]=L.elemPtr[a];
		}
	}
	L.elemPtr[position]=data;
	L.count++;
	
	return L;
}


List resize(List L){
	
	int *temp = realloc(L.elemPtr,sizeof(int) * 2 * L.max);
	 if (temp == NULL) {
        printf("Resize failed.\n");
        free(L.elemPtr);
        exit(1);
    }
	L.elemPtr = temp;
	L.max *= 2;
	
	return L;
}


void display(List L){
		
	int a;
	
	for(a=0;a<L.count;a++){
		printf("%d | ",L.elemPtr[a]);
	}
	
}


List deletePos(List L, int position){
	int a;
	
	if (position < 0 || position >= L.count) {
   		printf("Invalid position!\n");
   		return L;
	}

	for (a=position;a<L.count-1;a++){
		L.elemPtr[a] = L.elemPtr [a+1];
	}
	L.count--;
	return L;
}

int locate(List L, int data){
	
	int a;
	
	for(a=0;a<L.count;a++){
		if(L.elemPtr[a]==data){
			return a;
		}
	}
	
	return -1;
}

List  insertSorted(List L, int data){
	
	int a;
	
	if (L.count >= L.max){
		L = resize(L);
	}
	
	
	for(a=L.count-1;a>=0 && L.elemPtr[a] > data ;a--){
		L.elemPtr[a+1]=L.elemPtr[a];
	}
	L.elemPtr[a+1] = data;
	L.count++;

return L;
}



