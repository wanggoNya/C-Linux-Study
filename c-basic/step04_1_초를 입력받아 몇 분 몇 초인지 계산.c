#include <stdio.h>
#define SECOND_PER_MINUTE 60

// 초 입력받아 몇분 몇초인지 계산 
int main(void)
{
	int input = 1000;
	int minute = input / SECOND_PER_MINUTE; 
	int second = input % SECOND_PER_MINUTE;
	printf("%d초 %d분 %d초 입니다. \n", input, minute, second);
	return 0;
}
