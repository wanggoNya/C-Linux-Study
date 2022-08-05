// 재귀함수를 이용해 조합 구해보기
#include <stdio.h>

// 조합
// nCr은 r 이 0 이거나 n 이라면 1이며, nCr(n - 1, r - 1) + nCr(n - 1, r)과 같다.  

int nCr(int n, int r)  {
	if(n == 0 || r == n) {
		return 1;
	} else {
		return nCr(n - 1, r - 1) + nCr(n - 1, r);
	}
}

int main(void) {
	int n, r;
	printf("n 과 r 입력 : ");
	scanf("%d %d", &n,  &r);
	printf("%d", nCr(n, r)); 
	return 0;
}
