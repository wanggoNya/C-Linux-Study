#include <stdio.h>
#include <string.h>

int main(void) {
	int x, y;

	printf("����� ����� ũ�⸦ �Է� �ϼ���: ");
	scanf("%d %d", &x, &y);

	char arr[x][y];
	memset(arr, 0, x*y*sizeof(char)); // 0 ���� �ʱ�ȭ ;

	char alp = 97;

	int i, j;
	
	
	for(i = 0 ; i < x ; i++ ) {
		for(j = 0 ; j < y ; j++ ) {
			arr[i][j] = alp;
			alp++;
		}
	}

	// ��� ���
	for(i = 0; i < x; i++) {
		for(j = 0; j < y; j++) {
			printf("%c	", arr[i][j]);
		}
		printf("\n");
	}
	
	// ù ��° �迭����� �����͸� ������ ������ �����Ѵ�.
//	arrP = &arr[0][0];
	
	 
	printf("�� ��° ���� �˷��帱���? : ");
	int num;
	scanf("%d", num);
	printf("%d ��° ���� [%c] �Դϴ�.\n", num, 96 + num);
}
