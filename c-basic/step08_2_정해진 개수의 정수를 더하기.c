// ������ ������ ������ ���ϱ�

#include <stdio.h> 

int main(void) {
	int number, x, i, sum = 0;
	printf("������ ������ �Է� : ");
	scanf("%d", &number);
	for(i = 0 ; i < number ; i++) {
		printf("������ ���� �Է� : " );
		scanf("%d", &x) ;     
		sum += x;
		printf("��������� ����???  %d\n", sum);
	}
	
	printf("��ü ������ ���� %d �Դϴ�. \n", sum);
	return 0;
}
