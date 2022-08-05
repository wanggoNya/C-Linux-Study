#include <stdio.h>

// 관계 연산자
 
int main(void) {
	int x = 50, y = 30;
	// x, y가 같은 값을 가지고 있는가?
	// x = y -> x, y가 같은 상황 그 자체를 의미 
	// x == y -> true, x와 y가 같은 값을 가지고 있는 것
	
	printf("x == y ? %d\n", x == y);
	printf("x != y ? %d\n", x != y);
	printf("x > y ? %d\n", x > y);
	printf("x < y ? %d\n", x < y);
	printf("x에 y 값 넣으면 ? %d\n", x = y);
	printf("x에 y 값 넣으면 ? %d\n", (x = y) ); //
	printf("%d %d\n", x, y); 
	
	if (x == y ) {
		// true 일 때 실행되는 부분 
	} else {
		// false 실행 
	}
	
	
	return 0;
}
