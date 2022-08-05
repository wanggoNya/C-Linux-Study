// 특정한 문자열을 재귀 함수 반복 출력하기
#include <stdio.h>  

// 재귀 함수 (Recursive Function) 
void print(int count) {
	if(count == 0) {
		return ;
	} else {
		printf("문자열 출력 \n");
		print(count -1 );
	}
}
int main(void ) {
	int number;
	printf("문자열을 몇 개 출력할까요?");
	scanf("%d", &number);
	print(number);
	return 0;
}
