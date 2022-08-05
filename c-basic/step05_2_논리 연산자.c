// 논리연산자
#include <stdio.h> 

int main(void)
{
	int x = 50, y = 30 ; 
	printf("x가 y보다 크고 y는 40 미만? %d\n", (x>y) && (x<40)); // and 
	printf("x가 y보다 작거나 혹은 y가 30�? %d\n", (x<y) || (y==30)); // or
	printf("x가 50 아님? %d\n", (x != 50)); // not
	return 0;
}
