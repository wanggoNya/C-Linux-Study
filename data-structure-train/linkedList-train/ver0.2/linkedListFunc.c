#include "linkedList.h"

void* addList(void) 
{
		List *l1 = malloc(sizeof(List));	
		l1->size=0;

		return l1;	
}

void* addNode(List *l1, char *data, Node *node) 
{
		if (l1->size == 0) 
		{
				node = malloc(sizeof(Node));
				l1->head = node;	
				node->data = calloc(LENGTH, sizeof(char));
				strcpy(node->data, data);
		}
		else
		{
				node->next = malloc(sizeof(Node)); 
				node = node->next;	
				node->data = calloc(LENGTH, sizeof(char));
				strcpy(node->data, data); 
		}
		node->next = NULL;
		l1->tail = node;
		l1->size ++;
		return node;
}

void printNode(List *l1)
{
		int i;
		char *data;
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

void freeNode(List *l1)
{
		int cnt = l1->size;
		int i;
		printf("cnt %d\n", cnt);
		Node *nextNode;
		char *nextData;
		if (l1)
		{
				nextNode = l1->head;
				for(i = 0 ; i < cnt ; i++)
				{
						nextData = nextNode->data;
						if (nextData) 
						{
								free(nextData);
								nextData = NULL;
						}
						if(i != (cnt-1)) nextNode = nextNode->next;
								
				}
				while(cnt >= 0)
				{
						nextNode = l1->head;
						for(i = 0 ; i < (cnt-1) ; i++)
						{
								nextNode = nextNode->next;
						}
						if(nextNode) 
						{
								free(nextNode);
								nextNode = NULL;
						}
						cnt--;
				}
		}
}
