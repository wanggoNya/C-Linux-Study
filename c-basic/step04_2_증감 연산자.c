#include <stdio.h>

// ���� �����ڸ� �̿��� x�� �ٷﺸ��
int main(void) {
	int x = 0;
	printf("������ x�� %d�Դϴ�. \n", x);
	x++;
	printf("������ x�� %d�Դϴ�. \n", x);

	printf("������ x--�� %d�Դϴ�. \n", x--); // ����� �� �����ϸ� ��� �Ŀ� �����.
	printf("������ x�� %d�Դϴ�. \n", x);
	printf("������ --x�� %d�Դϴ�. \n", --x);
	printf("������ x�� %d�Դϴ�. \n", x);
}
