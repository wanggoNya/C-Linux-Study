#include <stdio.h>

// 최소로 줄 수 있는 거스름돈 계산 프로그램 

int smallest(int number) {
	int count = 0;
	while (number >= 50000)	 { // 가장 적은 거스름 화폐 개수 구하기 위한 
		number -= 50000;
		count ++;
	}
	while (number >= 10000)	 {
		number -= 10000;
		count ++;
	}
	while (number >= 5000)	 {
		number -= 5000;
		count ++;
	}
	while (number >= 1000)	 {
		number -= 1000;
		count ++;
	}
	while (number >= 500)	 {
		number -= 500;
		count ++;
	}
	while (number >= 100)	 {
		number -= 100;
		count ++;
	}
	while (number >= 50)	 {
		number -= 50;
		count ++;
	}
	while (number >= 10)	 {
		number -= 10;
		count ++;
	}
	return count; 
}
 
int main(void) {
	int number;
	printf("금액을 입력 :");
	scanf("%d", &number);
	
	printf("최소로 줄 수 있는 거스름 돈은 %d 개 입니다. \n", smallest(number));
	return 0;
}
