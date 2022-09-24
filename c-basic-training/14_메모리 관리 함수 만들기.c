#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#define BYTES_TO_KB 1024

// char: 1 byte, short: 2 byte, int: 4 byte, long: 4 byte, long long: 8 byte
// 할당된 총 메모리 총량, 해제 되지 않고 사용중인 메모리 총량, 해제된 메모리 총량
int allocate(void) {
	int *intAlct;
	char *charAlct;
	int type;
	int size;
	int sizeAlct;

	MEMORYSTATUSEX statex;
 
    statex.dwLength = sizeof(statex); // 초기 입력 값(구조체 크기)
 
    GlobalMemoryStatusEx(&statex);
 	
    
	printf("할당할 자료형 선택하세요.\n1. int 형 \n2. char형 \n");
	scanf("%d", &type);
	printf("얼만큼 할당하시겠어요?");
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
	
    _tprintf(TEXT("\n\n[Memory Usage]\ntotal allocated memory: %I64d KB, used memory: %I64d KB, freed memory: %I64d KB\n"), statex.ullTotalPhys / BYTES_TO_KB, sizeAlct / BYTES_TO_KB, (statex.ullTotalPhys - sizeAlct) / BYTES_TO_KB);  // 실제 총 물리 메모리 크기
    free(intAlct);
    free(charAlct);
    return sizeAlct;
}

void clear(int sizeAlct) {

	MEMORYSTATUSEX statex;
 
    statex.dwLength = sizeof(statex); // 초기 입력 값(구조체 크기)
 
    GlobalMemoryStatusEx(&statex);
    
    _tprintf(TEXT("\n\n[Memory Usage]\ntotal allocated memory: %I64d KB, used memory: %I64d KB, freed memory: %I64d KB\n"), statex.ullTotalPhys / BYTES_TO_KB, 0 / BYTES_TO_KB, statex.ullTotalPhys / BYTES_TO_KB);  // 실제 총 물리 메모리 크기
}

int main(void) {
	int sizeAlct;
	int *alct = NULL, select;
	printf("[메모리 메모리 모리모리]\n1. 메모리 할당\n2. 메모리 해제\n원하는 서비스?");
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
