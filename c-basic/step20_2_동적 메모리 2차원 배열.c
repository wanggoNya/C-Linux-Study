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
			*(*(pptr + y) + x ) = 6 * y + x; // pptr (인덱스 0) 에서 y씩 증가시키면서 배열 채움
			// 1열마다 6배수로 증가하므로 6을 곱해주고, 행 진행 될수록 1씩 증가하도록 만듬 
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
