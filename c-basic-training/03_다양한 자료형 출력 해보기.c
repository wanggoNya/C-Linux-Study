#include <stdio.h> 

int main(void) {
	char a = 'a';
	printf("char : %d	%c\n", sizeof(a), a);
	
	unsigned char b = 'a';
	printf("unsigned char : %d	%c\n", sizeof(b), b);

	int c = 123;
	printf("int : %d	%d\n", sizeof(c), c);

	short d = 123;
	printf("short : %d	%hd\n", sizeof(d), d);

	long e = 123;
	printf("char : %d	%d\n", sizeof(e), e);

	unsigned short f = 123;
	printf("unsigned short : %d	%hd\n", sizeof(f), f);
	
	unsigned int g = -1000;
	printf("unsigned int : %d	%hd\n", sizeof(g), g);
	
	unsigned long h = -3.14;
	printf("unsigned long : %d	%ld\n", sizeof(h), h);
	
	float i = 3.141592;
	printf("float : %d	%.3f\n", sizeof(i), i);
	
	double j = 3.14;
	printf("double : %d	%lf\n", sizeof(j), j);	
	
	int* k = 1001;
	printf("pointer : %d	%p\n", sizeof(k), k);
		
//	void l = 'a';
//	printf("void : %d	%c\n", sizeof(l), l);
}
