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

		int rearPtr = (q1->rear);
		char *dataPtr;
		dataPtr = (q1->data)[rearPtr + 1];
		dataPtr = data;
		printf("===============================\n");	
		printf("check enqueue data : %s\n", dataPtr);	
		printf("check enqueue ptr :%p\n", (q1->data)[rearPtr + 1]); 
		printf("check enqueue rear :%d\n", rearPtr+1); 
		printf("===============================\n");	
		q1->rear++; // increase rear value 
}

static int queueIsEmpty(queue * q1) {
		// check queue is null
		int i;
		//char *dataPtr = *(*q1).data;
		//char *dataptr = (q1->data);
		for (i = 1 ; i < MAXSIZE ; i++)
		{
				if (strcmp((q1->data)[i], "\0")) 
				{ 
						//printf("not empty data Ptr: %p\n", (q1->data)[i]);	
						//printf("not empty data : %s\n", (q1->data)[i]);	
						return 1;
				}
		}
		return 0;
}

static void *dequeue(void *arg) { 
		queue *q1 = (queue *)arg; 
		int i = 1;
		while(1) 
		{
				//char *dataPtr = *(*q1).data + i;
				char *dataPtr = (q1->data)[i];
				/*printf("===============================\n");	
				printf("check \033[32mdequeue data : %s\033[0m\n", dataPtr);	
				printf("check \033[32mdequeue ptr :%p\033[0m\n", dataPtr); 
				printf("check \033[32mdequeue rear :%d\033[0m\n", i); 
				printf("===============================\n");	*/
				if (queueIsEmpty(q1) == 1) {
						printf("\033[32mpop data !!!! :\033[0m %s\033[0m\n", dataPtr);
						//dataPtr = (char *)calloc(MAXSIZE, sizeof(char));// malloc length of data
						(q1->data)[i] = "\0";
						//data[i] = strdup(temp);
						sleep(1);
						i ++;
				}
				sleep(1);
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
		q1->data = calloc(MAXSIZE, sizeof(char*)); // 2d array malloc

		for(i = 0; i < MAXSIZE; i ++) {
				(q1->data)[i] = calloc(MAXSIZE, sizeof(char)); 
				(q1->data)[i]= "\0";
		}

		q1->front = 0; // reset value
		q1->rear = 0;

		data = calloc(MAXSIZE, sizeof(char));


		pthread_t pthread[2]; // multi thread 
		int pid;
		pid = pthread_create(&(pthread[1]), NULL, dequeue, q1); // q1 transmission to dequeue
		i = 0;
		while(1) { // infinite loop for data string
				scanf("%s", data);
				if (0)	enqueue(q1, data); // transmission to enqueue
				if (((q1->rear + 1) % MAXSIZE ) == q1->front ) // full queue 
				{
						q1->rear = 0; // reset rear value
				}

				(q1->data)[q1->rear + 1] = strdup(data);
				/*printf("===============================\n");	
				printf("check enqueue data : %s\n", (q1->data)[q1->rear + 1]);	
				printf("check enqueue ptr :%p\n", (q1->data)[q1->rear + 1]); 
				printf("check enqueue rear :%d\n", i+1); 
				printf("===============================\n");	*/
				q1->rear++; // increase rear value 
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
