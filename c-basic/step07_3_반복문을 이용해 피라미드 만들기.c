#include <stdio.h>
#define N 20

int main(void) {
	int i, j;
	
	// ����, c������ for���ȿ��� int i �� ����  �ʱ�ȭ �Ұ��� 
	for(i = 0 ; i < N ; i ++) { // 19�� �ݺ�  
		for(j = N - i - 1 ; j > 0 ; j--) { // j�� 0�϶����� �ϳ��� ���鼭 �ݺ�, j ��  
			printf("  ");
		}
		for(j = 0 ; j < i ; j++) {
			printf("@ ");
		}
		for(j = 0 ; j < i - 1 ; j++) {
			printf("@ ");
		}
		printf("\n");
	}

	return 0;
}
