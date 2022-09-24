#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#define LENGTH 10

typedef struct node 
{
		char *data;
		struct node *next;
} Node;

typedef struct list 
{
		Node *head;
		Node *tail;
		int size;
} List;

void * addList(void);
void* addNode(List *l1, char *data, Node *node);
void printNode(List *l1);
