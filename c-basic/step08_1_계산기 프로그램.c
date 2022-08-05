// 계산기 
#include <stdio.h>

int main(void) {

	char o;
	int x , y ;

	while(1) {
		printf("수식 입력 : ");
		scanf("%d %c %d", &x, &o, &y); // & 메모리 주소


		if( o == '+') {
			printf("%d %c %d = %d\n", x, o, y, x + y);
		} else if( o == '-') {
			printf("%d %c %d = %d\n", x, o, y, x - y);
		} else if( o == '*') {
			printf("%d %c %d = %d\n", x, o, y, x * y);
		} else if( o == '/') {
			printf("%d %c %d = %d\n", x, o, y, x / y);
		} else {
			printf("입력 오류 \n");
		}

		getchar();

		printf("프로그램을 종료하시겠습니까? (y/n)");

		scanf("%c", &o);

		if( o == 'y' || o == 'Y') {
			break;
		} else if( o == 'n' || o == 'N') {
			continue;
		} else {
			printf("입력 오류 \n");
		}
	}
	return 0;
}
