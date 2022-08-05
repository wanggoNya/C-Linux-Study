#include <stdio.h>
int main (void) {

	int score = 85;

	if(score >= 90) {
		printf("학점 A\n");
	} else if(score >= 80) {
		printf("학점 B\n");
	} else if(score >= 70) {
		printf("학점 C\n");
	} else {
		printf("학점 D\n");
	}
}
