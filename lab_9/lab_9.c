#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// RecordType
struct RecordType
{
    int id;
    char name;
    int order;
    struct RecordType* next;
    // create a next pointer (for linkedlist structure)
};

// Fill out this structure
struct HashType
{
    struct RecordType* p;// create a pointer to a RecordType
};

// Compute the hash function
int hash(int x)
{
    // hash function is x % tableSize
    int i = x % 23;

    return i;
}

// parses input file to an integer array
int parseData(char* inputFileName, struct RecordType** ppData)
{
    FILE* inFile = fopen(inputFileName, "r");
    int dataSz = 0;
    int i, n;
    char c;
    struct RecordType* pRecord;
    *ppData = NULL;

    if (inFile)
    {
        fscanf(inFile, "%d\n", &dataSz);
        *ppData = (struct RecordType*)malloc(sizeof(struct RecordType) * dataSz);
        // Implement parse data block
        if (*ppData == NULL)
        {
            printf("Cannot allocate memory\n");
            exit(-1);
        }
        for (i = 0; i < dataSz; ++i)
        {
            pRecord = *ppData + i;
            fscanf(inFile, "%d ", &n);
            pRecord->id = n;
            fscanf(inFile, "%c ", &c);
            pRecord->name = c;
            fscanf(inFile, "%d ", &n);
            pRecord->order = n;
            pRecord->next = NULL;
        }

        fclose(inFile);
    }

    return dataSz;
}

// prints the records
void printRecords(struct RecordType pData[], int dataSz)
{
    int i;
    printf("\nRecords:\n");
    for (i = 0; i < dataSz; ++i)
    {
        printf("\t%d %c %d\n", pData[i].id, pData[i].name, pData[i].order);
    }
    printf("\n\n");
}

// insert record into the hash table
void insertRecord(struct HashType* hashTable, struct RecordType* record, int tableSize)
{
    int index;
    index = hash(record->id, tableSize);
    if (hashTable[index].p == NULL) {
        hashTable[index].p = record;
    }
    //handle collition
    else {
        struct RecordType* temp = (hashTable + index)->p;
        //temp->next since first node is occupied (else statement)
        while (temp->next != NULL) {
            temp = temp->next;
        }
        
        temp->next = record;
        temp->next->next = NULL;
    }
}

// display records in the hash structure
// skip the indices which are free
// the output will be in the format:
// index x -> id, name, order -> id, name, order ....
void displayRecordsInHash(struct HashType* hashTable, int tableSize)
{
    int i;
    for (i = 0; i < tableSize; i++) {
        if ((hashTable + i)->p != NULL) {
            struct RecordType* t = (hashTable + i)->p;
            printf("\nIndex %d ", i);

            while (t != NULL) {
                printf("-> %d, %c, %d ", t->id, t->name, t->order);
                t = t->next;
            }

        }
    }
}

int main(void)
{
    struct RecordType* pRecords;
    int recordSz = 0;

    //reads from input file and calculates size of array of structs 
    recordSz = parseData("input_lab_9.txt", &pRecords);
    printRecords(pRecords, recordSz);

    int hashSz = 23;

    struct HashType* hash_table = calloc(hashSz, sizeof(struct HashType));

    int x;
    for (x = 0; x < recordSz; x++) {
        insertRecord(hash_table, &pRecords[x], hashSz);
        
    }

    displayRecordsInHash(hash_table, hashSz);
    // free all the allocated memory
    free(hash_table);
    free(pRecords);

    return 0;
}