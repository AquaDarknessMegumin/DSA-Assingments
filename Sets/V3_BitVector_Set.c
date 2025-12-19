#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 8

typedef bool Set[ARRAY_SIZE];

void initialize(Set set);
void insert(Set set, int element);
void deletes(Set set, int element);
bool find(Set set, int element);
void unions(Set A, Set B, Set C);
void intersection(Set A, Set B, Set C);
void difference(Set A, Set B, Set C);
void display(Set set);
void displayBinary(Set set);
void displayDecimal(Set set);


int main(){
	
	Set setA,setB,setC;
	initialize(setA);
	initialize(setB);
	initialize(setC);
	
	printf("Set A:\n");
	insert(setA,1);
	insert(setA,2);
	insert(setA,3);
	display(setA);
	displayDecimal(setA);
	displayBinary(setA);
	
	printf("\nSet B:\n");
	insert(setB,2);
	insert(setB,4);
	insert(setB,5);
	display(setB);
	displayDecimal(setB);
	displayBinary(setB);
	
	printf("\nSet C:\n");
	printf("\nUnions: (A + B)\n");
	unions(setA,setB,setC);
	display(setC);
	printf("\nIntersection: (A & B)\n");
	intersection(setA,setB,setC);
	display(setC);
	printf("\nDifference: (A - B)\n");
	difference(setA,setB,setC);
	display(setC);
}



void initialize(Set set){
	int a;
	for(a=0;a<8;a++){
		set[a] = false;
	}
}

void insert(Set set, int element){
	if(element > 0 && element < ARRAY_SIZE){
		set[element] = true;
	}
}

void deletes(Set set, int element){
	if(element > 0 &&  element < ARRAY_SIZE){
		set[element] = false;
	}	
}
bool find(Set set, int element){
	return set[element];
}
void unions(Set A, Set B, Set C){
	int a;
	for(a=0;a<ARRAY_SIZE;a++){
		C[a] = A[a] | B[a];
	}
}
void intersection(Set A, Set B, Set C){
	int a;
	for(a=0;a<ARRAY_SIZE;a++){
		C[a] = A[a] & B[a];
	}
}

void difference(Set A, Set B, Set C){
	int a;
	for(a=0;a<ARRAY_SIZE;a++){
		C[a] = A[a] & ~(B[a]);
	}
}

void display(Set set){
	int a;
	printf("{ ");
	for(a=0;a<ARRAY_SIZE;a++){
		if(set[a]){
			printf("%d, ",a);
		}
	}
	printf("} \n");
}
void displayBinary(Set set){
	int a;
	printf("Binary Value: { ");
	for(a=ARRAY_SIZE-1;a>=0;a--){
		printf("%d ",set[a]);
	}
	printf("} \n");
}
void displayDecimal(Set set){
	int a;
	int decimal = 0;
	for(a=0;a<ARRAY_SIZE;a++){
		if(set[a]){
			decimal += (1<<a);
		}
	}
	printf("Decimal value is: { %d }\n",decimal);
}




