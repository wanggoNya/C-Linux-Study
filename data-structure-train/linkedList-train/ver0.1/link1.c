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

static void* addList(void) 
{
		List *l1 = malloc(sizeof(List));	
		l1->size=0;

		return l1;	
}

static void* addNode(List *l1, char *data, Node *node) 
{
		if (l1->size == 0) 
		{
				node = malloc(sizeof(Node));
				l1->head = node;	
				node->data = calloc(LENGTH, sizeof(char));
				strcpy(node->data, data);
				l1->size ++;
				return node;
		}
		else
		{
				node->next = malloc(sizeof(Node)); 
				//backNode = node;
				node = node->next;	
				node->data = calloc(LENGTH, sizeof(char));
				strcpy(node->data, data); 
				l1->size ++;
				return node;
		}
}

static void printNode(List *l1)
{
		int i;
		char *data = calloc(LENGTH, sizeof(char));
		Node *nextNode;
		Node *node;
		for(i = 0; i < l1->size; i ++)
		{
				if (i == 0) 
				{
						data = l1->head->data;
						nextNode = l1->head->next;
				}
				else
				{
						data = nextNode->data;
						node = nextNode->next;
						nextNode = node;
				}
				printf("Node %d, %s\n", i, data);
		}
}

int main(void) 
{ 
		List *l1 = addList();
		int select;
		char *data;
		data = calloc(LENGTH, sizeof(char));
		Node *node;
		while(select != 3) 
		{
				printf("=============linked list world=============\n");	
				printf("1. push \n2. pop \n3. print \n4. exit\n");
				printf("===========================================\n");	
				scanf("%d", &select);

				switch (select) {
						case 1:
								printf("----------push mode----------\n");	
								printf("Enter string : ");
								scanf("%s", data);
								printf("-----------------------------\n");
								node = addNode(l1, data, node);
								break;
						case 2:
								printf("----------pop mode----------\n");	
								printf("Select string number : ");
								printf("----------------------------\n");
								break;
						case 3:
								
								printf("----------print mode----------\n");	
								printNode(l1);
								printf("----------------------------\n");

								break;
						case 4:
								break;
				}
		}

		return 0;
}

