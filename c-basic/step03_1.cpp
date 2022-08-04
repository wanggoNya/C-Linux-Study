#include <stdio.h>
#define MONTHS 12 // 상수에 대한 정의 ex 원주율, 등등 이미 정해진 수학적 법칙 define 뒤에 정의해줄것 
int main(void)
{
	double monthSalary = 1000.5;
	printf("$ %2.f", monthSalary * MONTHS);
	return 0;
}
