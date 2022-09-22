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

