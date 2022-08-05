// 조건 연산자
#include <stdio.h>

int main(void)  {
	int x = -50, y = 30;
	int max = (x > y) ? x : y;
	int min = (x < y) ? x : y;
	int absoluteX = (x > 0)? x : -x ; // 절대값을 반환하도록 하는 조건 연산자
	printf("x의 절대값은 %d\n", absoluteX) ;
	printf("최대값은 %d\n", max);
	printf("최대값은 %d\n", min);
	return 0;
	
	// 조건 연산자는 코드 간단하게 만듬! 
}
