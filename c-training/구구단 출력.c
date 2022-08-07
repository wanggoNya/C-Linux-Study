#include <stdio.h>
#include <limits.h>

int main(void) {
	
	int a;
	printf("구구단을 한 줄에 몇 개씩 출력할까요? : ");
	scanf("%d", &a);
	
	while(!(a > 0) || !(a < INT_MAX)) {
		printf("잘못 입력하셨습니다. 다시 입력하세요. \n구구단을 한 줄에 몇 개씩 출력할까요? : ");
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
