#include <stdio.h>

int main(void) {
	FILE *fp = NULL;
	int c;
	
	fp = fopen("input.txt", "r");
	
	if(fp == NULL) {
		printf("���� ���⿡ ����\n");
		
	} else {
		printf("���� ���⿡ ���� \n");
	}
	
	while((c = fgetc(fp)) != EOF) // ���� �����ִ� ���Ͽ��� ���� �ϳ��� �а� c�� �����Ѵ�. 
	{
		putchar(c); // �ܼ�â�� �ش� ���ڸ� ��� // ������ ���� �� ���� ��� �� ��   
	 } 
	 
	 fclose(fp);
	 
	 return 0;
}


