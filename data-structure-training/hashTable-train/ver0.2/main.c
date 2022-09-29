#include "hashTable.h"

int main(void) 
{
		FILE *fp;
		char hash_buf[1024];
		char **hash;
		int hash_key, hash_index;

		linked_list_t *linked_list;	
		hash_table_t hash_table_arr[TBLSIZE];
		hash_table_t * hash_table;

		fp = fileOpen();
		hashTableArrClear(hash_table_arr + 0);

		while (!feof(fp))
		{
				fgets(hash_buf, sizeof(hash_buf), fp);

				hash = hashFileRead(hash_buf);

				hash_buf[0] = '\0';

				if(!nullCheck(hash, "hash")) break;

				linked_list = linkedListAlloc(linked_list, hash);
				
				hash_key = hashKeyToAscii(hash[0]);
				hash_index = hashKeyToIndex(hash_key);	

				hash_table = hash_table_arr + hash_index;
				hash_table = hashTableIndex(hash_table, linked_list);

				if(!nullCheck(hash_table, "hash_table")) return 0;

				freeFunc(hash);
		}

		printHashTable(hash_table_arr);

		freeHash(hash_table_arr);		
		fclose(fp);

		return 0;
}
