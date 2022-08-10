#include <stdio.h>
#include <string.h>

int main(void) {
	char input[10000];
	printf("문자열을 입력하세요 : ");
	gets(input); // 문자열 받기

	// 글자 수 세기
	int count = 0;
	while(input[count] != '\0') { // null 만날 때 까지 count 증가
		count++;
	}
	char inputOne[1], inputTwo[1];
	int temp = count-1, strCount = 0, max = 0, min = count-1, minTemp, i, maxIndex, minIndex;

	while(temp > 0) {
		for(i = 0 ; i < count ; i++ ) {
			inputOne[0] = input[i];
			inputTwo[0] = input[temp];
			if(strcasecmp(inputOne, inputTwo) == 0) {
				strCount++;
			}
			if(max < strCount) {
				max = strCount;
				maxIndex = temp;
			}
			if(min > strCount) {
				min = strCount;
				minIndex = temp;
				printf("확인 : %d, %d, %d\n", strCount, min, minIndex);
			}
		}
		temp--;
		strCount = 0;
	}

	printf("%s 의 총 길이 : %d, 최다 사용 : %c (%d), 최소 사용 : %c (%d)", input, count, input[maxIndex], max, input[minIndex], min);
	return 0;
}
// 배열 27개 만들어서 count 하기 
