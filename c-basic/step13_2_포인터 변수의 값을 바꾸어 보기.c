#include <stdio.h>

int main()  {
	int i = 10; 
	int *p; // ������ �ڷ����� p ����
	p = &i; // p���� i�� �ּҸ� ��´�.  
	
	printf("%d\n", p); 
	printf("%d\n", *p); 
	printf("i = %d\n", i); 
	*p = 20; // 
	printf("i = %d\n", i);
	return 0;
}
