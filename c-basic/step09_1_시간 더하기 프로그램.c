// ����� ���� �Լ�

// �ð� ���ϱ� 
#include <stdio.h> 

// ���� ����
int hour;
int minute;
int minuteAdd;

void counter() {
	minute += minuteAdd ;
	hour += minute / 60;
	minute %= 60;
	hour %= 24;
}
 
int main(void) {
	
	printf("�� �Է� : ");
	scanf("%d", &hour);
	printf("�� �Է� : ");
	scanf("%d", &minute);
	printf("���� ��  �Է� : ");
	scanf("%d", &minuteAdd);
	counter();
	
	printf("�ð��� %d�� %d �� �Դϴ�", hour, minute);
	
	return 0;
}
