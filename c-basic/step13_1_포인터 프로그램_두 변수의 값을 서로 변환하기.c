// �� ������ ���� ���� ��ȯ�ϴ� ������ �Լ� ���α׷� 
#include <stdio.h>

void swap(int *x, int *y)  { // ���� ��ǥ���� ������ ����ϴ� �Լ� 
	int temp;
	temp = *x; 
	*x = *y;
	*y = temp;
}

int main(void) {
	int x = 1;
	int y = 2;
	swap(&x, &y) ;
	printf("x = %d\ny = %d\n", x, y);
	
	// �����͸� �� ���� ���������� ���� �� �ٲ�!!!!!
}
