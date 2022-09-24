#include <stdio.h>
#include <string.h>

int main(void) {
	char input[10000];
	printf("문자열을 입력하세요 : ");
	gets(input); // 문자열 받기

	int alp_count[27] = {0, }; // 빈 배열 생성

	// 글자 수 세기
	int count = 0;
	while(input[count] != '\0') { // null 만날 때 까지 count 증가
		count++;
	}

	char alp = 97, max = 0, min = count-1, i, maxIndex, minIndex;

	while(alp < 123) {
		for(i = 0 ; i < count ; i++ ) {
			if(input[i] == alp || input[i] == (alp - 32)) {
				alp_count[alp-97]++;
			}
		}
		alp++;
	}

	// 최다 & 최소 구하기
	for(i = 0 ; i < 27 ; i++ ) {
		if(alp_count[i] > max) {
			max = alp_count[i];
			maxIndex = i;
		}

		if(alp_count[i] < min && alp_count[i] > 0) {
			min = alp_count[i];
			minIndex = i;
		}
	}

	printf("%s 의 총 길이 : %d, 최다 사용 : %c (%d), 최소 사용 : %c (%d)", input, count, maxIndex + 97, max, minIndex + 97, min);
	return 0;
}
