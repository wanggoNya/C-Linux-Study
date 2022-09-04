#include <stdio.h>
#include <string.h>
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"
#include "fcntl.h"

#include <unistd.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include <sched.h>
#include <dirent.h>
//#include <iconv.h>
#include <wchar.h>
#include "b64_encoding.h"

int main() {
	
	FILE* html;
	FILE* htmlr;
	long lSize;
	char* buffer;
	size_t result;
	
    unsigned int wordCount = 0;  //�ܾ��
    unsigned int lineNumber = 0; //���� ��
    char *searchword; //ã�� ���ڿ�
    char *readByte; //���Ͽ��� ���� ����Ʈ
    char buf[1024]; //���Ͽ��� ���� ����Ʈ
	
	html = fopen("body.html", "rb");
	htmlr = fopen("body.html", "r");
	
	if (html == NULL) {
		printf("File Error");
		exit(1);
	}
	
	// ���� ũ�⸦ lSize�� ���� 
	fseek(html, 0, SEEK_END);
	lSize = ftell(html);
	rewind(html);
	
	// ��ü ������ ������ ���� �� ���� ������ ũ��� �޸𸮸� �Ҵ�
	buffer = (char*)malloc(sizeof(char) * lSize);
	if (buffer == NULL) {
		printf("Memory Error");
		exit(2);
	}
	
	// �� ������ ������ ���ۿ� ����
	result = fread(buffer, 1, lSize, html);
	printf("%zu\n", lSize);
	printf("%ld\n", result);
	
	if (result != lSize) {
		printf("Reading Error", stderr);
		exit(3);
	}
	
	while (feof(html) == 0) {
		readByte = fgets(buf, sizeof(buf), htmlr);
		char *tempStr = malloc(sizeof(char) * 1024);
		
		strcpy(tempStr, readByte);
		
		char *ptr = strtok(buf, " ");
		
		while (ptr != NULL) {
			
			if(strstr(readByte, "src=") != NULL) {
				wordCount += 1;
				RemoveEnd(tempStr+15);
                printf("%s \n", tempStr+15);
			}
			ptr = strtok(NULL, " "); //���� ���ڿ��� �߶� �����͸� ��ȯ
		}
		//������ �Ҵ��� ������ ���ڿ� ����
        free(tempStr);
	}

	// ��� ������ ������ ���ۿ� ��
	// ����
	fclose(htmlr);
	fclose(buf);
	fclose(html);
	free(buffer); 

	return 0;
}
	
void RemoveEnd(char *buf)
{
    int i = 0;    
    while (buf[i])
    {
        i++;
    }
    buf[i - 2] = '\0';
}

