#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int i, x, y;
	int ** pptr = (int**)malloc(sizeof(int*) * 8);
	
	for(i = 0 ; i < 8 ; i++ ) {
		*(pptr + i) = (int *)malloc(sizeof(int) * 6);
	}
	
	for(y = 0 ; y < 8 ; y++ ){ // 0 ~ 8
		for(x = 0 ; x < 6 ; x++ ) { // 0 ~ 6 
			*(*(pptr + y) + x ) = 6 * y + x; // pptr (�ε��� 0) ���� y�� ������Ű�鼭 �迭 ä��
			// 1������ 6����� �����ϹǷ� 6�� �����ְ�, �� ���� �ɼ��� 1�� �����ϵ��� ���� 
		}
	} 
	
	for(y = 0 ; y < 8 ; y++ ) {
		for( x = 0 ; x < 6 ; x ++ ) {
			printf("%3d", *(*(pptr + y) + x));
		}
		printf("\n");
	}
	
	for(y = 0; y < 8; y++) {
		free(*(pptr + y));
	}
	return 0;
}
