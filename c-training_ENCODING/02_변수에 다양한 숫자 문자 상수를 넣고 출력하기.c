#include <stdio.h>

int main(void) {
	int a = -100;
	int b = 0;
	int c = 300;
	float d = 3.14;
	float e = 37.00000;
	char f = 'a';
	char g = '@';
	
	printf("%d, %d %d\n", a, b, c);
	printf("%.2f, %.1f\n", d, e);
	printf("%c, %c\n", f, g);
}
