// ��������
#include <stdio.h> 

int main(void)
{
	int x = 50, y = 30 ; 
	printf("x�� y���� ũ�� y�� 40 �̸�? %d\n", (x>y) && (x<40)); // and 
	printf("x�� y���� �۰ų� Ȥ�� y�� 30�? %d\n", (x<y) || (y==30)); // or
	printf("x�� 50 �ƴ�? %d\n", (x != 50)); // not
	return 0;
}
