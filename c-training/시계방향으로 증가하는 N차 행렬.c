//# N�� ����� ����� ������
//# �Է� ���� ���� ��ŭ�� ����� ��� �ϰ�, ��� �ȿ��� ���ڸ� 1���� ä���ݴϴ�.
//# ���ڴ� ������ܿ��� �����Ͽ� �ݽð� �������� ���ư��� ���������� ä���ݴϴ�.

#include <stdio.h>
#include <string.h>

int main() {
	int n, max, i, j, x = -1, y = 0, z = 1, num = 1;


	printf("����� ����� ũ�⸦ �Է� �ϼ���: ");

	scanf("%d", &n);
	int arr[n][n];
	memset(arr, 0, n*n*sizeof(int)); // 0 ���� �ʱ�ȭ ;

	max = n;

	while(max > 0) { 
		for(i = 0; i < max; i++) { 
			x = x + z;
			arr[x][y] = num;
			num++;
		}
		max--;

		for(i = 0; i < max; i++) {
			y = y + z;
			arr[x][y] = num;
			num++;
		}
		z *= -1;
	}

	// ��� ���
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			printf("%d	", arr[i][j]);
		}
		printf("\n");
	}
}
