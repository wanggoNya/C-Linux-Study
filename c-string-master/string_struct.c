#include <stdio.h>
#include <string.h>

struct employee
{
	char *id;
	char *department;
	int age;
	char *name;
	char *address;
};

struct employee registerEmployee(struct employee *e, int num) {
	int i; 
	
	for(i = 1 ; i <= num ; i++) {
		printf("%d 번째 직원 사번 : ", i);
		scanf("%s", &e[i-1].id);
		
		printf("%d 번째 직원 부서 : ", i);
		scanf("%s", &e[i-1].department);
		
		printf("%d 번째 직원 나이 : ", i);
		scanf("%d", &e[i-1].age);
		
		printf("%d 번째 직원 이름 : ", i);
		scanf("%s", &e[i-1].name);
		
		printf("%d 번째 직원 거주지 : ", i);
		scanf("%s", &e[i-1].address);
	}
	
	printf("입력 완료"); 
//	char *result = (char *)malloc(strlen(e[0]) + strlen(senior));
	
	return e[num];
}

void list(struct employee *e, int num) {
	char *senior = "Senior : ";
	char *junior = "Junior : ";
	
//	char *result = (char *)malloc(strlen(e[0]) + strlen(senior));
}

int main() {
	struct employee *e = NULL;	
	
	int num; 
	printf("몇 명 등록?");
	scanf("%d", &num);
	
	// 할당 해줘야함 
	e = (struct employee *)malloc(sizeof(struct employee) * num);
//	e = calloc(num + 1, sizeof(struct employee) * num);
	
	registerEmployee(e, num);
	list(e, num);
	
	free(e);
	return 0;
}
