#include <stdio.h>

int main ()  
{
	int score[5][2]; // 총 5명의 점수,  
	int total[2] = { 0, }; // total 이라는 array에 모두 0이라는 값을 할당하겠다는 의미  
	int i;
	
	for(i = 0 ; i < 5 ; i++ ) 
	{
		printf("%d번 학생의 수학, 영어 점수 : ", i+1);
		scanf("%d %d", &score[i][0], &score[i][1]);
	}
	
	for(i = 0 ; i < 5 ; i++ ) 
	{
		total[0] += score[i][0];
		total[1] += score[i][1];
	}
	
	printf("\n\n5명의 수학 점수 합계 : %d\n", total[0]);
   printf("5명의 영어 점수 합계 : %d\n",total[1]);
	return 0;
}

