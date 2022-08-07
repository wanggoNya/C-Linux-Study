#include <stdio.h>
#include <limits.h>

int main(void) {
	
	int a;
	printf("구구단을 한 줄에 몇 개씩 출력할까요? : ");
	scanf("%d", &a);
	
	char b = a;
	
	printf("%c", b);
	
	while(b < 49 || b > 57) {
		printf("잘못 입력하셨습니다. 다시 입력하세요. \n구구단을 한 줄에 몇 개씩 출력할까요? : ");
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
