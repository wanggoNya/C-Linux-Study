#include <stdio.h>
#include <stdlib.h>

struct student {
	int number;
	char name[10];
	double grade;
};

int main(void) {
	struct student s;
//	s.number = 20150001;
//	strcpy(s.name, "�����");
//	s.grade = 4.5;
	
	
	printf("�й��� �Է� : ");
	scanf("%d", &s.number);
	
	printf("�̸��� �Է� : ");
	scanf("%s", s.name); // �迭�� �� ��ü�� �������� �ǹ̸� ������ �ְ� �� ��ü�� �ּ��� �ǹ��� 
	
	printf("������ �Է� : ");
	scanf("%lf", &s.grade); // �Է� ���� �� lf ��� ������� 
	
	printf("�й� : %d\n", s.number);
	printf("�̸� : %s\n", s.name); 
	printf("���� : %.1f\n", s.grade); 
	return 0;
}
