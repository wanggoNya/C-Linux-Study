#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
	FILE *fp;
	char fname[256];
	char word[256];
	char buffer[256];

	printf("���� �̸��� �Է��ϼ��� : ");
	scanf("%s", fname);

	fp = fopen(fname, "w");

	if((fp = fopen(fname, "r")) == NULL) {
		fprintf(stderr, "���� %s ��(��) ���µ� �����߽��ϴ�. \n", fname);
		return 0;
	}

	printf("���� ���⿡ �����߽��ϴ�. \n�빮�ڷ� �����ϰ��� �ϴ� ���ڿ��� �Է� �ϼ��� : ") ;
	scanf("%s", word);

	// ���� ó������ ������ �о��, �����鼭 buffer�� �����Ű��
	while(fgets(buffer, 256, fp)) {
		
	}
	
	fclose(fp);
	return 0;
	//toupper(���ڿ�);
	 
}
