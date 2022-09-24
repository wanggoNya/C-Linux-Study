//# N차 행렬을 출력해 보세요
//# 입력 받은 숫자 만큼의 행렬을 출력 하고, 행렬 안에는 숫자를 1부터 채워줍니다.
//# 숫자는 좌측상단에서 시작하여 반시계 방향으로 돌아가며 순차적으로 채워줍니다.

#include <stdio.h>
#include <string.h> // memset 사용을 위한 헤더 

int main() {
	int n, max, i, j, x = -1, y = 0, z = 1, num = 1; // 변수 선언 


	printf("출력할 행렬의 크기를 입력 하세요: ");

	scanf("%d", &n); 
	int arr[n][n]; // 입력받은 숫자만큼의 크기로 2차원 배열 생 
	memset(arr, 0, n*n*sizeof(int)); // 배열 0 으로 초기화 ;

	max = n; // max에 최대 크기 (입력 받은 숫자) 설정  

	while(max > 0) { // max 가 0 이상일 때 while 반복 
		for(i = 0; i < max; i++) {  // 행 입력을 위한 반복문 
			x = x + z; // 행 1씩 증가 // += 1 하지 않은 이유?? 감소하는 구간도 있어서! 
			arr[x][y] = num; // 배열에 숫자 할당 1부터 1씩 증가 
			num++;
		}
		max--; // max 1씩 감소 ( 

		for(i = 0; i < max; i++) { // 열 입력을 위한 반복문 
			y = y + z; // 열 1씩 증가 
			arr[x][y] = num; // 배열에 숫자 할당 위에서 이어 받아서 계속 1씩 증가 
			num++;
		}
		z *= -1; // 위로 진행, 왼쪽으로 진행하는 경우는 숫자가 감소하므로 z에 -1을 할당 
	}

	// 행렬 출력
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			printf("%d	", arr[i][j]);
		}
		printf("\n");
	}
}
