#include <stdio.h>

int main(void) {
	int x = -150;
	if (x < 0) {
		x = -x;
		// ���밪���� ������ֱ�  
	}
	
	printf("x�� ������ %d\n" , x) ;
	return 0;
}
