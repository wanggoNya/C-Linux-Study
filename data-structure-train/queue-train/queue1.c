#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define length 100
#define maxsize 10

typedef struct {
		char data[MAXSIZE][LENGTH];
		char *input;
		int front;
		int rear;
} queue;

queue *q1;
char input[100][LENGTH];
int queueCnt;

static void enqueue(char data[100]) {
		if (((q1->rear + 1) % MAXSIZE ) == q1->front ) // 꽉찼을 때 
		{
				q1->rear = 0;
				(q1->data)[q1->rear +1][0] = '\0';
		}
		strncpy((q1->data)[(q1->rear) + 1], data, strlen(data));

		(q1->data)[q1->rear +1][strlen(data)] = '\0';
		q1->rear ++;
}

static void *printQueue(void *arg) {
		if(!arg) printf("arg : %p\n", arg);
		int i = 1;
		while(1) 
		{
				if ((q1->data)[i][0] != '\0') {
						printf("\033[32mpush data !!!! :\033[0m %s\033[0m\n", (q1->data)[i]);
						(q1->data)[i][0] = '\0';
						sleep(1);
				}
				i ++;
				if(i == 10) i = 1;
		}
		return NULL;
}

int main(void) {
		char data[100];
		int status;
		q1 = malloc(sizeof(queue));
		q1->front = 0;
		q1->rear = 0;

		queueCnt = 0;

		pthread_t pthread[2];
		int pid;

		data[0] = '\0';

		strcpy(q1->data[q1->front], data);
		strcpy(q1->data[q1->rear], data);
		strcpy(input[0], data);

		pid = pthread_create(&(pthread[1]), NULL, printQueue, data);

		while(1) {
				scanf("%s", input[queueCnt]);
				input[queueCnt][strlen(input[queueCnt])] = '\0';
				enqueue(input[queueCnt]);
				queueCnt ++;
				if (queueCnt == 100) 
				{
						queueCnt = 0;
						input[queueCnt][0] = '\0';
				}
		}

		if (pid < 0) 
		{
				perror("thread create error : ");
				printf("pid : %d\n", pid);
				exit(0);
		}

		pthread_join(pthread[1], (void *)&status);
		if (q1)
		{
				free(q1);

		}
		data[0] = '\0';
		return 0;
}

