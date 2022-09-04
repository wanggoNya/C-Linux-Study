#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>
#include <sched.h>
#include <dirent.h>
//#include <iconv.h>
#include <wchar.h>

#include "b64_encoding.h"
static const char base64code_ascii[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int text2base64_size(const char *text)
{
 int len = strlen(text);
 return ((len + 2) / 3 * 4);
}

int base64_encoder(char *in, int in_size, char *out, int out_size)
{
 int i = 0;
 int o = 0;

 if (!in || !out) return 0;
 if (text2base64_size(in) > out_size) return 0;

 while (i < in_size - 2 && o+4 <= out_size)
 {
 out[o++] = base64code_ascii[(in[i] >> 2) & 0x3F];
 out[o++] = base64code_ascii[((in[i] & 0x3) << 4) | ((int)(in[i + 1] & 0xF0) >> 4)];
 out[o++] = base64code_ascii[((in[i + 1] & 0xF) << 2) | ((int)(in[i + 2] & 0xC0) >> 6)];
 out[o++] = base64code_ascii[in[i + 2] & 0x3F];
 i += 3;
 }

 if (i < in_size)
 {
 out[o++] = base64code_ascii[(in[i] >> 2) & 0x3F];
 if (i == (in_size - 1))
 {
 out[o++] = base64code_ascii[((in[i] & 0x3) << 4)];
 out[o++] = '='; // padding
 }
 else
 {
 out[o++] = base64code_ascii[((in[i] & 0x3) << 4) | ((int)(in[i + 1] & 0xF0) >> 4)];
 out[o++] = base64code_ascii[((in[i + 1] & 0xF) << 2)];
 }

 out[o++] = '='; // padding
 }

 return o;
}

int main() {

char *str = "hello base64 !";
char base64_code[128] = { 0, };
char text[128] = { 0, };
int ret = 0;

printf("%s\n", str);

ret = base64_encoder(str, strlen(str), base64_code, 128);
printf("base64 encoding : %s\n", base64_code);
	
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
		;
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

