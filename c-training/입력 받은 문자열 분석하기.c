#include <stdio.h>
#include <string.h>

int main(void) {
	char input[10000];
	printf("���ڿ��� �Է��ϼ��� : ");
	gets(input); // ���ڿ� �ޱ�

	// ���� �� ����
	int count = 0;
	while(input[count] != '\0') { // null ���� �� ���� count ����
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
				printf("Ȯ�� : %d, %d, %d\n", strCount, min, minIndex);
			}
		}
		temp--;
		strCount = 0;
	}

	printf("%s �� �� ���� : %d, �ִ� ��� : %c (%d), �ּ� ��� : %c (%d)", input, count, input[maxIndex], max, input[minIndex], min);
	return 0;
}
// �迭 27�� ���� count �ϱ� 
