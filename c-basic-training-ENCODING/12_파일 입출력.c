#include <stdio.h>
#include <ctype.h>
#include <string.h>

char *strcasestr(const char *haystack, const char *needle) {
	int size = strlen(needle);

	while(*haystack) {
		if(strncasecmp(haystack, needle, size) == 0) {
			return (char *)haystack;
		}
		haystack++;
	}
	return NULL;
}

int main() {
	FILE *fp, *fp_cap;
	char fname[256], temp[256], fname_capital, word[256], buffer[256], *corr, *corrTemp;

	printf("파일 이름을 입력하세요 : ");
	scanf("%s", fname);

	fp = fopen(fname, "r");
	strcpy(temp, fname); // temp에 fname 복사

	if((fp = fopen(fname, "r")) == NULL) {
		fprintf(stderr, "파일 %s 을(를) 여는데 실패했습니다. \n", fname);
		return 0;
	}

	char *namePlus = "_capital.txt"; // 두 번째 파일이름 설정
	char *fnameCut = strtok(temp, "."); // temp에서 문자 . 을 기준으로 문자열 자르기
	strcat(fnameCut, namePlus); // 문자열 붙이기

	printf("파일 열기에 성공했습니다. \n대문자로 변경하고자 하는 문자열을 입력 하세요 : ") ;
	scanf("%s", word);
	int len = (int)strlen(word);
	int i, j;

	fp_cap = fopen(fnameCut, "w");

	// 파일 처음부터 끝까지 읽어보기, 읽으면서 buffer에 저장시키기
	while(fgets(buffer, 256, fp)) { // 문자 가져오기
		corr = strcasestr(buffer, word);

// buffer = 20byte corr 12byte 주소값 
		while(corr != NULL) {
			corrTemp = (char *)malloc(sizeof(char) * 1024); // corrTemp 메모리 할당
			strcpy(corrTemp, corr); // corrTemp에 내용 복사  
			strupr(corrTemp); // 대문자로 변환
			strncpy(corr, corrTemp, strlen(word)); // 글자 수만 corr 로 다시 복사  
			corr ++; // corr에 더해줌 
			corr = strcasestr(corr, word); // 이 줄을 while 문 마지막에 넣어야 오류가 안 남  
		}
		fputs(buffer, fp_cap);
	}
	fclose(fp_cap);
	fclose(fp);
	return 0;
}