// ����Լ��� �̿��� ���� ���غ���
#include <stdio.h>

// ����
// nCr�� r �� 0 �̰ų� n �̶�� 1�̸�, nCr(n - 1, r - 1) + nCr(n - 1, r)�� ����.  

int nCr(int n, int r)  {
	if(n == 0 || r == n) {
		return 1;
	} else {
		return nCr(n - 1, r - 1) + nCr(n - 1, r);
	}
}

int main(void) {
	int n, r;
	printf("n �� r �Է� : ");
	scanf("%d %d", &n,  &r);
	printf("%d", nCr(n, r)); 
	return 0;
}
