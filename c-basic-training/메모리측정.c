#include <windows.h>
#include <stdio.h>
#include <tchar.h>
 
#define BYTES_TO_KB 1024
 
int main(void) {
 
    MEMORYSTATUSEX statex;
 
    statex.dwLength = sizeof(statex); // �ʱ� �Է� ��(����ü ũ��)
 
    GlobalMemoryStatusEx(&statex);
 
    _tprintf(TEXT("%I64d KB\n"), statex.ullTotalPhys / BYTES_TO_KB);  // ���� �� ���� �޸� ũ��
    _tprintf(TEXT("%.2f GB\n"), (statex.ullTotalPhys / BYTES_TO_KB) / (1024.0 * 1024.0)); // ���� �� ���� �޸� ũ��
 
    printf("%lu KB\n", statex.ullTotalPhys / BYTES_TO_KB);
    printf("%.2f GB\n", (statex.ullTotalPhys / BYTES_TO_KB) / (1024.0 * 1024.0));
 
    return 0;
}
 
/*
run:
 
66916832 KB
63.82 GB
66916832 KB
63.82 GB
 
*/
