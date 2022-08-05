// pow() 
// 거듭 제곱 연산을 지원하는 함수
// 기본 존재하는 라이브러리를 사용할 수 있음

#include <stdio.h> 
#include <math.h> // pow(), abs()

int main (void) {
	
	double x = pow(2.0, 20.0); // 2.0 의 20.0 제곱
	printf("2의 20 제곱은 %.0f 입니다\n", x);
		
	return 0;
}
