#include <stdio.h>
#include <string.h>

/* ����
���� ���� �Է�
�ش� ���Ͽ��� ã�� ���� ���ڿ� �Է�
��ҹ��� ���� ���� ���ڿ� ã��
��� �빮�ڷ� ����
�������ϸ� _capital �ٿ��� ���� ���� */

int main(void) {
	FILE *fp;
	char fname[256];
	char fname_capital[256];
	char word[256];
	char buffer[256];
	int i, j = 0, corr_count = 0, corr;

	// ���� �̸� �Է�
	printf("���� �̸��� �Է��ϼ��� : ");
	scanf("%s", fname);
	fname_capital = strcat((strtok(fname, "."))[0], "_capital.txt");

	// �б� ���� ����, buffer �� ���ڿ� ����
	fp = fopen(fname, "r");

	// ���� null �϶�
	if((fp = fopen(fname, "r")) == NULL) {
		printf("���� %s ��(��) ���µ� �����߽��ϴ�. \n", fname);
		return 0;
	}

	// ã�� ���ڿ� �Է�
	printf("���� ���⿡ �����߽��ϴ�. \n�빮�ڷ� �����ϰ��� �ϴ� ���ڿ��� �Է� �ϼ��� : ") ;
	scanf("%s", word);

	// ã�� ���ڿ��� ����
	int count = 0;
	while(word[count] != '\0') { // null ���� �� ���� count ����
		count++;
	}

	FILE *fp_cap = fopen(fname_capital, "w");

	// ���� �о����, while �� ������ �� ��
	while(fgets(buffer, 256, fp)) { // �����鼭 buffer�� ������ѳ���
		corr_count = 0;

		for(j = 0 ; j < (strlen(buffer)-count) ; j ++) {
			j += corr_count;
			corr = 1;
			i = 0;
			while(corr == 1) {
				if(buffer[j] == word[i] || buffer[j] == (word[i]) - 32 || buffer[j] == (word[i]) + 32) {
					corr = 1;
					corr_count ++;
					j ++;
					i ++;
					if(corr_count == count) {
						if(buffer[j] > 96 && buffer[j] < 123) {
							fputs(buffer[j]+32, fp_cap);
						} else {
							fputs(buffer[j], fp_cap);
						}
					}
				} else {
					corr = 0;
					corr_count = 0;
				}
			}
			fputs(buffer[j], fp_cap);
		}
	}

	fclose(fp_cap);
	fclose(fp);
	return 0;
}
