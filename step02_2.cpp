#include <stdio.h>
#include <limits.h> // ������ ������, �Ѱ谪, ������ �����ϰ� �ִ� ���̺귯 

int main(void)
{
	// overflow ���� �ʰ��Ǵ� ��� 
	int a = INT_MAX; // int�� ���� �� �ִ� �ִ��� ��, limits.h ���̺귯���� �ʿ�
	printf("int���� �ִ밪�� %d �Դϴ�. \n", a) ;
	printf("a + 1 =  %d �Դϴ�. \n", a+1) ; // �ѹ����� �ǳ� �ٰ� �ּҰ����� ���ư�����
	// overflow! 

	return 0;	
}
