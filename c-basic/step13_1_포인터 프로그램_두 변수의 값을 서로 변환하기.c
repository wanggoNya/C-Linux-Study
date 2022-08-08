// 두 변수의 값을 서로 변환하는 포인터 함수 프로그램 
#include <stdio.h>

void swap(int *x, int *y)  { // 가장 대표적인 포인터 사용하는 함수 
	int temp;
	temp = *x; 
	*x = *y;
	*y = temp;
}

int main(void) {
	int x = 1;
	int y = 2;
	swap(&x, &y) ;
	printf("x = %d\ny = %d\n", x, y);
	
	// 포인터를 안 쓰면 지역변수라서 값이 안 바뀜!!!!!
}
