// 배열 
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
	// array[0] ~ array[4] : 총 5개가 들어갈 수 있는 크기의 배열 선언
	for(i = 0; i < NUMBER; i++)  {
		printf("%d 번째 숫자를 입력 : ", i+1);
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
	
	printf("가장 큰 숫자는 %d 이고, %d 번째 입니다.", max, index+1);
	printf("가장 작은 숫자는 %d 이고, %d 번째 입니다.", min, indexMin+1);
	return 0;
}
