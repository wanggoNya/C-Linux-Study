#include <stdio.h>
#include <string.h>

int main(void) {
	int x, y;

	printf("출력할 행렬의 크기를 입력 하세요: ");
	scanf("%d %d", &x, &y);

	char arr[x][y];
	memset(arr, 0, x*y*sizeof(char)); // 0 으로 초기화 ;

	char alp = 97;

	int i, j;
	
	
	for(i = 0 ; i < x ; i++ ) {
		for(j = 0 ; j < y ; j++ ) {
			arr[i][j] = alp;
			alp++;
		}
	}

	// 행렬 출력
	for(i = 0; i < x; i++) {
		for(j = 0; j < y; j++) {
			printf("%c	", arr[i][j]);
		}
		printf("\n");
	}
	
	// 첫 번째 배열요소의 포인터를 포인터 변수에 저장한다.
//	arrP = &arr[0][0];
	
	 
	printf("몇 번째 값을 알려드릴까요? : ");
	int num;
	scanf("%d", num);
	printf("%d 번째 값은 [%c] 입니다.\n", num, 96 + num);
}
