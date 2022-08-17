#include <stdio.h>
#include <string.h>
#define SIZE 30

struct Student {
	int num;
	char name[20];
	int kor;
	int eng;
	int mat;
	int sci;
};

struct Student registerStudent(struct Student *s, int num) {
	
	int i = 0;
	
	while(i < num) {
		printf("%d �� �л��� �й��� �Է����ּ���. : \n", i+1);
		scanf("%d", &s[i].num); 
		
		printf("%d �� �л��� �̸��� �Է����ּ���. : \n", i+1);
		scanf("%s", s[i].name);
		printf("%d �� �л��� ���� ������ �Է����ּ���. : \n", i+1);
		scanf("%d", &s[i].kor);
		printf("%d �� �л��� ���� ������ �Է����ּ���. : \n", i+1);
		scanf("%d", &s[i].eng);
		printf("%d �� �л��� ���� ������ �Է����ּ���. : \n", i+1);
		scanf("%d", &s[i].mat);
		printf("%d �� �л��� ���� ������ �Է����ּ���. : \n", i+1);
		scanf("%d", &s[i].sci);
		printf("�Է��� �Ϸ� �Ǿ����ϴ�.\n	�й� : %d\n	�̸� : %s\n	���� ���� : %d\n	���� ���� : %d\n	���� ���� : %d\n	���� ���� : %d\n\n\n", s[i].num, s[i].name, s[i].kor, s[i].eng, s[i].mat, s[i].sci);
	
		i++;
	}
	
	printf("%s", s[i+1].name);
	return s[num];
}

int list(struct Student *s) {
	int i = 0;
	/*for (i = 0; i < 10; i++) { 
		if (strlen(s[i].name)) printf("name : %s\n", s[i].name);
		else {
			printf("no name\n");
			break;
		}
	}*/
	while(*(s[i].name)) {
		printf("%d. %s	 \n", i + 1, s[i].name);
		i++;
	}
	int num;
	printf("��ȸ�� �л��� ��ȣ�� �Է��ϼ���.\n");
	scanf("%d", &num); 
	return num-1;
}
// 0x100 "hello"\0 10Byte
// %s => 0x100 ~ 0x109 \0 10byte 
void info(int i, struct Student *s) {
	printf("	\n�й� : %d\n	�̸� : %s\n	���� ���� : %d\n	���� ���� : %d\n	���� ���� : %d\n	���� ���� : %d\n\n", (s+i) -> num, (s+i) -> name, (s+i) -> kor, (s+i) -> eng, (s+i) -> mat, (s+i) -> sci);
}

  /*         // 0x20,  0x10  
void func1(int num, int *num1) {
	num = 30;
	*num1 = 30;
	return;
}
*/
int main() {
	//struct Student s[5] = {0,};
	struct Student *s = NULL;
	int select;
	int num, i = 0;
	
	//0x10
/*	int *test;
	*test = 20;
	printf("%d\n", *test);
	func1(*test, test);
	printf("%d\n", *test);
	*/
	char re = 'y';
	while(re == 'y') {
		printf("[�л� ���� �ý���]\n");
		printf("1. �л� ���� ��ȸ \n2. ���� ���� \n3. ����\n������ ���͵帱���? ");
		scanf("%d", &select);
		
		switch(select) {
			case 3:
				re = 'n';
				printf("�̿��� �ּż� �����մϴ�.");
				break;
			case 1:
				printf("1-1. �л� �Է�\n1-2. �л� ���� ��ȸ\n1-3. ����\n");
				scanf("%d", &select);
				switch(select) {
					case 3:
						re = 'n';
						printf("�̿��� �ּż� �����մϴ�."); 
						break;
					case 1:
						printf("����� �л��� ���� �Է����ּ���. : ");
						scanf("%d", &num);
						//s = (struct Student *)malloc(sizeof(struct Student) * num);
						s = calloc(num+1, sizeof(struct Student));
						registerStudent(s, num);
						break;
					case 2:
						info(list(s), s);
						break;
				}
		}
	}
	free(s);
	return 0;
};
