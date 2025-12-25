#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int hash(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hash(key);
    char filename[20];

    sprintf(filename, "bucket_%d.txt", index);

    FILE *fp = fopen(filename, "a");
    if(fp == NULL) return;

    fprintf(fp, "%d\n", key);
    fclose(fp);
}

void search(int key) {
    int index = hash(key);
    char filename[20];
    int x;

    sprintf(filename, "bucket_%d.txt", index);

    FILE *fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Not Found %d\n", key);
        return;
    }

    while(fscanf(fp, "%d", &x) != EOF) {
        if(x == key) {
            printf("Found %d\n", key);
            fclose(fp);
            return;
        }
    }

    fclose(fp);
    printf("Not Found %d\n", key);
}

int main() {
    insert(10);
    insert(15);
    insert(20);
    insert(25);
    insert(30);

    search(15);
    search(99);

    return 0;
}

