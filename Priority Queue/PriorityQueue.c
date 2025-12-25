#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 

// --- STRUCT DEFINITIONS ---

typedef struct node {
    char name[50];
    char role[50];  
    int priority;   
    struct node* next;
} Node;

typedef struct {
    Node* front;
} PriorityQueue;

// --- FUNCTION PROTOTYPES ---

PriorityQueue* initialize();
void enqueue(PriorityQueue* pq, char* name, char* role);
char* dequeue(PriorityQueue* pq);
bool isGuestInQueue(PriorityQueue* pq, char* targetName);
void findGuestsLike(PriorityQueue* pq, char* roleFragment);
void display(PriorityQueue* pq);

// --- MAIN FUNCTION (TESTING) ---

int main() {
    // 1. Initialize
    printf("Initializing Wedding Guest Queue...\n");
    PriorityQueue* weddingQ = initialize();

    // 2. Enqueue Guests (Simulating arrival)
    // Note: You need to implement logic to auto-assign priority based on role!
    // Priority Rules: Bride/Groom (100) > Family (50) > VIP (20) > Others (1)
    
    printf("\n--- Guests Arriving ---\n");
    enqueue(weddingQ, "John Smith", "Regular Guest");
    enqueue(weddingQ, "Maria Clara", "Mother of Family");
    enqueue(weddingQ, "Alice Guo", "VIP Sponsor");
    enqueue(weddingQ, "Jose Rizal", "Groom"); 
    
    // 3. Display Queue
    display(weddingQ);

    // 4. Test Search
    printf("\n--- Searching for 'Alice Guo' ---\n");
    if (isGuestInQueue(weddingQ, "Alice Guo")) {
        printf("Yes, she is on the list.\n");
    } else {
        printf("Not found.\n");
    }

    printf("\n--- Finding all 'Family' members ---\n");
    findGuestsLike(weddingQ, "Family");

    // 5. Dequeue (Seating)
    printf("\n--- Seating Guests (High Priority First) ---\n");
    
    char* seatedGuest;
    
    seatedGuest = dequeue(weddingQ);
    if (seatedGuest) {
        printf("Seated: %s\n", seatedGuest);
        free(seatedGuest); 
    }

    seatedGuest = dequeue(weddingQ);
    if (seatedGuest) {
        printf("Seated: %s\n", seatedGuest);
        free(seatedGuest);
    }

    display(weddingQ);

    return 0;
}

// --- IMPLEMENT YOUR FUNCTIONS BELOW ---

// 1. Initialize the queue
PriorityQueue* initialize() {
	PriorityQueue *pq=malloc(sizeof(PriorityQueue));
    if(pq == NULL){
    	printf("Memory Allocation Failed");
    	return NULL;
	}
	pq->front = NULL;
    return pq; 
}

// 2. Add guest (Sorted Insert)
void enqueue(PriorityQueue* pq, char* name, char* role) {
    
    Node *newNode = malloc(sizeof(Node));
    strcpy(newNode->name,name);
    strcpy(newNode->role,role);
    newNode->next = NULL;

	if(strcmp(newNode->role,"Bride")==0 || strcmp(newNode->role,"Groom")==0){
		newNode->priority=100;
	}
	else if(strstr(newNode->role,"Family")!=NULL){
		newNode->priority=50;
	}
	else if(strstr(newNode->role,"VIP")!=NULL){
		newNode->priority=20;
	}else{
		newNode->priority=1;
	}
   
	if(pq->front == NULL || newNode->priority > pq->front->priority){
		newNode->next = pq->front;
		pq->front = newNode;
	}else{
		Node *temp = pq->front;
		while(temp->next!=NULL && temp->next->priority >= newNode->priority){
			temp = temp->next;
		}
		newNode->next=temp->next;
		temp->next=newNode;
	}
}

// 3. Remove highest priority guest
char* dequeue(PriorityQueue* pq) {
    if (pq==NULL||pq->front==NULL)return NULL;
    
   
    Node *oldFront = pq->front;
	pq->front = oldFront->next;
    
    char *saved = malloc(strlen(oldFront->name) + 1);
    strcpy(saved,oldFront->name);

    free(oldFront);
    return saved; 
}

// 4. Check if exact name exists
bool isGuestInQueue(PriorityQueue* pq, char* targetName) {
	Node *trav = pq->front;
	while(trav!=NULL){
		if(strcmp(trav->name,targetName)==0){
			return true;
		}
		trav=trav->next;
	}
    return false; 
}

// 5. Find guests with partial role match
void findGuestsLike(PriorityQueue* pq, char* roleFragment) {
	Node *trav = pq->front;
	while(trav!=NULL){
		if(strstr(trav->role,roleFragment)!=NULL){
			printf("%s, %s, %d\n",trav->name,trav->role,trav->priority);
		}
		trav=trav->next;
	}
 
}

// 6. Print the whole list
void display(PriorityQueue* pq) {
	Node *trav = pq->front;
	while(trav!=NULL){
		printf("%s	%s	%d\n",trav->name,trav->role,trav->priority);
		trav=trav->next;
	}

}
