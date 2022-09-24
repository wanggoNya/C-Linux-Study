#include <stdio.h>

/*
# 반복문과 조건문을 사용하여 아래 모양을 출력하는 코드를 작성 해 보세요. 
. . . . A . . . . 5 10-65-60
. . . B . B . . . 4 6 10-66-60
. . C . . . C . . 3 7 
. D . . . . . D . 2 8
E . . . . . . . E 1 9
. D . . . . . D . 
. . C . . . C . .
. . . B . B . . .
. . . . A . . . .
*/

int main(void) {
	
	char diamond = 65;
	int i;
	int j;
	int k;
	
	for(k = 0 ; k < 5 ; k++ ) {
		
		i = diamond - 60;
		
		for(j = 0 ; j < 9 ; j++ ) {
			
			if(j == i-1 || j == (10 - i-1)) {
				printf("%c ", diamond);
			} else {
				printf(". ", stdout);
			}
			
		}
		printf("\n", stdout);
		diamond++;
	}
	
	diamond = 68;
	for(k = 0 ; k < 4 ; k++ ) {
		i = diamond - 60;
	
		for(j = 0 ; j < 9 ; j++ ) {
			
			if(j == i-1 || j == (10 - i-1)) {
				printf("%c ", diamond);
			} else {
				printf(". ", stdout);
			}
			
		}
		printf("\n", stdout);
		diamond--;
	}
}
