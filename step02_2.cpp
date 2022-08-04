#include <stdio.h>
#include <limits.h> // 각각의 변수들, 한계값, 범위를 포함하고 있는 라이브러 

int main(void)
{
	// overflow 값이 초과되는 경우 
	int a = INT_MAX; // int가 가질 수 있는 최대의 값, limits.h 라이브러리가 필요
	printf("int형의 최대값은 %d 입니다. \n", a) ;
	printf("a + 1 =  %d 입니다. \n", a+1) ; // 한바퀴를 건너 뛰고 최소값으로 돌아가버림
	// overflow! 

	return 0;	
}
