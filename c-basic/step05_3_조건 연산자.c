// ���� ������
#include <stdio.h>

int main(void)  {
	int x = -50, y = 30;
	int max = (x > y) ? x : y;
	int min = (x < y) ? x : y;
	int absoluteX = (x > 0)? x : -x ; // ���밪�� ��ȯ�ϵ��� �ϴ� ���� ������
	printf("x�� ���밪�� %d\n", absoluteX) ;
	printf("�ִ밪�� %d\n", max);
	printf("�ִ밪�� %d\n", min);
	return 0;
	
	// ���� �����ڴ� �ڵ� �����ϰ� ����! 
}
