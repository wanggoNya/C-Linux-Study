#include <stdio.h>
#include <string.h>

int main(void) {
	char inputOne[5] = "A";
	char inputTwo[5] = "B";
	printf("문자열 비교 : %d\n", strcmp(inputOne, inputTwo)); 
	
	// strcmp 는 두 문자가 사전적으로 동일하면 0,
	// 왼쪽이 사전적으로 앞에 있다면 -1, 오른쪽이 앞에 있다면 1을 반환 하는 함수  
	return 0;
}
