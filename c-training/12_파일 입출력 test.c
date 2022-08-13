#include <stdio.h>
#include <string.h>

/* 문제
읽을 파일 입력
해당 파일에서 찾고 싶은 문자열 입력
대소문자 구별 없이 문자열 찾기
모두 대문자로 변경
기존파일명에 _capital 붙여서 파일 쓰기 */

int main(void) {
	FILE *fp;
	char fname[256];
	char fname_capital[256];
	char word[256];
	char buffer[256];
	int i, j = 0, corr_count = 0, corr;

	// 파일 이름 입력
	printf("파일 이름을 입력하세요 : ");
	scanf("%s", fname);
	fname_capital = strcat((strtok(fname, "."))[0], "_capital.txt");

	// 읽기 모드로 열고, buffer 에 문자열 저장
	fp = fopen(fname, "r");

	// 파일 null 일때
	if((fp = fopen(fname, "r")) == NULL) {
		printf("파일 %s 을(를) 여는데 실패했습니다. \n", fname);
		return 0;
	}

	// 찾을 문자열 입력
	printf("파일 열기에 성공했습니다. \n대문자로 변경하고자 하는 문자열을 입력 하세요 : ") ;
	scanf("%s", word);

	// 찾을 문자열의 길이
	int count = 0;
	while(word[count] != '\0') { // null 만날 때 까지 count 증가
		count++;
	}

	FILE *fp_cap = fopen(fname_capital, "w");

	// 파일 읽어오기, while 한 바퀴가 한 줄
	while(fgets(buffer, 256, fp)) { // 읽으면서 buffer에 저장시켜놓기
		corr_count = 0;

		for(j = 0 ; j < (strlen(buffer)-count) ; j ++) {
			j += corr_count;
			corr = 1;
			i = 0;
			while(corr == 1) {
				if(buffer[j] == word[i] || buffer[j] == (word[i]) - 32 || buffer[j] == (word[i]) + 32) {
					corr = 1;
					corr_count ++;
					j ++;
					i ++;
					if(corr_count == count) {
						if(buffer[j] > 96 && buffer[j] < 123) {
							fputs(buffer[j]+32, fp_cap);
						} else {
							fputs(buffer[j], fp_cap);
						}
					}
				} else {
					corr = 0;
					corr_count = 0;
				}
			}
			fputs(buffer[j], fp_cap);
		}
	}

	fclose(fp_cap);
	fclose(fp);
	return 0;
}
