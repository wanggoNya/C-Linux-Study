#include <stdio.h>

int main(void) {
	FILE *fp;
	char fname[256];
	char buffer[256];
	char word[256];
	int line = 0;
	
	// �� ���� �̸�  
	printf("���� �̸��� �Է��ϼ��� : "); 
	scanf("%s", fname); 
	
	// Ž���� �ܾ� �Է� 
	printf("Ž���� �ܾ �Է��ϼ��� : "); // �ܾ �˻� 
	scanf("%s", word);
	
	// ���� ������ ���� �� ������ �ִٸ�  
	if((fp = fopen(fname, "r")) =NULL) {
		fprintf(stderr. "���� %s�� �� �� �����ϴ�.", fname);
		return 0;
	} 
	
	// ���� ó������ ������ �о�� 
	while(fgets(buffer, 256, fp)) { // �����鼭 buffer�� ������ѳ��� 
	// 256(����)		 
		line++;
		if(strstr(buffer, word)) { // buffer�� ���ԵǾ� �ִٸ�  
			printf("���� %d : �ܾ� %s��(��) �߰ߵǾ����ϴ�. \n", line, word);
		}
	}
	
	fclose(fp);
	return 0;
} 
