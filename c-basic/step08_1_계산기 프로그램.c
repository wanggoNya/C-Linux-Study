// ���� 
#include <stdio.h>

int main(void) {

	char o;
	int x , y ;

	while(1) {
		printf("���� �Է� : ");
		scanf("%d %c %d", &x, &o, &y); // & �޸� �ּ�


		if( o == '+') {
			printf("%d %c %d = %d\n", x, o, y, x + y);
		} else if( o == '-') {
			printf("%d %c %d = %d\n", x, o, y, x - y);
		} else if( o == '*') {
			printf("%d %c %d = %d\n", x, o, y, x * y);
		} else if( o == '/') {
			printf("%d %c %d = %d\n", x, o, y, x / y);
		} else {
			printf("�Է� ���� \n");
		}

		getchar();

		printf("���α׷��� �����Ͻðڽ��ϱ�? (y/n)");

		scanf("%c", &o);

		if( o == 'y' || o == 'Y') {
			break;
		} else if( o == 'n' || o == 'N') {
			continue;
		} else {
			printf("�Է� ���� \n");
		}
	}
	return 0;
}
