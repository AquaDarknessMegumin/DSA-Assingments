#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
	unsigned int field: 8;
}Set;

void initialize(Set *set);
void insert(Set *set, int element);
void deletes(Set *set, int element);
bool find(Set set, int element);
Set unions(Set A, Set B);
Set intersection(Set A, Set B);
Set difference(Set A, Set B);
void display(unsigned char set);
void displayBinary(unsigned char set);
void displayDecimal(unsigned char set);


int main(){
	
	Set setA,setB,setC;
	
	initialize(&setA);
	initialize(&setB);
	
	insert(&setA,1);
	insert(&setA,2);
	insert(&setA,3);
	
	printf("Set A:\n");
	display(setA.field);
	displayDecimal(setA.field);
	displayBinary(setA.field);
	
	insert(&setB,2);
	insert(&setB,4);
	insert(&setB,5);
	
	printf("\nSet B:\n");
	display(setB.field);
	displayDecimal(setB.field);
	displayBinary(setB.field);
	
	printf("\nSet C:");
	printf("\nUnions: (A + B)\n");
	setC = unions(setA,setB);
	display(setC.field);
	
	printf("\nIntersection: (A & B)\n");
	setC = intersection(setA,setB);
	display(setC.field);
	
	printf("\nDifference: (A - B)\n");
	setC = difference(setA,setB);
	display(setC.field);
}

void initialize(Set *set){
	set->field=0;
	
}
void insert(Set *set, int element){
	if(element >= 0 && element < 8){
		unsigned int mask =  1 << element;
		set->field|=mask;
	}
}
void deletes(Set *set, int element){
	if(element >= 0 && element < 8){
		unsigned int mask = 1 << element;
		set->field&=~mask;
	}
}
bool find(Set set, int element){
	if(element >= 0 && element < 8){
		unsigned int mask = 1 << element;
		if(set.field&mask){
			return true;
		}
	}
	return false;
}

Set unions(Set A, Set B){
	Set C;
	C.field = A.field | B.field;
	return C;
}
Set intersection(Set A, Set B){
	Set C;
	C.field = A.field & B.field;
	return C;
}
Set difference(Set A, Set B){
	Set C;
	C.field = A.field & ~(B.field);
	return C;
}

void display(unsigned char set){
	int a;
	printf("{ ");
	for(a=0;a<8;a++){
		if(set &(1<<a)){
			printf("%d, ",a);
		}
	}
	printf(" }\n");
}

void displayDecimal(unsigned char set){
	printf("Decimal value is: { %d }\n",set);
}


void displayBinary(unsigned char set){
	printf("Binary Value: { ");
	int a;
	for(a=7;a>=0;a--){
		unsigned char mask = 1 << a;
		if((set & mask)){
			printf("1");
		}else{
			printf("0");
		}
	}
	printf(" }\n");
}


