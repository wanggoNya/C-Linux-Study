// 사용자 정의 함수

// 시간 더하기 
#include <stdio.h> 

// 전역 변수
int hour;
int minute;
int minuteAdd;

void counter() {
	minute += minuteAdd ;
	hour += minute / 60;
	minute %= 60;
	hour %= 24;
}
 
int main(void) {
	
	printf("시 입력 : ");
	scanf("%d", &hour);
	printf("분 입력 : ");
	scanf("%d", &minute);
	printf("더할 분  입력 : ");
	scanf("%d", &minuteAdd);
	counter();
	
	printf("시간은 %d시 %d 분 입니다", hour, minute);
	
	return 0;
}
