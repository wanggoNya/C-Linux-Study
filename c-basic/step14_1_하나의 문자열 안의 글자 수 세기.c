#include <stdio.h>

int main(void) {
	char input[1001]; // 1001 ����ŭ�� ���ڰ� �� �� �ִ� �ϳ��� ���ڿ� �������
	gets(input); // ���ڿ� �ޱ� 
	int count = 0;
	
	while(input[count] != '\0') {
		count++; // null ���� �� ���� count ���� 
	}
	
	printf("�Է��� ���ڿ��� ���̴� %d �Դϴ� ", count); 
	printf("�Է��� ���ڿ��� %s �Դϴ� ", input); // %s �ΰ��� ���� �� ���� �ϳ� �ϳ� ����ϴ� ��� 
	return 0; 
}
