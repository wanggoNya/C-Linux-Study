#include <stdio.h>

/* 문제
읽을 파일 입력
해당 파일에서 찾고 싶은 문자열 입력
대소문자 구별 없이 문자열 찾기
모두 대문자로 변경
기존파일명에 _capital 붙여서 파일 쓰기 */

int main(void) {
//	FILE *fp = NULL;
	FILE *fp;
	char fname[256];
	char word[256];
	char buffer[256];
	int line = 0;

	printf("파일 이름을 입력하세요 : ");
	scanf("%s", fname);

	fp = fopen("a.txt", "w");

	if((fp = fopen(fname, "r")) = NULL) {
		printf(stderr. "파일 %s 을(를) 여는데 실패했습니다. \n", fname);
		return 0;
	}

	printf("파일 열기에 성공했습니다. \n대문자로 변경하고자 하는 문자열을 입력 하세요 : ") ;
	scanf("%s", word);

	// 파일 처음부터 끝까지 읽어보기, 읽으면서 buffer에 저장시키기
	while(fgets(buffer, 256, fp)) {
		line++;
		if(stristr(buffer, word)) { // buffer에 word가 포함되어 있다면
			// 대문자로 변경하여 저장
			
			
		}
	}
	
	fclose(fp);
	return 0;
}
