#include <stdio.h>
#include <stdlib.h>

int main(void) {
	
	int count;
	printf("�ֻ����� �� �� �������?? : ");
	scanf("%d", &count);
	
	float temp = count;
	int dice[6][2] = {0, };

	while(count > 0) {
		int index = (rand() % 6)+1;
		dice[index-1][1] += 1;
		count--;
	}

	int i;
	for(i = 1 ; i < 7 ; i++ ) {
		float percent = (dice[i-1][1]/temp) * 100;
		printf("%d�� : %d (%.0f %%)\n", i, dice[i-1][1], percent);
	}
}
