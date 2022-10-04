#include "hashTable.h"


int main(void) 
{
		thread_json_t * tj1;
		tj1 = malloc(sizeof(thread_json_t));
		
		tj1 = jsonReadAlloc(tj1);


		pthread_t * thread = (pthread_t *)malloc(tj1->thread_num * sizeof(pthread_t));

		threadMake(tj1, thread);

		free(thread);
 		freeThreadJson(tj1);
		
		return 0;
}
