#include <stdio.h>
#include <string.h>
#define SUBJECT 4

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
	while(*(s[i].name)) { // student ����ü ���� �̸�(���ڿ�)�� ������ ���¹Ƿ� �� ���� ���� ������ 
		printf("%d. %s	 \n", i + 1, s[i].name);
		i++;
	}
	int num;
	printf("��ȸ�� �л��� ��ȣ�� �Է��ϼ���.\n");
	scanf("%d", &num); 
	return num-1;
}

void info(int i, struct Student *s) {
	printf("\n	�й� : %d\n	�̸� : %s\n	���� ���� : %d\n	���� ���� : %d\n	���� ���� : %d\n	���� ���� : %d\n\n", (s+i) -> num, (s+i) -> name, (s+i) -> kor, (s+i) -> eng, (s+i) -> mat, (s+i) -> sci);
}

void average(int i, struct Student *s) {
	int sum;
	float average;
	sum = s[i].kor + s[i].mat + s[i].sci + s[i].eng;
	average = sum / SUBJECT;
	printf("%d �� %s �л��� ��ü ��� ������ %.1f�� �Դϴ�.\n\n", i+1, s[i].name, average); 
}

void averageAll(int num, struct Student *s) {
	int sum, i, j;
	float average;
	char *subArray;
	for(j = 0 ; j < SUBJECT ; j++ ) {
		for(i = 0 ; i < num ; i++ ) {
			if(j == 0) {sum += s[i].kor; subArray = "����"; }
			if(j == 1) {sum += s[i].mat; subArray = "����";}
			if(j == 2) {sum += s[i].sci; subArray = "����";}
			if(j == 3) {sum += s[i].eng; subArray = "����";}
		}
		average = sum / num;
		printf("%s ������ ��ü ��� ������ %.1f�� �Դϴ�.\n\n", subArray, average); 
		sum = 0;
	}
}

void top(int num, struct Student *s, int sub) { // 0 1 2 3 4(��ü) 
	int i, j, max = 0, repeat = 1, temp = sub, top;
	char *subArray;
	printf("sub :  %d\n\n", sub);
	if(sub == 4) {repeat = 4; temp = 0;}
	for(j = 0 ; j < repeat ; j++ ){
		printf("temp :: %d \n\n", temp);
		for(i = 0 ; i < num ; i++ ) {
			if(temp == 0) {if(max < s[i].kor) {max = s[i].kor; subArray = "����"; top = i;}}
			else if(temp == 1) {if(max < s[i].mat) {max = s[i].mat; subArray = "����"; top = i;}}
			else if(temp == 2) {if(max < s[i].sci) {max = s[i].sci; subArray = "����"; top = i;}}
			else if(temp == 3) {if(max < s[i].eng) {max = s[i].eng; subArray = "����"; top = i;}}
		}
		printf("%s ������ 1���� �л��� �̸��� ����\n	�й� : %d\n	�̸� : %s\n	���� ���� : %d\n	���� ���� : %d\n	���� ���� : %d\n	���� ���� : %d\n\n", subArray, (s+top) -> num, (s+top) -> name, (s+top) -> kor, (s+top) -> eng, (s+top) -> mat, (s+top) -> sci);
		if(sub == 4) { temp++; max = 0;}
	}
}

int main() {
	struct Student *s = NULL;	//struct Student s[5] = {0,};
	int select;
	int num, i = 0, sub;
	
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
						s = calloc(num+1, sizeof(struct Student)); // �ʱ�ȭ�� ���ÿ� 0���� ������� 
						registerStudent(s, num);
						break;
					case 2:
						info(list(s), s);
						break;
				}
				break;
			case 2:
				printf("2-1. Ư�� �л��� ��� ���� \n2-2. ��ü �л��� ���� �� ��� ���� \n2-3. Ư�� ������ 1���� �л��� �̸� �� ���� \n2-4. ���� \n");
				scanf("%d", &select);
				switch(select) {
					case 4:
						re = 'n';
						printf("�̿��� �ּż� �����մϴ�.");
						break;
					case 1:
						average(list(s), s);
						break;
					case 2:
						averageAll(num, s); 
						break;						
					case 3:
						printf("��ȸ�� ������ �����ϼ���\n1. ���� 2. ���� 3. ���� 4. ���� 5. ��ü\n");
						scanf("%d", &sub);
						top(num, s, sub-1);
				}
		}
	}
	free(s);
	return 0;
};
