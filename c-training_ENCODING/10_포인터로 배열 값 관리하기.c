#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int x, y, i, j, count, num;

	printf("출력할 행렬의 크기를 입력 하세요: ");
	scanf("%d %d", &y, &x);

	// 메모리 할당, 배열과 거의 동일
	// 동적 메모리 할당 2차원 배열 들어갈 공간을 만드는 것
	char ** pptr = (char**)malloc(sizeof(char*) * y);

	// 2차원 배열 생성
	for(i = 0 ; i < y ; i++ ) {
		*(pptr + i) = (char *)malloc(sizeof(char) * x);
	}

	count = 0 ;
	for(i = 0 ; i < x ; i++ ) {
		for(j = 0 ; j < y ; j++ ) {
			*(*(pptr + i) + j) = 97 + count;
			count++;
			if(count == 27) {
				break;
			}
			printf("%3c", *(*(pptr + i) + j));
		}
		printf("\n");
		if(count == 27) {
			break;
		}
	}

	printf("몇 번째 값을 알려드릴까요? : ");
	scanf("%d", &num);

	count = 1;
	for(i = 0 ; i < x ; i++ ) {
		for(j = 0 ; j < y ; j++ ) {
			if(count == num) {
				printf("%3c", *(*(pptr + i) + j) - 32);
				for(i = 0 ; i < x ; i++) {
					free(*(pptr + y));
					return 0;
				}
			}
			count++;
		}
	}

	// 메모리 해제
	for(i = 0 ; i < x ; i++) {
		free(*(pptr + y));
	}

	return 0;
}