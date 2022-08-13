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
	FILE *fp;
	FILE *fp_cap;
	char fname[256];
	char fname_capital;
	char word[256];
	char buffer[256];
	char *corr;

	printf("파일 이름을 입력하세요 : ");
	scanf("%s", fname);

	fp = fopen(fname, "r");
	
	if((fp = fopen(fname, "r")) == NULL) {
		fprintf(stderr, "파일 %s 을(를) 여는데 실패했습니다. \n", fname);
		return 0;
	}
	
	char *namePlus = "_capital.txt";
	char *fnameCut = strtok(fname, ".");
	fname_capital = strcat(fnameCut, namePlus);
	
	printf("fname : %s\n", fname); 
	printf("fnameCut : %s\n", fnameCut); 
	printf("%s\n", fname_capital);


	printf("파일 열기에 성공했습니다. \n대문자로 변경하고자 하는 문자열을 입력 하세요 : ") ;
	scanf("%s", word);

	// 파일 처음부터 끝까지 읽어보기, 읽으면서 buffer에 저장시키기
	while(fgets(buffer, 256, fp)) {
		printf("%d\n", 234);
		corr = strcasestr(buffer, word);
		printf("%s\n", corr);
		
		while (corr != NULL) {              // 검색된 문자열이 없을 때까지 반복
			printf("%s\n", corr);           // 검색된 문자열 출력
			corr = strcasestr(buffer + 1, word);  // den 포인터에 1을 더하여 e부터 검색
		}
	}
	
//	fp_cap = fopen(fname_capital, "w");
//	while () {
//		fputs();
//	}



	fclose(fp_cap);
	fclose(fp);
	return 0;
	//toupper(문자열);
}
