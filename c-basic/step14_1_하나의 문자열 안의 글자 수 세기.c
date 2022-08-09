#include <stdio.h>

int main(void) {
	char input[1001]; // 1001 개만큼의 문자가 들어갈 수 있는 하나의 문자열 만들어짐
	gets(input); // 문자열 받기 
	int count = 0;
	
	while(input[count] != '\0') {
		count++; // null 만날 때 까지 count 증가 
	}
	
	printf("입력한 문자열의 길이는 %d 입니다 ", count); 
	printf("입력한 문자열은 %s 입니다 ", input); // %s 널값이 나올 때 까지 하나 하나 출력하는 기능 
	return 0; 
}
