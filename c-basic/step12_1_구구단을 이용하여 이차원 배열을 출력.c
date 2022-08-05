#include <stdio.h>

int main(void) {
	int i, j;
	int ggd[10][10];
	for (i = 1 ; i < 10 ; i ++) {
		printf("%d ´Ü\n\n", i);
		for (j = 1 ; j < 10 ; j ++ ) {
			ggd[i][j] = i * j;
			printf("%d X %d = %d\n\n", i, j, ggd[i][j]);
		}
	}
	return 0;
}
