#include <stdio.h>
#define SIZE 30

struct Student {
	int num;
	char name[50];
	int kor;
	int eng;
	int mat;
	int sci;
};

int main() {
	char *select;
	int i = 0;
	struct Student s[SIZE] = { 0, };
	
	printf("[�л� ���� �ý���]\n");
	printf("1. �л� ���� ��ȸ \n2. ���� ���� \n");
	scanf("%s", &select);
	
	switch(select) {
		case '1';
			printf("1-1. �л� �Է�\n1-2. �л� ���\n1-3. �л� ���� ��ȸ\n");
			scanf("%s", &select); 
			switch(select) {
				case '1-1';
					registerStudent(); 
				case '1-2';
					list(i);
				case '1-3';
					info(i);
			}
			break;
		case '2';
			average();
			break;
		case '3';
			subjectAvg();
			break;
		case '4';
			topScore();
			break;
	}
	int i = 5;
	registerStudent(i);
	return 0;
}

struct Student registerStudent(int i) {
	struct Student s[SIZE];
	
	printf("%d �� �л��� �й��� �Է����ּ���. : ");
	scanf("%d", &s[i].num); 
	printf("%d �� �л��� �̸��� �Է����ּ���. : ");
	scanf("%s", &s[i].name); 
	printf("%d �� �л��� ���� ������ �Է����ּ���. : ");
	scanf("%d", &s[i].kor); 
	printf("%d �� �л��� ���� ������ �Է����ּ���. : ");
	scanf("%d", &s[i].eng); 
	printf("%d �� �л��� ���� ������ �Է����ּ���. : ");
	scanf("%d", &s[i].mat); 
	printf("%d �� �л��� ���� ������ �Է����ּ���. : ");
	scanf("%d", &s[i].sci); 
	
	return s[i];
}

struct Student list(int i) {
	struct Student s[SIZE];
	return s[i];
}

struct Student info(int i) {
	struct Student s[SIZE];
	return s[i];
}

int average(void) {
	int average;
	return 0;
}

int subjectAvg(void) {
	return 0;
}

int topScore(void) {
	return 0;
}


