#include <stdio.h>
#include <limits.h>

int main(void) {
	
	int a;
	printf("�������� �� �ٿ� �� ���� ����ұ��? : ");
	scanf("%d", &a);
	
	while(!(a > 0) || !(a < INT_MAX)) {
		printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��ϼ���. \n�������� �� �ٿ� �� ���� ����ұ��? : ");
		scanf("%d", &a);
		getchar();
	}
	
	int i;
	int j;
	int k;
	
	for( k = 1 ; k < 9 ; k++ ) {
		for( j = 1 ; j < 9 ; j++ ) {
			for( i = 2 ; i > 0 ; i-- ) {
				printf("%d X %d = %d	", i, j, i*j);	
			}
		}
		printf("\n");
	}
	
	
}
