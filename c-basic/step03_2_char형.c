#include <stdio.h>

int main(void) {
	char x = 'A';
	//아스키코드 :  하나의 char 형이 담을 수 있는  모든 문자에 대한 내용을 보여주는 하나의 코드 표
	printf("x = %c\n", x);


	int a = 65;
	//아스키코드 :  하나의 char 형이 담을 수 있는  모든 문자에 대한 내용을 보여주는 하나의 코드 표
	printf("a = %c\n", a);
	// 출력 타입이 %c이기 때문에 A로 출력

	char y = 65;
	char b = 'B';
	printf("y = %c\n", y);
	printf("b = %d\n", b);


	return 0;
}
