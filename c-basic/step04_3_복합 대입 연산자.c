// 복합 대입 연산자 
// 두 개 이상의 연산자가  한꺼번에 묶여 사용되는 것 
// 코드 줄이기 가능 

#include <stdio.h>

int main(void) {
	int x = 100;
	printf("현재 x의 값은 %d 입니다.\n" , x);
	
	x += 50;
	
	printf("현재 x의 값은 %d 입니다.\n" , x);
	
	x -= 50;
	
	printf("현재 x의 값은 %d 입니다.\n" , x);
		
	x *= 50;
	
	printf("현재 x의 값은 %d 입니다.\n" , x);
		
	x /= 50;
	
	printf("현재 x의 값은 %d 입니다.\n" , x);
		
	x %= 3;
	
	printf("현재 x의 값은 %d 입니다.\n" , x);
	return 0;
}
