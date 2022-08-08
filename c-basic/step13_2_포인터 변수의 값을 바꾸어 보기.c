#include <stdio.h>

int main()  {
	int i = 10; 
	int *p; // 포인터 자료형의 p 선언
	p = &i; // p에는 i의 주소를 담는다.  
	
	printf("%d\n", p); 
	printf("%d\n", *p); 
	printf("i = %d\n", i); 
	*p = 20; // 
	printf("i = %d\n", i);
	return 0;
}
