#include <stdio.h>
#define NUMBER 5

int main(void) {
	int array[NUMBER];
	int i, oddMax, evenMax;
	
	for(i = 0; i < NUMBER; i ++) {
		printf("%d 번째 숫자 입력 : ", i);
		scanf("%d", &array[i]);
		
		if(array[i] % 2 == 0) {
			if(oddMax < array[i]) {
				oddMax = array[i];
			}
		} else {
			if(evenMax < array[i]) {
				evenMax = array[i];
			}
			
		}
	}
	printf("홀수의 최대는 %d, 짝수의 최대는 %d", oddMax, evenMax);
	return 0;
}
