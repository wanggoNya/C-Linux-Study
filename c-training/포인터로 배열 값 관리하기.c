#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int x, y, i, j, count, num;

	printf("����� ����� ũ�⸦ �Է� �ϼ���: ");
	scanf("%d %d", &y, &x);

	// �޸� �Ҵ�, �迭�� ���� ����
	// ���� �޸� �Ҵ� 2���� �迭 �� ������ ����� ��
	char ** pptr = (char**)malloc(sizeof(char*) * y);

	// 2���� �迭 ����
	for(i = 0 ; i < y ; i++ ) {
		*(pptr + i) = (char *)malloc(sizeof(char) * x);
	}

	count = 0 ;
	for(i = 0 ; i < x ; i++ ) {
		for(j = 0 ; j < y ; j++ ) {
			*(*(pptr + i) + j) = 97 + count;
			count++;
			if(count == 27) {
				break;
			}
			printf("%3c", *(*(pptr + i) + j));
		}
		printf("\n");
		if(count == 27) {
			break;
		}
	}

	printf("�� ��° ���� �˷��帱���? : ");
	scanf("%d", &num);

	count = 1;
	for(i = 0 ; i < x ; i++ ) {
		for(j = 0 ; j < y ; j++ ) {
			if(count == num) {
				printf("%3c", *(*(pptr + i) + j) - 32);
				for(i = 0 ; i < x ; i++) {
					free(*(pptr + y));
					return 0;
				}
			}
			count++;
		}
	}

	// �޸� ����
	for(i = 0 ; i < x ; i++) {
		free(*(pptr + y));
	}

	return 0;
}
