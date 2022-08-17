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
	
	printf("[학생 관리 시스템]\n");
	printf("1. 학생 정보 조회 \n2. 성적 관리 \n");
	scanf("%s", &select);
	
	switch(select) {
		case '1';
			printf("1-1. 학생 입력\n1-2. 학생 목록\n1-3. 학생 정보 조회\n");
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
	
	printf("%d 번 학생의 학번을 입력해주세요. : ");
	scanf("%d", &s[i].num); 
	printf("%d 번 학생의 이름을 입력해주세요. : ");
	scanf("%s", &s[i].name); 
	printf("%d 번 학생의 국어 성적을 입력해주세요. : ");
	scanf("%d", &s[i].kor); 
	printf("%d 번 학생의 영어 성적을 입력해주세요. : ");
	scanf("%d", &s[i].eng); 
	printf("%d 번 학생의 수학 성적을 입력해주세요. : ");
	scanf("%d", &s[i].mat); 
	printf("%d 번 학생의 과학 성적을 입력해주세요. : ");
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


