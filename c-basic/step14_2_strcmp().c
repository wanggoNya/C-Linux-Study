#include <stdio.h>
#include <string.h>

int main(void) {
	char inputOne[5] = "A";
	char inputTwo[5] = "B";
	printf("���ڿ� �� : %d\n", strcmp(inputOne, inputTwo)); 
	
	// strcmp �� �� ���ڰ� ���������� �����ϸ� 0,
	// ������ ���������� �տ� �ִٸ� -1, �������� �տ� �ִٸ� 1�� ��ȯ �ϴ� �Լ�  
	return 0;
}
