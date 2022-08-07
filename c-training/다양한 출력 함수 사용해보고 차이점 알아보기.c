#include <stdio.h>

int main(void) {
	char* str = "hello world\n";
	
	puts("Hello world");
	fputs(str, stdout);
	printf("Hello world\n");
//	fprint("Hello world\n");
	return 0;
}

