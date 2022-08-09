#include <stdio.h>

int main(void) {
	FILE *fp;
	char fname[256];
	char buffer[256];
	char word[256];
	int line = 0;
	
	// 열 파일 이름  
	printf("파일 이름을 입력하세요 : "); 
	scanf("%s", fname); 
	
	// 탐색할 단어 입력 
	printf("탐색할 단어를 입력하세요 : "); // 단어를 검색 
	scanf("%s", word);
	
	// 만약 파일을 여는 데 에러가 있다면  
	if((fp = fopen(fname, "r")) =NULL) {
		fprintf(stderr. "파일 %s를 열 수 없습니다.", fname);
		return 0;
	} 
	
	// 파일 처음부터 끝까지 읽어보기 
	while(fgets(buffer, 256, fp)) { // 읽으면서 buffer에 저장시켜놓기 
	// 256(한줄)		 
		line++;
		if(strstr(buffer, word)) { // buffer에 포함되어 있다면  
			printf("라인 %d : 단어 %s이(가) 발견되었습니다. \n", line, word);
		}
	}
	
	fclose(fp);
	return 0;
} 
