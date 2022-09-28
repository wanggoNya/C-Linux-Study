#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TBLSIZE 31

typedef struct linked_list 
{
		struct linked_list *next;
		char *hash_key;
		char *data;
} linked_list_t;

typedef struct hash_table 
{
		struct linked_list *head;
		struct linked_list *tail;
		int list_entry;
} hash_table_t;

FILE * fileOpen(void);
hash_table_t * hashTableArrClear(hash_table_t* hash_table_arr);
char ** hashFileRead(char *hash_buf);

int nullCheck(void *string, char *name);
void freeFunc(char **addr);

int hashKeyToAscii(char *hash_key);
int hashKeyToIndex(int hash_key);

void * linkedListAlloc(linked_list_t *linked_list, char **hash);
void * hashTableIndex(hash_table_t * hash_table, linked_list_t * linked_list);
void printHashTable(hash_table_t * hash_table);

void freeHash(hash_table_t * hash_table);
void freeList(linked_list_t * addr);
void freeAll(void *addr);
