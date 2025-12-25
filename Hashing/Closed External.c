#include <stdio.h>

#define SIZE 10
#define EMPTY -1

int hash(int key) {
    return key % SIZE;
}

void initialize() {
    FILE *fp = fopen("hashtable.dat", "wb");
    int empty = EMPTY;

    for(int i = 0; i < SIZE; i++)
        fwrite(&empty, sizeof(int), 1, fp);

    fclose(fp);
}

void insert(int key) {
    FILE *fp = fopen("hashtable.dat", "rb+");
    int index = hash(key);
    int value;

    for(int i = 0; i < SIZE; i++) {
        fseek(fp, index * sizeof(int), SEEK_SET);
        fread(&value, sizeof(int), 1, fp);

        if(value == EMPTY) {
            fseek(fp, index * sizeof(int), SEEK_SET);
            fwrite(&key, sizeof(int), 1, fp);
            fclose(fp);
            return;
        }

        index = (index + 1) % SIZE;   
    }

    fclose(fp);
}

void search(int key) {
    FILE *fp = fopen("hashtable.dat", "rb");
    int index = hash(key);
    int value;

    for(int i = 0; i < SIZE; i++) {
        fseek(fp, index * sizeof(int), SEEK_SET);
        fread(&value, sizeof(int), 1, fp);

        if(value == key) {
            printf("Found %d\n", key);
            fclose(fp);
            return;
        }

        if(value == EMPTY)
            break;

        index = (index + 1) % SIZE;
    }

    fclose(fp);
    printf("Not Found %d\n", key);
}

int main() {
    initialize();

    insert(10);
    insert(20);
    insert(15);
    insert(25);
    insert(35);

    search(15);
    search(99);

    return 0;
}

