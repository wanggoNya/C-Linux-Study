#include <stdio.h>
#include <string.h>

int main(void) {
	char input[10000];
	printf("���ڿ��� �Է��ϼ��� : ");
	gets(input); // ���ڿ� �ޱ�

	int alp_count[27] = {0, };

	// ���� �� ����
	int count = 0;
	while(input[count] != '\0') { // null ���� �� ���� count ����
		count++;
	}

	int alp = 97, strCount = 0, max = 0, min = count-1, minTemp, i, maxIndex, minIndex;

	while(alp < 122) {
		for(i = 0 ; i < count ; i++ ) {
			if(input[i] == )
		}
	}


	printf("%s �� �� ���� : %d, �ִ� ��� : %c (%d), �ּ� ��� : %c (%d)", input, count, input[maxIndex], max, input[minIndex], min);
	return 0;
}
// �迭 27�� ���� count �ϱ�
