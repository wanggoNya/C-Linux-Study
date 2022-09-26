#include "hashTable.h"

FILE * fileOpen(void)
{
		FILE *fp;

		fp = fopen("hash.csv", "r");

		if (!fp)
		{
				printf("ERROR : file open");
				return 0;			
		}

		return fp;
}

char ** hashFile(char *hash_buf)
{
		char sep[] = ", \n";
		char *hash_key, *hash_data, *temp;
		char **hash; 

		temp = strtok(hash_buf, sep);

		if (!temp) return NULL;

		hash_key = calloc(strlen(temp) + 1, sizeof(char));

		strcpy(hash_key, temp);	

		if (!nullCheck(hash_key, "hash_key")) return NULL;

		temp = strtok(NULL, sep);

		hash_data = calloc(strlen(temp) + 1, sizeof(char));

		strcpy(hash_data, temp);	

		hash = calloc(strlen(hash_buf), sizeof(char *));

		hash[0] = hash_key;
		hash[0][strlen(hash_key)] = '\0';

		hash[1] = hash_data;
		hash[1][strlen(hash_data)] = '\0';

		return hash;
}

int nullCheck(char *string, char *name)
{
		if(!string)
		{
				printf("error! %s is empty\n", name);
				return 0;
		}
		return 1;
}

void freeFunc(char **addr)
{
		if (addr[0])
		{
				free(addr[0]);
				addr[0] = '\0';
		}
		if (addr[1])
		{
				free(addr[1]);
				addr[1] = '\0';
		}
		free(addr);
}

int hashKeyToAscii(char *hash_key)
{
		int i, hash_ascii = 0;	
		for (i = 0; i < (int)strlen(hash_key); i++)
		{
				hash_ascii += hash_key[i];		
		}

		return hash_ascii; 
}

int hashKeyToIndex(int hash_key)
{
		int index = 0;
		index = hash_key % TBLSIZE;

		return index; 
}

void * linkedListAlloc(linked_list_t *linked_list, char **hash)
{
		linked_list = malloc(sizeof(linked_list_t));

		linked_list->hash_key = calloc(strlen(hash[0]) + 1, sizeof(char));

		linked_list->data = calloc(strlen(hash[1]) + 1, sizeof(char));

		char *hash_key = linked_list->hash_key;
		char *data = linked_list->data;

		strncpy(hash_key, hash[0], strlen(hash[0]));
		strncpy(data, hash[1], strlen(hash[1]));

		linked_list->next = NULL;

		return linked_list;
}

void * hashTableIndex(hash_table_t * hash_table, linked_list_t * linked_list)
{
		hash_table->list_entry += 1;

		if (hash_table->list_entry == 1)
		{
				hash_table->head = linked_list; 
				hash_table->head->next = NULL;
				hash_table->tail = linked_list; 
				hash_table->tail->next = NULL;
		}
		else
		{
				hash_table->tail->next = linked_list;
				hash_table->tail = linked_list;
		}

		return hash_table;
}

void printHashTable(hash_table_t * hash_table)
{
		int i, j;
		linked_list_t * linked_list;
		char mark = '*';
		printf("\n\n\033[01m\033[4mHashTable\033[0m\n");
		for(i = 0 ; i < TBLSIZE ; i++)
		{
				
				if (!(hash_table + i)->head) mark = '#';
				else mark = '*';

				printf("%02d | %c |", i, mark); 

				if ((hash_table + i)->head)
				{
						linked_list = (hash_table + i)->head->next;
						if (!linked_list) mark = '#';
						printf(" -----> | %c |", mark);	
						printf("|\033[32m %d \033[0m|", hashKeyToAscii((hash_table + i)->head->hash_key));	
						printf("|\033[32m key : %s \033[0m|", (hash_table + i)->head->hash_key);	
						printf("|\033[31m data : %s \033[0m|", (hash_table + i)->head->data);	
						printf("\n");

						if (!linked_list)
						{
								printf("\t -----> ");	
								printf("|\033[31m NULL \033[0m");	
								printf("\n");
						}

						if ((hash_table + i)->head->next) 
						{
								for(j = 1 ; j < (hash_table + i)->list_entry ; j++)
								{
										if (j == (hash_table + i)->list_entry - 1) mark = '#';
										else mark = '*';
										printf("\t -----> | %c |", mark);	
										printf("|\033[32m %d \033[0m|", hashKeyToAscii(linked_list->hash_key));	
										printf("|\033[32m key : %s \033[0m|", linked_list->hash_key);	
										printf("|\033[31m data : %s \033[0m|", linked_list->data);	
										linked_list = linked_list->next;
										printf("\n");
								}
								if (!linked_list)
								{
										printf("\t -----> ");	
										printf("|\033[31m NULL \033[0m");	
										printf("\n");
								}
						}
				}

				printf("\n");
		}
}

void freeHash(hash_table_t * hash_table)
{
		int i, j;
		linked_list_t *linked_list;
		linked_list_t *temp;

		for(i = 0 ; i < TBLSIZE ; i++)
		{
				if (hash_table + i)
				{
						for(j = 1 ; j <= (hash_table+i)->list_entry ; j++)
						{
								if (j == 1)
								{
										linked_list = (hash_table + i)->head->next;
										freeList((hash_table +i)->head);
										freeAll((hash_table + i)->head);
										temp = linked_list;
								}	
								else
								{
										linked_list = temp;
										temp = linked_list->next;
										freeList(linked_list);
										freeAll(linked_list);	
								}
						}
				}
		}
}

void freeList(linked_list_t * addr)
{
		if(addr->hash_key)
		{
				freeAll(addr->hash_key);
		}
		if(addr->data)
		{
				freeAll(addr->data);
		}
}

void freeAll(void *addr)
{
		if (addr) {
				free(addr);
				addr = NULL;
		}
}
