#include <stdio.h>
#include <string.h>

int check(int count, int size) {
	if(count > (size*size)) {
		return 0;
	} else {
		return 1;
	}
}

int main(void) {
	printf("출력할 행렬의 크기를 입력하세요 : ");
	int size;
	scanf("%d", &size);

	int matrix[size][size];
	memset(matrix, 0, size*size*sizeof(int)); // 0 으로 초기화 ;

	int rotation = 0;
	int i, j;
	int x = 0;
	int y = 0;
	int count = 0;
	int xMax = size-1;
	int yMax = size-1;

	while(count <= (size*size)) {

		// down
		for(i = x+rotation; i < xMax ; i++) {
			count++;
			matrix[i][y] = count;
		}
		
		if( check(count, size) == 0 ) {
			break;
		};
		
		// right
		for(i = y+rotation; i < yMax-rotation ; i++) {
			count++;
			matrix[xMax][i] = count;
		}
		
		if( check(count, size) == 0 ) {
			break;
		};
		
		// up
		for(i = xMax; i > x+rotation ; i--) {
			count++;
			matrix[i][yMax] = count;
		}
		
		if( check(count, size) == 0 ) {
			break;
		};
		
		// left
		for(i = yMax-rotation; i > y+rotation ; i--) {
			count++;
			matrix[x][i] = count;
		}

		if( check(count, size) == 0 ) {
			break;
		};
		
		rotation ++;
	}

	// 행렬 출력
	for(i = 0 ; i < size ; i++ ) {
		for(j = 0 ; j < size ; j++ ) {
			printf("%d 		", matrix[i][j]);
		}
		printf("\n");
	}
}
