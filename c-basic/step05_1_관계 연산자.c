#include <stdio.h>

// ���� ������
 
int main(void) {
	int x = 50, y = 30;
	// x, y�� ���� ���� ������ �ִ°�?
	// x = y -> x, y�� ���� ��Ȳ �� ��ü�� �ǹ� 
	// x == y -> true, x�� y�� ���� ���� ������ �ִ� ��
	
	printf("x == y ? %d\n", x == y);
	printf("x != y ? %d\n", x != y);
	printf("x > y ? %d\n", x > y);
	printf("x < y ? %d\n", x < y);
	printf("x�� y �� ������ ? %d\n", x = y);
	printf("x�� y �� ������ ? %d\n", (x = y) ); //
	printf("%d %d\n", x, y); 
	
	if (x == y ) {
		// true �� �� ����Ǵ� �κ� 
	} else {
		// false ���� 
	}
	
	
	return 0;
}
