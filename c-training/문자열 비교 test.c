#include <stdio.h>
#include <string.h>

int main(void) {
	char input[10000];
	printf("문자열을 입력하세요 : ");
	gets(input); // 문자열 받기

	int alp_count[27] = {0, };

	// 글자 수 세기
	int count = 0;
	while(input[count] != '\0') { // null 만날 때 까지 count 증가
		count++;
	}

	int alp = 97, strCount = 0, max = 0, min = count-1, minTemp, i, maxIndex, minIndex;

	while(alp < 122) {
		for(i = 0 ; i < count ; i++ ) {
			if(input[i] == )
		}
	}


	printf("%s 의 총 길이 : %d, 최다 사용 : %c (%d), 최소 사용 : %c (%d)", input, count, input[maxIndex], max, input[minIndex], min);
	return 0;
}
// 배열 27개 만들어서 count 하기
