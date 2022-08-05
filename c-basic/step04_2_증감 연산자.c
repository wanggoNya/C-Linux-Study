#include <stdio.h>

// 증감 연산자를 이용해 x를 다뤄보자
int main(void) {
	int x = 0;
	printf("현재의 x는 %d입니다. \n", x);
	x++;
	printf("현재의 x는 %d입니다. \n", x);

	printf("현재의 x--는 %d입니다. \n", x--); // 출력할 때 증감하면 출력 후에 적용됨.
	printf("현재의 x는 %d입니다. \n", x);
	printf("현재의 --x는 %d입니다. \n", --x);
	printf("현재의 x는 %d입니다. \n", x);
}
