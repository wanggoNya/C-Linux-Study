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
		printf("%d 번 학생의 학번을 입력해주세요. : \n", i+1);
		scanf("%d", &s[i].num); 
		
		printf("%d 번 학생의 이름을 입력해주세요. : \n", i+1);
		scanf("%s", s[i].name);
		printf("%d 번 학생의 국어 성적을 입력해주세요. : \n", i+1);
		scanf("%d", &s[i].kor);
		printf("%d 번 학생의 영어 성적을 입력해주세요. : \n", i+1);
		scanf("%d", &s[i].eng);
		printf("%d 번 학생의 수학 성적을 입력해주세요. : \n", i+1);
		scanf("%d", &s[i].mat);
		printf("%d 번 학생의 과학 성적을 입력해주세요. : \n", i+1);
		scanf("%d", &s[i].sci);
		printf("입력이 완료 되었습니다.\n	학번 : %d\n	이름 : %s\n	국어 성적 : %d\n	영어 성적 : %d\n	수학 성적 : %d\n	과학 성적 : %d\n\n\n", s[i].num, s[i].name, s[i].kor, s[i].eng, s[i].mat, s[i].sci);
	
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
	printf("조회할 학생의 번호를 입력하세요.\n");
	scanf("%d", &num); 
	return num-1;
}
// 0x100 "hello"\0 10Byte
// %s => 0x100 ~ 0x109 \0 10byte 
void info(int i, struct Student *s) {
	printf("	\n학번 : %d\n	이름 : %s\n	국어 성적 : %d\n	영어 성적 : %d\n	수학 성적 : %d\n	과학 성적 : %d\n\n", (s+i) -> num, (s+i) -> name, (s+i) -> kor, (s+i) -> eng, (s+i) -> mat, (s+i) -> sci);
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
		printf("[학생 관리 시스템]\n");
		printf("1. 학생 정보 조회 \n2. 성적 관리 \n3. 종료\n무엇을 도와드릴까요? ");
		scanf("%d", &select);
		
		switch(select) {
			case 3:
				re = 'n';
				printf("이용해 주셔서 감사합니다.");
				break;
			case 1:
				printf("1-1. 학생 입력\n1-2. 학생 정보 조회\n1-3. 종료\n");
				scanf("%d", &select);
				switch(select) {
					case 3:
						re = 'n';
						printf("이용해 주셔서 감사합니다."); 
						break;
					case 1:
						printf("등록할 학생의 수를 입력해주세요. : ");
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
