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
		printf("%d ��° ���� ��� : ", i);
		scanf("%s", &e[i-1].id);
		
		printf("%d ��° ���� �μ� : ", i);
		scanf("%s", &e[i-1].department);
		
		printf("%d ��° ���� ���� : ", i);
		scanf("%d", &e[i-1].age);
		
		printf("%d ��° ���� �̸� : ", i);
		scanf("%s", &e[i-1].name);
		
		printf("%d ��° ���� ������ : ", i);
		scanf("%s", &e[i-1].address);
	}
	
	printf("�Է� �Ϸ�"); 
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
	printf("�� �� ���?");
	scanf("%d", &num);
	
	// �Ҵ� ������� 
	e = (struct employee *)malloc(sizeof(struct employee) * num);
//	e = calloc(num + 1, sizeof(struct employee) * num);
	
	registerEmployee(e, num);
	list(e, num);
	
	free(e);
	return 0;
}
