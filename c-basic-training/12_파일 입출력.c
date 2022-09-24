#include <stdio.h>
#include <ctype.h>
#include <string.h>

char *strcasestr(const char *haystack, const char *needle) {
	int size = strlen(needle);

	while(*haystack) {
		if(strncasecmp(haystack, needle, size) == 0) {
			return (char *)haystack;
		}
		haystack++;
	}
	return NULL;
}

int main() {
	FILE *fp, *fp_cap;
	char fname[256], temp[256], fname_capital, word[256], buffer[256], *corr, *corrTemp;

	printf("���� �̸��� �Է��ϼ��� : ");
	scanf("%s", fname);

	fp = fopen(fname, "r");
	strcpy(temp, fname); // temp�� fname ����

	if((fp = fopen(fname, "r")) == NULL) {
		fprintf(stderr, "���� %s ��(��) ���µ� �����߽��ϴ�. \n", fname);
		return 0;
	}

	char *namePlus = "_capital.txt"; // �� ��° �����̸� ����
	char *fnameCut = strtok(temp, "."); // temp���� ���� . �� �������� ���ڿ� �ڸ���
	strcat(fnameCut, namePlus); // ���ڿ� ���̱�

	printf("���� ���⿡ �����߽��ϴ�. \n�빮�ڷ� �����ϰ��� �ϴ� ���ڿ��� �Է� �ϼ��� : ") ;
	scanf("%s", word);
	int len = (int)strlen(word);
	int i, j;

	fp_cap = fopen(fnameCut, "w");

	// ���� ó������ ������ �о��, �����鼭 buffer�� �����Ű��
	while(fgets(buffer, 256, fp)) { // ���� ��������
		corr = strcasestr(buffer, word);

// buffer = 20byte corr 12byte �ּҰ� 
		while(corr != NULL) {
			corrTemp = (char *)malloc(sizeof(char) * 1024); // corrTemp �޸� �Ҵ�
			strcpy(corrTemp, corr); // corrTemp�� ���� ����  
			strupr(corrTemp); // �빮�ڷ� ��ȯ
			strncpy(corr, corrTemp, strlen(word)); // ���� ���� corr �� �ٽ� ����  
			corr ++; // corr�� ������ 
			corr = strcasestr(corr, word); // �� ���� while �� �������� �־�� ������ �� ��  
		}
		fputs(buffer, fp_cap);
	}
	fclose(fp_cap);
	fclose(fp);
	return 0;
}
