#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#define BYTES_TO_KB 1024

// char: 1 byte, short: 2 byte, int: 4 byte, long: 4 byte, long long: 8 byte
// �Ҵ�� �� �޸� �ѷ�, ���� ���� �ʰ� ������� �޸� �ѷ�, ������ �޸� �ѷ�
int allocate(void) {
	int *intAlct;
	char *charAlct;
	int type;
	int size;
	int sizeAlct;

	MEMORYSTATUSEX statex;
 
    statex.dwLength = sizeof(statex); // �ʱ� �Է� ��(����ü ũ��)
 
    GlobalMemoryStatusEx(&statex);
 	
    
	printf("�Ҵ��� �ڷ��� �����ϼ���.\n1. int �� \n2. char�� \n");
	scanf("%d", &type);
	printf("��ŭ �Ҵ��Ͻðھ��?");
	scanf("%d", &size);
	
	switch(type) {
		case 1:
			intAlct = (int *)malloc(size * sizeof(int));
			sizeAlct = size * sizeof(int);
			break;
		case 2:
			charAlct = (char *)malloc(size * sizeof(char));
			sizeAlct = size * sizeof(char);
			break;
	}
	
    _tprintf(TEXT("\n\n[Memory Usage]\ntotal allocated memory: %I64d KB, used memory: %I64d KB, freed memory: %I64d KB\n"), statex.ullTotalPhys / BYTES_TO_KB, sizeAlct / BYTES_TO_KB, (statex.ullTotalPhys - sizeAlct) / BYTES_TO_KB);  // ���� �� ���� �޸� ũ��
    free(intAlct);
    free(charAlct);
    return sizeAlct;
}

void clear(int sizeAlct) {

	MEMORYSTATUSEX statex;
 
    statex.dwLength = sizeof(statex); // �ʱ� �Է� ��(����ü ũ��)
 
    GlobalMemoryStatusEx(&statex);
    
    _tprintf(TEXT("\n\n[Memory Usage]\ntotal allocated memory: %I64d KB, used memory: %I64d KB, freed memory: %I64d KB\n"), statex.ullTotalPhys / BYTES_TO_KB, 0 / BYTES_TO_KB, statex.ullTotalPhys / BYTES_TO_KB);  // ���� �� ���� �޸� ũ��
}

int main(void) {
	int sizeAlct;
	int *alct = NULL, select;
	printf("[�޸� �޸� �𸮸�]\n1. �޸� �Ҵ�\n2. �޸� ����\n���ϴ� ����?");
	scanf("%d", &select);
	switch(select) {
		case 1:
			sizeAlct = allocate();
			break;
		case 2:
			clear(sizeAlct);
			break;
	}
	return 0;
}
