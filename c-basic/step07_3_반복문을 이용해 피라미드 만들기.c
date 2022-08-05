#include <stdio.h>
#define N 20

int main(void) {
	int i, j;
	
	// 주의, c언어에서는 for문안에서 int i 로 변수  초기화 불가함 
	for(i = 0 ; i < N ; i ++) { // 19번 반복  
		for(j = N - i - 1 ; j > 0 ; j--) { // j가 0일때까지 하나씩 빼면서 반복, j 는  
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
