#include <stdio.h>
#include <limits.h>

int main(void) {
	
	int a;
	printf("�������� �� �ٿ� �� ���� ����ұ��? : ");
	scanf("%d", &a);
	
	char b = a;
	
	printf("%c", b);
	
	while(b < 49 || b > 57) {
		printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��ϼ���. \n�������� �� �ٿ� �� ���� ����ұ��? : ");
		scanf("%d", &a);
		getchar();
	}
	
	
	int i;
	int j;
	
//	for(i = 2 ; i < 9/((a-48)+(9%(a-48))) ; i++ ) {
//		for(j = a-48 ; j > 0 ; j-- ) {
//			printf("%d X ")
//		}
//	}

}
