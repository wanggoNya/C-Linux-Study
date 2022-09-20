#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int count = 0;
int n;
int front = 0, rear = 0;
int* queue;

static void enQueue(int data) {

	if ((rear + 1) % (n+1) == front) {
		printf("큐가 꽉 찼습니다.\n");
		return;
	}

	rear = (rear + 1) % (n + 1);
	queue[rear % (n+1)] = data;

}

static int deQueue(void) {
	int data;

	if (front == rear) {
		printf("큐가 비었습니다.\n");
		return 0;
	}

	data = queue[(front + 1) % (n+1)];
	front = (front + 1) % (n+1);

	if (!data) return 0;
	return 0;
}

static void printQueue(void) {
	int idx=0;
	idx = (front + 1) % (n+1);

	do{
		if (front == rear) {
			printf("큐가 비었습니다.\n");
			break;
		}
		else if (idx > rear)
			break;
		printf("%d ", queue[idx++ % (n + 1)]);
	} while (1);

}

int main(void) {

	printf("원형 큐의 크기 입력 : ");
	scanf("%d", &n);
	queue = (int*)malloc(sizeof(int) * (n + 1));

	while (1) {
		int menu, data;
		printf("\n1. 삽입 , 2. 삭제, 3. 출력, 4. 종료\n");
		scanf("%d", &menu);

		switch (menu)
		{
		case 1:
			printf("삽입할 데이터 입력 : ");
			scanf("%d", &data);
			enQueue(data);
			break;
		case 2:
			deQueue();
			break;
		case 3:
			printQueue();
			break;
		case 4:
			exit(1);
			break;
		}
	}

}
