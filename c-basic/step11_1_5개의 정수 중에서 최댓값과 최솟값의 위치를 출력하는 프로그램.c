// �迭 
#include <stdio.h>
#include <limits.h>
#define NUMBER 5

int main(void) {
	int i, max, min, index, indexMin;
	
	max = 0;
	index = 0;
	indexMin = 0;
	min = INT_MAX;
	int array[NUMBER];
	// array[0] ~ array[4] : �� 5���� �� �� �ִ� ũ���� �迭 ����
	for(i = 0; i < NUMBER; i++)  {
		printf("%d ��° ���ڸ� �Է� : ", i+1);
		scanf("%d", &array[i]);
		
		if(max < array[i]) {
			max = array[i];
			index = i;
		}
		if(min > array[i]) {
			min = array[i];
			indexMin = i;
		}
	}
	
	printf("���� ū ���ڴ� %d �̰�, %d ��° �Դϴ�.", max, index+1);
	printf("���� ���� ���ڴ� %d �̰�, %d ��° �Դϴ�.", min, indexMin+1);
	return 0;
}
