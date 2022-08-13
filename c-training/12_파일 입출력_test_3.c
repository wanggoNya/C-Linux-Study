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
	FILE *fp;
	FILE *fp_cap;
	char fname[256];
	char fname_capital;
	char word[256];
	char buffer[256];
	char *corr;

	printf("���� �̸��� �Է��ϼ��� : ");
	scanf("%s", fname);

	fp = fopen(fname, "r");
	
	if((fp = fopen(fname, "r")) == NULL) {
		fprintf(stderr, "���� %s ��(��) ���µ� �����߽��ϴ�. \n", fname);
		return 0;
	}
	
	char *namePlus = "_capital.txt";
	char *fnameCut = strtok(fname, ".");
	fname_capital = strcat(fnameCut, namePlus);
	
	printf("fname : %s\n", fname); 
	printf("fnameCut : %s\n", fnameCut); 
	printf("%s\n", fname_capital);


	printf("���� ���⿡ �����߽��ϴ�. \n�빮�ڷ� �����ϰ��� �ϴ� ���ڿ��� �Է� �ϼ��� : ") ;
	scanf("%s", word);

	// ���� ó������ ������ �о��, �����鼭 buffer�� �����Ű��
	while(fgets(buffer, 256, fp)) {
		printf("%d\n", 234);
		corr = strcasestr(buffer, word);
		printf("%s\n", corr);
		
		while (corr != NULL) {              // �˻��� ���ڿ��� ���� ������ �ݺ�
			printf("%s\n", corr);           // �˻��� ���ڿ� ���
			corr = strcasestr(buffer + 1, word);  // den �����Ϳ� 1�� ���Ͽ� e���� �˻�
		}
	}
	
//	fp_cap = fopen(fname_capital, "w");
//	while () {
//		fputs();
//	}



	fclose(fp_cap);
	fclose(fp);
	return 0;
	//toupper(���ڿ�);
}
