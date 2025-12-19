#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void initialize(unsigned char *set);
void insert(unsigned char *set, int element);
void deletes(unsigned char *set, int element);
bool find(unsigned char set, int element);
unsigned char set_union(unsigned char A, unsigned char B);
unsigned char intersection(unsigned char A, unsigned char B);
unsigned char difference(unsigned char A, unsigned char B);
unsigned char symmetric_difference(unsigned char A, unsigned char B);
void display(unsigned char set);
void displayDecimal(unsigned char set);
void displayBinary(unsigned char set);

int main(){
	
	unsigned char setA,setB;
	
	initialize(&setA);
	initialize(&setB);
	
	insert(&setA,1);
	insert(&setA,2);
	insert(&setA,3);
	
	printf("Set A:\n");
	display(setA);
	displayDecimal(setA);
	displayBinary(setA);
	
	
	insert(&setB,2);
	insert(&setB,4);
	insert(&setB,5);
	
	printf("\nSet B:\n");
	display(setB);
	displayDecimal(setB);

	
	printf("\nUnion (A | B):\n");
	display(set_union(setA,setB));
	
	printf("\nIntersectin (A & B):\n");
	display(intersection(setA,setB));
	
	printf("\nDifference (A - B):\n");
	display(difference(setA,setB));
	
	printf("\nSymmetric Difference (A ^ B):\n");
	display(symmetric_difference(setA,setB));
	
	printf("\nFoundd 3 in SET A? %s\n",find(setA,3)? "YES" : "NO");
	printf("Foundd 1 in SET B? %s\n",find(setB,1)? "YES" : "NO");
	
}

void initialize(unsigned char *set){
	
	*set = 0;
	
}


void insert(unsigned char *set, int element){
	
	if(element >= 0 && element < 8){
		unsigned char mask = 1 << element;
		*set |= mask;
	}	
}
void deletes(unsigned char *set, int element){
	
	if(element >= 0 && element < 8){
		unsigned char mask = 1 << element;
		*set &= ~mask;
	}
	
}

bool find(unsigned char set, int element){
	
	if(element >= 0 && element < 8){
		unsigned char mask = 1 << element;
		return (set & mask ) !=0;
	}
	return false;
}
unsigned char set_union(unsigned char A, unsigned char B){
	
	return A | B;
	
}

unsigned char intersection(unsigned char A, unsigned char B){
	
	return A & B;
	
}

unsigned char difference(unsigned char A, unsigned char B){
	
	return A & (~B);

}

unsigned char symmetric_difference(unsigned char A, unsigned char B){
	
	return A ^ B;
	
}


void display(unsigned char set){
	
	int a;
	
	printf("{ ");
	for(a=0;a<8;a++){
		if(set &(1<<a)){
			printf("%d, ",a);
		}
	}
	printf("} \n");
}

void displayDecimal(unsigned char set){
	
	printf("Decimal Value: { %d } \n",set);
}


void displayBinary(unsigned char set){
	
	int a;
	
	for(a=7;a>=0;a--){
		unsigned char mask = 1 << a;

		if(set & mask){
			printf("1");
		} else{
			printf("0");
		}
	}
	printf("\n");
}

