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
	int count = 1;

	while( count < 9 ) {
		for( j = 1 ; j < 10 ; j++ ) { // o X j = ?
			for( i = count ; i < a+count ; i++ ) { // i X o = ?
				if(i == 9) {
					break;
				}
				printf("%d X %d = %d	", i+1, j, (i+1)*j);
			}
			printf("\n");
		}
		count += a;
		printf("\n");
	}
}
