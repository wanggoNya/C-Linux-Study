#include <stdio.h>

/* ����
���� ���� �Է�
�ش� ���Ͽ��� ã�� ���� ���ڿ� �Է�
��ҹ��� ���� ���� ���ڿ� ã��
��� �빮�ڷ� ����
�������ϸ� _capital �ٿ��� ���� ���� */

int main(void) {
//	FILE *fp = NULL;
	FILE *fp;
	char fname[256];
	char word[256];
	char buffer[256];
	int line = 0;

	printf("���� �̸��� �Է��ϼ��� : ");
	scanf("%s", fname);

	fp = fopen("a.txt", "w");

	if((fp = fopen(fname, "r")) = NULL) {
		printf(stderr. "���� %s ��(��) ���µ� �����߽��ϴ�. \n", fname);
		return 0;
	}

	printf("���� ���⿡ �����߽��ϴ�. \n�빮�ڷ� �����ϰ��� �ϴ� ���ڿ��� �Է� �ϼ��� : ") ;
	scanf("%s", word);

	// ���� ó������ ������ �о��, �����鼭 buffer�� �����Ű��
	while(fgets(buffer, 256, fp)) {
		line++;
		if(stristr(buffer, word)) { // buffer�� word�� ���ԵǾ� �ִٸ�
			// �빮�ڷ� �����Ͽ� ����
			
			
		}
	}
	
	fclose(fp);
	return 0;
}
