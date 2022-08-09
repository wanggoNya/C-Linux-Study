#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char *pc = NULL;
	int i = 0;
	pc = (char *)malloc(100 * sizeof(char)); // 초기화! 
	// 배열과 거의 동일
	// 동적 메모리 할당 또한 char가 100 개 들어갈 공간을 만드는 것
	 
	if(pc == NULL) {
		printf("동적 메모리 할당에 실패\n");
		exit(1); 
	}
	
	// pc가 가르키는 포인터를 1씩 증가시키며 알파벳 소문자를 삽입합니다. 
	for (i = 0 ; i < 26 ; i++) {
		*(pc + i) = 'a' + i;  // a는 아스키코드로 97 번째 // 즉 i가 0일 때 a 가 들어감
		// a를 시작으로 연속된 알파벳 넣음 
	} 
	
	// 1byte *100 -> 연속된 1byte 100개 
	// *pc = 가장 처음 1 byte
	// *pc + 1 = 그 다음 1 byte (사실상 pc[1] 과 같은 의미)  
	
	
	// i가 26일 때 
	// 아스키코드 0은 NULL을 의미합니다. 
	*(pc + i) = 0; // c언어에서의 문자열은 문자의 배열이고, null은 문자의 종료를 의미하므로
	  
	printf("%s\n", pc); 
	
	free(pc);
	
	return 0;
}
