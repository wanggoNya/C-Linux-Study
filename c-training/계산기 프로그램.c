#include <stdio.h>
#include <limits.h>

int plus(int a, int b) {
	return a+b;
}

int minus(int a, int b) {
	return a-b;
}

int multiply(int a, int b) {
	return a*b;
}

int divide(int a, int b) {
	return a/b;
}

int main(void) {
	int a;
	int b;
	char cal;
	int result;
	
	printf("수식을 입력하세요. ");
	scanf("%d %c %d", &a, &cal, &b);
	
	if(cal == '+') {
		result = plus(a, b);
	} else if(cal == '-') {
		result = minus(a, b);
	} else if(cal == '*') {
		result = multiply(a, b);
	} else if(cal == '/') {
		result = divide(a, b);
	} else {
		printf("입력 오류 \n");
		return 0; 
	}
	printf("계산 결과 %d %c %d = %d", a, cal, b, result);
}
