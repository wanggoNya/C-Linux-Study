#include <stdio.h>

int main(void) {
	int A = 10;
	int B = 35;
	
	printf("A + B = %d\n", A+B);
	printf("A - B = %d\n", A-B);
	printf("A * B = %d\n", A*B);
	printf("A / B = %d\n", A/B);
	printf("A % B = %d\n", A%B);
	
	printf("A ++ = %d\n", A++);
	printf("++ A = %d\n", ++A);
	printf("A -- = %d\n", A--);
	printf("-- A = %d\n", --A);
		
	printf("B ++ = %d\n", B++);
	printf("++ B = %d\n", ++B);
	printf("B -- = %d\n", B--);
	printf("-- B = %d\n", --B);
	
	while(1) { // while에 1을 지정하면 무한루프 
		A += B;
		printf("A += B = %d\n", A);
		A -= B;
		printf("A -= B = %d\n", A);
		A *= B;
		printf("A *= B = %d\n", A);
		A /= B;
		printf("A /= B = %d\n", A);
		A %= B;
		printf("A %= B = %d\n", A);
		break;
	}
	
	A = 15;
	B = 25;
	
	if(A && B) {
		printf("A && B\n");
		printf("A = %d\n, A");
		printf("B = %d\n, B");
	} 
	
	A < B ? A = 1 : B = 2;
}
