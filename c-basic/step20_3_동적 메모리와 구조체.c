#include <stdio.h>
#include <stdlib.h>

struct Book 
{
	int number;
	char title[100];
};

void showBook(struct Book *p, int n) { // 현재 관리하고 있는 책 정보들을 출력하기 
	int i;
	for(i = 0; i < n; i++ ){
		printf("번호 %d : %s\n", (p + i)->number, (p + i)->title);
	} 
};

int main(void) {
	struct Book *p; // 구조체를 동적 메모리 할당.
	p = (struct Book *)malloc(2 * sizeof(struct Book)); // 총 2개 만큼의 정보가 들어갈 수 있는 구조체를 만듬 
	if(p == NULL) {
		printf("동적 메모리 할당에 실패했습니다. \n");
		exit(1);
	} 
	
	p -> number =1; // p 구조체포인터에 접근하기 위해 화살표 사용 
	strcpy(p -> title, "C programming");
	
	(p + 1) -> number = 2; // 두 번째 구조체에 접근 
	strcpy((p + 1)->title, "data structure");
	free(p);
	return 0;
}
