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
	while(*(s[i].name)) { // student 구조체 안의 이름(문자열)은 포인터 형태므로 그 안의 값을 봐야함 
		printf("%d. %s	 \n", i + 1, s[i].name);
		i++;
	}
	int num;
	printf("조회할 학생의 번호를 입력하세요.\n");
	scanf("%d", &num); 
	return num-1;
}

void info(int i, struct Student *s) {
	printf("\n	학번 : %d\n	이름 : %s\n	국어 성적 : %d\n	영어 성적 : %d\n	수학 성적 : %d\n	과학 성적 : %d\n\n", (s+i) -> num, (s+i) -> name, (s+i) -> kor, (s+i) -> eng, (s+i) -> mat, (s+i) -> sci);
}

void average(int i, struct Student *s) {
	int sum;
	float average;
	sum = s[i].kor + s[i].mat + s[i].sci + s[i].eng;
	average = sum / SUBJECT;
	printf("%d 번 %s 학생의 전체 평균 점수는 %.1f점 입니다.\n\n", i+1, s[i].name, average); 
}

void averageAll(int num, struct Student *s) {
	int sum, i, j;
	float average;
	char *subArray;
	for(j = 0 ; j < SUBJECT ; j++ ) {
		for(i = 0 ; i < num ; i++ ) {
			if(j == 0) {sum += s[i].kor; subArray = "국어"; }
			if(j == 1) {sum += s[i].mat; subArray = "수학";}
			if(j == 2) {sum += s[i].sci; subArray = "과학";}
			if(j == 3) {sum += s[i].eng; subArray = "영어";}
		}
		average = sum / num;
		printf("%s 과목의 전체 평균 점수는 %.1f점 입니다.\n\n", subArray, average); 
		sum = 0;
	}
}

void top(int num, struct Student *s, int sub) { // 0 1 2 3 4(전체) 
	int i, j, max = 0, repeat = 1, temp = sub, top;
	char *subArray;
	printf("sub :  %d\n\n", sub);
	if(sub == 4) {repeat = 4; temp = 0;}
	for(j = 0 ; j < repeat ; j++ ){
		printf("temp :: %d \n\n", temp);
		for(i = 0 ; i < num ; i++ ) {
			if(temp == 0) {if(max < s[i].kor) {max = s[i].kor; subArray = "국어"; top = i;}}
			else if(temp == 1) {if(max < s[i].mat) {max = s[i].mat; subArray = "수학"; top = i;}}
			else if(temp == 2) {if(max < s[i].sci) {max = s[i].sci; subArray = "과학"; top = i;}}
			else if(temp == 3) {if(max < s[i].eng) {max = s[i].eng; subArray = "영어"; top = i;}}
		}
		printf("%s 과목의 1등인 학생의 이름과 성적\n	학번 : %d\n	이름 : %s\n	국어 성적 : %d\n	영어 성적 : %d\n	수학 성적 : %d\n	과학 성적 : %d\n\n", subArray, (s+top) -> num, (s+top) -> name, (s+top) -> kor, (s+top) -> eng, (s+top) -> mat, (s+top) -> sci);
		if(sub == 4) { temp++; max = 0;}
	}
}

int main() {
	struct Student *s = NULL;	//struct Student s[5] = {0,};
	int select;
	int num, i = 0, sub;
	
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
						s = calloc(num+1, sizeof(struct Student)); // 초기화와 동시에 0으로 만들어줌 
						registerStudent(s, num);
						break;
					case 2:
						info(list(s), s);
						break;
				}
				break;
			case 2:
				printf("2-1. 특정 학생의 평균 점수 \n2-2. 전체 학생의 과목 별 평균 점수 \n2-3. 특정 과목의 1등인 학생의 이름 및 성적 \n2-4. 종료 \n");
				scanf("%d", &select);
				switch(select) {
					case 4:
						re = 'n';
						printf("이용해 주셔서 감사합니다.");
						break;
					case 1:
						average(list(s), s);
						break;
					case 2:
						averageAll(num, s); 
						break;						
					case 3:
						printf("조회할 과목을 선택하세요\n1. 국어 2. 수학 3. 과학 4. 영어 5. 전체\n");
						scanf("%d", &sub);
						top(num, s, sub-1);
				}
		}
	}
	free(s);
	return 0;
};
