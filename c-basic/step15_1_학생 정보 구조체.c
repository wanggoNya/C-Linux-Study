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
//	strcpy(s.name, "김수연");
//	s.grade = 4.5;
	
	
	printf("학번을 입력 : ");
	scanf("%d", &s.number);
	
	printf("이름을 입력 : ");
	scanf("%s", s.name); // 배열은 그 자체로 포인터의 의미를 가지고 있고 그 자체로 주소의 의미임 
	
	printf("학점을 입력 : ");
	scanf("%lf", &s.grade); // 입력 받을 때 lf 라고 해줘야함 
	
	printf("학번 : %d\n", s.number);
	printf("이름 : %s\n", s.name); 
	printf("학점 : %.1f\n", s.grade); 
	return 0;
}
