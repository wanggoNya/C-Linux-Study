#include <stdio.h>
#include <stdlib.h>

struct Book 
{
	int number;
	char title[100];
};

void showBook(struct Book *p, int n) { // ���� �����ϰ� �ִ� å �������� ����ϱ� 
	int i;
	for(i = 0; i < n; i++ ){
		printf("��ȣ %d : %s\n", (p + i)->number, (p + i)->title);
	} 
};

int main(void) {
	struct Book *p; // ����ü�� ���� �޸� �Ҵ�.
	p = (struct Book *)malloc(2 * sizeof(struct Book)); // �� 2�� ��ŭ�� ������ �� �� �ִ� ����ü�� ���� 
	if(p == NULL) {
		printf("���� �޸� �Ҵ翡 �����߽��ϴ�. \n");
		exit(1);
	} 
	
	p -> number =1; // p ����ü�����Ϳ� �����ϱ� ���� ȭ��ǥ ��� 
	strcpy(p -> title, "C programming");
	
	(p + 1) -> number = 2; // �� ��° ����ü�� ���� 
	strcpy((p + 1)->title, "data structure");
	free(p);
	return 0;
}
