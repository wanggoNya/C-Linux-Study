#include <stdio.h>

// �ּҷ� �� �� �ִ� �Ž����� ��� ���α׷� 

int smallest(int number) {
	int count = 0;
	while (number >= 50000)	 { // ���� ���� �Ž��� ȭ�� ���� ���ϱ� ���� 
		number -= 50000;
		count ++;
	}
	while (number >= 10000)	 {
		number -= 10000;
		count ++;
	}
	while (number >= 5000)	 {
		number -= 5000;
		count ++;
	}
	while (number >= 1000)	 {
		number -= 1000;
		count ++;
	}
	while (number >= 500)	 {
		number -= 500;
		count ++;
	}
	while (number >= 100)	 {
		number -= 100;
		count ++;
	}
	while (number >= 50)	 {
		number -= 50;
		count ++;
	}
	while (number >= 10)	 {
		number -= 10;
		count ++;
	}
	return count; 
}
 
int main(void) {
	int number;
	printf("�ݾ��� �Է� :");
	scanf("%d", &number);
	
	printf("�ּҷ� �� �� �ִ� �Ž��� ���� %d �� �Դϴ�. \n", smallest(number));
	return 0;
}
