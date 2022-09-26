#include "hashTable.h"

int main(void) 
{
		FILE *fp;
		fp = fileOpen();

		char hash_buf[1024];
		char **hash;

		linked_list_t *linked_list;	
		hash_table_t hash_table_arr[TBLSIZE];
		hash_table_t * hash_table;

		int i, hash_key, hash_index;

		for(i = 0 ; i < TBLSIZE ; i++)
		{
				(hash_table_arr + i)->head = NULL;
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

				hash_table = hash_table_arr + hash_index;
				hash_table = hashTableIndex(hash_table_arr + hash_index, linked_list);

				if(!hash_table) return 0;

				freeFunc(hash);
		}

		printHashTable(hash_table_arr);

		freeHash(hash_table_arr);		

		fclose(fp);

		return 0;
}
