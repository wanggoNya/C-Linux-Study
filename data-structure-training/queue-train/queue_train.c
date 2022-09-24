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

		strcpy((q1->data)[(q1->rear)+ 1], data);
		printf("===============================\n");	
		printf("check enqueue data : %s\n", (q1->data)[(q1->rear)+ 1]);	
		printf("check enqueue ptr :%p\n", (q1->data)[(q1->rear)+ 1]); 
		printf("check enqueue rear :%d\n", (q1->rear)+1); 
		printf("===============================\n");	
		q1->rear++; // increase rear value 
}

static int queueIsNotEmpty(queue * q1) {
		// check queue is null
		int i;
		//char *dataPtr = *(*q1).data;
		//char *dataptr = (q1->data);
		for (i = 1 ; i < MAXSIZE ; i++)
		{
				//	if ((q1->data)[i] != 0) 
				if ((q1->data)[i][0] != 0) 
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
				printf("===============================\n");	
				printf("check \033[32mdequeue data : %s\033[0m\n", dataPtr);	
				printf("check \033[32mdequeue ptr :%p\033[0m\n", dataPtr); 
				printf("check \033[32mdequeue rear :%d\033[0m\n", i); 
				printf("===============================\n");
				if (queueIsNotEmpty(q1) == 1) {
						printf("\033[32mpop data !!!! :\033[0m %s\033[0m\n", dataPtr);
						//(q1->data)[i] = "\0";
						if (!strcmp(dataPtr, "quit")) {
								(q1->data)[0] = "quit";
								return NULL;
						}
						memset((q1->data)[i], 0, strlen(dataPtr));
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
		printf("%ld\n", sizeof(queue));
		q1->data = calloc(MAXSIZE, sizeof(char*)); // 2d array malloc

		for(i = 1; i < MAXSIZE; i ++) {
				(q1->data)[i] = calloc(MAXSIZE, sizeof(char)); 
				//(q1->data)[i]= "\0";
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
				enqueue(q1, data); // transmission to enqueue
				if (!strcmp(data, "quit")) {
						break;
				}
		}

		if (pid < 0) 
		{
				perror("thread create error : ");
				printf("pid : %d\n", pid);
				exit(0);
		}

		pthread_join(pthread[1], (void *)&status);
		
		for (i = 1; i < MAXSIZE; i++ ) {
				if ((q1->data)[i]) {
						free((q1->data)[i]);
						(q1->data)[i] = NULL;
				}

		}
		if (q1->data) {
				free(q1->data);
				q1->data = NULL;
		}
		if (q1) // must reset q1->data to null
		{
				free(q1);
				q1 = NULL;

		}
		if (data){
				free(data);
				data = NULL;
		}
		return 0;
}
