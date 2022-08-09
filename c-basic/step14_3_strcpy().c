#include <stdio.h>
#include <string.h>

int main(void) {
	char input[10] = "I Love You";
	char result[5] = "Love";
	strcpy(result, input);
	printf("문자열 복사 : %s\n", result);
	// 글자수가 달라도 복사 가능 
	return 0;
}
