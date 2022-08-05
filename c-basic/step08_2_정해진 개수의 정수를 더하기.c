// 정해진 개수의 정수를 더하기

#include <stdio.h> 

int main(void) {
	int number, x, i, sum = 0;
	printf("정수의 개수를 입력 : ");
	scanf("%d", &number);
	for(i = 0 ; i < number ; i++) {
		printf("정수의 값을 입력 : " );
		scanf("%d", &x) ;     
		sum += x;
		printf("현재까지의 합은???  %d\n", sum);
	}
	
	printf("전체 정수의 값은 %d 입니다. \n", sum);
	return 0;
}
