#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}Node;

typedef struct{
	Node *head;
	int count;
}List; 



List* initialize(); //done

void empty(List *list);

void insertFirst(List *list, int data); //done

void insertLast(List *list, int data); //done

void insertPos(List *list, int data, int index);  //done
void deleteStart(List *list);  //done
void deleteLast(List *list); //done
void deletePos(List *list, int index); // done
int retrieve(List *list, int index); //done
int locate(List *list, int data); //done
void display(List *list); //done

int main(){
	
	List *L = initialize();
	
	int ret,loc;
	
	insertFirst(L,5);
	insertFirst(L,6);
	insertFirst(L,2);
//	insertFirst(L,7);
//	insertLast(L,7);

//	insertPos(L,7,2);
//	deleteStart(L);
//	deleteLast(L);
//	deletePos(L,1);
	
	ret = retrieve(L,0);
	printf("Data in that index is %d\n",ret);
	
	loc = locate(L,6);
	printf("Data retrieved is %d\n",loc);
	display(L);
	
	return 0;
}
List* initialize(){
	
	List *newList = malloc(sizeof(List));
	
	if (newList == NULL){
		printf("Memory allocation failed");
	} 
	
	newList->head=NULL;
	newList->count=0;
	return newList;
}

void empty(List *list){
	
	Node *current = list->head;
	Node *temp;
	
	while(current!=NULL){
		temp=current;
		current = current->next;
		free(temp);
	}
	list->head=NULL;
	list->count=0;
}

void insertFirst(List *list, int data){
	
	Node *newNode = malloc(sizeof(Node));

	newNode->data=data;
	newNode->next=list->head;
	list->head = newNode;
	list->count++;
}

void display(List *list){
	
	Node *current = list->head;
	
	if(current == NULL){
		printf("List is empty");
		return;
	}
	
	int a;
	
	for(;current!=NULL;){
		
		printf("[%d] -> ",current->data);
		current = current->next;
	}
	printf("NULL");
	
}

void insertLast(List *list, int data){
	
	Node *newNode = malloc(sizeof(Node));
	Node *current;

	
	newNode->data = data;
	newNode->next = NULL;
	
	if (list->head==NULL){
		list->head = newNode;
	} else{
		current = list->head;	
		for(;current->next!=NULL;){
			current = current->next;
		}
		current->next=newNode;
	}
	
	list->count++;
}

void insertPos(List *list, int data, int index){
	
	int pos;
	
	if (index > list->count){
		printf("Index must be valid");
		return;
	}
	
	if (index == 0){
		insertFirst(list,data);
		return;
	}
	
	if(index ==  list->count){
		insertLast (list,data);
		return;
	}
	
	Node *newNode = malloc(sizeof(Node));
	
	newNode->data= data;
	
	Node *current = list->head;
	
	for(pos=0; pos < index -1 ;pos++){
		current = current->next;
	

	}
	newNode->next=current->next;
	current->next=newNode;
	list->count++;

}

void deleteStart(List *list){
	
	Node *current = list->head;
	
	list->head= current->next;
	free(current);
	list->count--;

	
}


void deleteLast(List *list){
	
	int pos;
	if (list->count==1){
		free(list->head);
		list->count--;
		return;
	}
	Node *current = list->head;
	
	for(pos=0;pos<list->count-2;pos++){
		current = current->next;
	}
	free(current->next);
	current->next = NULL;
	list->count--;
}

void deletePos(List *list, int index){
	int pos;
	if (index < 0 || index >= list->count) {
  		printf("Invalid index\n");
    	return;
	}

	if(index ==0){
		deleteStart(list);
		return;
	}
	
	Node *current =list->head;
	
	for(pos=0;pos< index-1;pos++){
		current = current->next;
	}
	Node *temp = current->next;
	current->next = temp->next;
	free(temp);
	list->count--;
	
}

int retrieve(List *list, int index){
	int pos;
  	if (list->head == NULL) {
        printf("List is empty\n");
        return -1;  
    }
    if (index < 0 || index >= list->count) {
        printf("Invalid index\n");
        return -1;
    }
	Node *current = list->head;
	
	for(pos=0;pos <index;pos++){
		
		current = current->next;
	}
	return current->data;
}	


int locate(List *list, int data){
    if (list->head == NULL) {
        printf("List is empty\n");
        return -1;  
    }
    
    Node *current = list->head;
    int index = 0;
    
    for (; current != NULL; current = current->next, index++) {
        if (current->data == data) {
            return index;
        }
    }
    return -1;
}

