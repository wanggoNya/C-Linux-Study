#include <stdio.h>
#include <string.h>

int main(void) {
	char input[10000];
	printf("���ڿ��� �Է��ϼ��� : ");
	gets(input); // ���ڿ� �ޱ�

	int alp_count[27] = {0, }; // �� �迭 ����

	// ���� �� ����
	int count = 0;
	while(input[count] != '\0') { // null ���� �� ���� count ����
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

	// �ִ� & �ּ� ���ϱ�
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

	printf("%s �� �� ���� : %d, �ִ� ��� : %c (%d), �ּ� ��� : %c (%d)", input, count, maxIndex + 97, max, minIndex + 97, min);
	return 0;
}
