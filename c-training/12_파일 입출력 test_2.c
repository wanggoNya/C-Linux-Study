#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
	FILE *fp;
	char fname[256];
	char word[256];
	char buffer[256];

	printf("파일 이름을 입력하세요 : ");
	scanf("%s", fname);

	fp = fopen(fname, "w");

	if((fp = fopen(fname, "r")) == NULL) {
		fprintf(stderr, "파일 %s 을(를) 여는데 실패했습니다. \n", fname);
		return 0;
	}

	printf("파일 열기에 성공했습니다. \n대문자로 변경하고자 하는 문자열을 입력 하세요 : ") ;
	scanf("%s", word);

	// 파일 처음부터 끝까지 읽어보기, 읽으면서 buffer에 저장시키기
	while(fgets(buffer, 256, fp)) {
		
	}
	
	fclose(fp);
	return 0;
	//toupper(문자열);
	 
}
