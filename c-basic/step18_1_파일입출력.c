#include <stdio.h>

int main(void) {
	FILE *fp = NULL;
	fp = fopen("test0811.txt", "w");
	// w -> ���� ���(Write), r -> �б� ���(Read)
	
	if(fp == NULL) {
		printf("���� ���⿡ �����߽��ϴ�. \n");
	}
	
	else {
		printf("���� ���⿡ �����߽��ϴ�. \n");
	}
	
	fputc('H',fp);
	fputc('E',fp);
	fputc('L',fp);
	fputc('L',fp);
	fputc('O',fp);
	fclose(fp);
	
	return 0;
}
