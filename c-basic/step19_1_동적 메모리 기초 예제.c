#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int *pi; // pointer integer
	pi = (int *)malloc(sizeof(int)); // malloc = �޸𸮸� �Ҵ��ض�.
	// (int *) �� ��ȭ .  
	// sizeof(int) ��ŭ�� ũ�⸦ �Ҵ��ض� 
	// pi�� �� ��ġ�� ����ϰ� �ϴ� �� (�޸� ��ġ, �� �ּ�)
	// ���߿� pi�� �̿��� �Ҵ�� int �� ���� ��ü�ϰų� �� �� ����. 
	
	if(pi == NULL) {
		prinf("���� �޸� �Ҵ翡 ���� \n");
		exit(1);
	}
	
	*pi = 100;
	printf("%d\n", *pi);
	
	// ���� �޸𸮸� ����� ���Ŀ��� ������ �ش� �޸𸮸� ��ȯ�մϴ�. ! �߿�
	free(pi); // pi�� ����Ű�� �ִ� �κ� (  (int *)malloc(sizeof(int))  ) �� �κп� ���� �޸� �ּ� ���� 
	 
	
	return 0; 
}
