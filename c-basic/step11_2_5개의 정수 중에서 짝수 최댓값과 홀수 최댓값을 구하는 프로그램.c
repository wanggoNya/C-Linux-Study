#include <stdio.h>
#define NUMBER 5

int main(void) {
	int array[NUMBER];
	int i, oddMax, evenMax;
	
	for(i = 0; i < NUMBER; i ++) {
		printf("%d ��° ���� �Է� : ", i);
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
	printf("Ȧ���� �ִ�� %d, ¦���� �ִ�� %d", oddMax, evenMax);
	return 0;
}
