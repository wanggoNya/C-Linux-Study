#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 64 

typedef struct {
		char **data;
		int front;
		int rear;
} queue;


static void enqueue(queue *q1, char * data) { 
		if (((q1->rear + 1) % MAXSIZE ) == q1->front ) // full queue 
		{
				q1->rear = 0; // reset rear value
		}

		int rearPtr = (*q1).rear;
		char *dataPtr = *(*q1).data + (rearPtr + 1);
		dataPtr = (char *)calloc(MAXSIZE, sizeof(char));// malloc length of data
		printf("rearPtr : %d\n", rearPtr);
		strncpy(dataPtr, data, strlen(data)); // push data to data of queue
		dataPtr[strlen(data)] = '\0'; // reset value of end digit
		printf("check enqueue dataPtr : %p\n\n\n", dataPtr);	
		printf("check enqueue dataPtr : %s\n\n\n", dataPtr);	
		printf("check 2 :%p\n", *(*q1).data + (*q1).rear); 
		q1->rear++; // increase rear value 
}

static int queueIsEmpty(queue * q1) {
		// check queue is null
		int i;
		char *dataPtr = *(*q1).data;
		for (i = 1 ; i < MAXSIZE ; i++)
		{
				dataPtr += i;
				if (dataPtr) 
				{ 
						printf("not empty data : %s\n", dataPtr);	
						return 1;
				}
		}
		return 0;
}

static void *dequeue(void *arg) { 
		queue *q1 = (queue *)arg; 
		int i = 1;
		char *dataPtr = *(*q1).data;
						printf("dataPtr :%p\n", dataPtr + q1->rear + 1);
		printf("check dequeue ptr :%p\n", *(*q1).data + (*q1).rear); 
		while(1) 
		{
				if (queueIsEmpty(q1) == 1) {
						printf("\033[32mpush data !!!! :\033[0m %s\033[0m\n", dataPtr + i);
						dataPtr = (char *)calloc(MAXSIZE, sizeof(char));// malloc length of data
						//				(q1->data)[i] = '\0';
						sleep(1);
				}
				i ++;
				if(i == MAXSIZE) i = 1;
		}
		return NULL;
}

int main(void) {
		char *data; // input data, 1d array
		int status; 
		int i = 0;

		queue *q1; 
		q1 = malloc(sizeof(queue));
		(*q1).data = calloc(MAXSIZE, sizeof(char)); // 2d array malloc
		*(*q1).data = calloc(MAXSIZE, sizeof(char)); // 2d array malloc
		*(*q1).data = calloc(MAXSIZE, sizeof(char)); // 2d array malloc
		for(i = 0; i < MAXSIZE; i ++) {
				((*q1).data)[i] = calloc(MAXSIZE, sizeof(char)); 
				(*(*q1).data)[i] = '\0'; 
		}

		q1->front = 0; // reset value
		q1->rear = 0;

		//char *temp = '\0';
		//*(*q1).data = temp; 
		(*(*q1).data)[0] = 0; 
		(*(*q1).data)[0]= '\0'; 
		data = calloc(MAXSIZE, sizeof(char));

		pthread_t pthread[2]; // multi thread 
		int pid;
		pid = pthread_create(&(pthread[1]), NULL, dequeue, q1); // q1 transmission to dequeue

		while(1) { // infinite loop for data string
				scanf("%s", data);
				enqueue(q1, data); // transmission to enqueue
				// must check data reset 
				i++; 
				if (i == MAXSIZE) i = 0; 
		}

		if (pid < 0) 
		{
				perror("thread create error : ");
				printf("pid : %d\n", pid);
				exit(0);
		}

		pthread_join(pthread[1], (void *)&status);
		if (q1) // must reset q1->data to null
		{
				free(q1);

		}
		data[0] = '\0';
		return 0;
}
