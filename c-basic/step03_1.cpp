#include <stdio.h>
#define MONTHS 12 // ����� ���� ���� ex ������, ��� �̹� ������ ������ ��Ģ define �ڿ� �������ٰ� 
int main(void)
{
	double monthSalary = 1000.5;
	printf("$ %2.f", monthSalary * MONTHS);
	return 0;
}
