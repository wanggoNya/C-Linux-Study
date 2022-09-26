#include "hashTable.h"

int main(void) 
{
		FILE *fp;
		fp = fileOpen();

		char hash_buf[1024];
		char **hash;

		linked_list_t *linked_list;	
		//hash_table_t * hash_table_arr = malloc(TBLSIZE * sizeof(hash_table_t));
		hash_table_t hash_table_arr[TBLSIZE];
		hash_table_t * hash_table;

		int i, hash_key, hash_index;

		for(i = 0 ; i < TBLSIZE ; i++)
		{
				(hash_table_arr + i)->head = NULL;
//				printf("size!! %ld\n", sizeof(hash_table_arr[i]));
				(hash_table_arr + i)->tail = NULL;
				(hash_table_arr + i)->list_entry = 0;
		}

		while (!feof(fp))
		{
				fgets(hash_buf, sizeof(hash_buf), fp);

				hash = hashFile(hash_buf);

				hash_buf[0] = '\0';

				if(!hash) break;

				hash_key = hashKeyToAscii(hash[0]);
				hash_index = hashKeyToIndex(hash_key);	

				linked_list = linkedListAlloc(linked_list, hash);

//				printf("linked_list %p\n", linked_list);
//				printf("linked_list %s\n", linked_list->hash_key);
//				printf("linked_list %s\n", linked_list->data);

				hash_table = hash_table_arr + hash_index;
				hash_table = hashTableIndex(hash_table_arr + hash_index, linked_list);

				//printf("hash_key : %d\n", hash_key);
				//printf("index : %d\n", hash_index);
				//printf("hash key main %s\n", hash[0]);
				//printf("hash data main %s\n", hash[1]);

				//printf("\n\n");
				if(!hash_table) return 0;

				freeFunc(hash);
		}

		printHashTable(hash_table_arr);

		freeHash(hash_table_arr);		


		fclose(fp);

		return 0;
}
