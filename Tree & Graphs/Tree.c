#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node* LC;
    struct node* RC;
} Node, *BST;

void insert(BST* B, int value);
void inorder(BST B);
void preorder(BST B);
void postorder(BST B);
BST deleteNode(BST B, int value);

int main(){
    BST B = NULL;

    insert(&B, 50);
    insert(&B, 30);
    insert(&B, 70);
    insert(&B, 20);
    insert(&B, 40);
    insert(&B, 60);
    insert(&B, 80);

    inorder(B);
    printf("\n");

    preorder(B);
    printf("\n");

    postorder(B);
    printf("\n");

    B = deleteNode(B, 50);
    inorder(B);
    printf("\n");

    return 0;
}

void insert(BST* B, int value){
    if(*B == NULL){
        *B = malloc(sizeof(Node));
        (*B)->data = value;
        (*B)->LC = NULL;
        (*B)->RC = NULL;
        return;
    }

    if(value < (*B)->data){
        insert(&(*B)->LC, value);
    } else if(value > (*B)->data){
        insert(&(*B)->RC, value);
    }
}

void inorder(BST B){
    if(B != NULL){
        inorder(B->LC);
        printf("%d ", B->data);
        inorder(B->RC);
    }
}

void preorder(BST B){
    if(B != NULL){
        printf("%d ", B->data);
        preorder(B->LC);
        preorder(B->RC);
    }
}

void postorder(BST B){
    if(B != NULL){
        postorder(B->LC);
        postorder(B->RC);
        printf("%d ", B->data);
    }
}

BST deleteNode(BST B, int value){
    if(B == NULL){
        return NULL;
    }

    if(value < B->data){
        B->LC = deleteNode(B->LC, value);
    } else if(value > B->data){
        B->RC = deleteNode(B->RC, value);
    } else {
        if(B->LC == NULL){
            BST temp = B->RC;
            free(B);
            return temp;
        } else if(B->RC == NULL){
            BST temp = B->LC;
            free(B);
            return temp;
        }

        BST succ = B->RC;
        while(succ->LC != NULL){
            succ = succ->LC;
        }

        B->data = succ->data;
        B->RC = deleteNode(B->RC, succ->data);
    }
    return B;
}

