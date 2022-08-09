#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int *pi; // pointer integer
	pi = (int *)malloc(sizeof(int)); // malloc = 메모리를 할당해라.
	// (int *) 형 변화 .  
	// sizeof(int) 만큼의 크기를 할당해라 
	// pi에 그 위치를 기억하게 하는 것 (메모리 위치, 즉 주소)
	// 나중에 pi를 이용해 할당된 int 의 값을 교체하거나 할 수 있음. 
	
	if(pi == NULL) {
		prinf("동적 메모리 할당에 실패 \n");
		exit(1);
	}
	
	*pi = 100;
	printf("%d\n", *pi);
	
	// 동적 메모리를 사용한 이후에는 무조건 해당 메모리를 반환합니다. ! 중요
	free(pi); // pi가 가리키고 있는 부분 (  (int *)malloc(sizeof(int))  ) 이 부분에 대한 메모리 주소 해제 
	 
	
	return 0; 
}
