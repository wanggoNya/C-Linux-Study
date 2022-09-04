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
	
    unsigned int wordCount = 0;  //단어수
    unsigned int lineNumber = 0; //라인 수
    char *searchword; //찾을 문자열
    char *readByte; //파일에서 읽을 바이트
    char buf[1024]; //파일에서 읽을 바이트
	
	html = fopen("body.html", "rb");
	htmlr = fopen("body.html", "r");
	
	if (html == NULL) {
		printf("File Error");
		exit(1);
	}
	
	// 파일 크기를 lSize에 저장 
	fseek(html, 0, SEEK_END);
	lSize = ftell(html);
	rewind(html);
	
	// 전체 파일의 내용을 받을 수 있을 정도의 크기로 메모리를 할당
	buffer = (char*)malloc(sizeof(char) * lSize);
	if (buffer == NULL) {
		printf("Memory Error");
		exit(2);
	}
	
	// 그 파일의 내용을 버퍼에 저장
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
			ptr = strtok(NULL, " "); //다음 문자열을 잘라서 포인터를 반환
		}
		//위에서 할당한 포인터 문자열 해제
        free(tempStr);
	}

	// 모든 파일의 내용이 버퍼에 들어감
	// 종료
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

static const unsigned char base64_table[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

char * sd_string_alloc_base64_encode(const unsigned char *src, size_t len, size_t *out_len)
{
    unsigned char *out, *pos;
    const unsigned char *end, *in;
    size_t olen;
    int line_len;

    olen = len * 4 / 3 + 4; /* 3-byte blocks to 4-byte */
    olen += olen / 72; /* line feeds */
    olen++; /* nul termination */
    if (olen < len) return NULL; /* integer overflow */
    out = calloc(1, olen);
    if (out == NULL) return NULL;

    end = src + len;
    in = src;
    pos = out;
    line_len = 0;
    while (end - in >= 3) {
        *pos++ = base64_table[in[0] >> 2];
        *pos++ = base64_table[((in[0] & 0x03) << 4) | (in[1] >> 4)];
        *pos++ = base64_table[((in[1] & 0x0f) << 2) | (in[2] >> 6)];
        *pos++ = base64_table[in[2] & 0x3f];
        in += 3;
        line_len += 4;
        if (line_len >= 72) {
            *pos++ = '\n';
            line_len = 0;
        }
    }

    if (end - in) {
        *pos++ = base64_table[in[0] >> 2];
        if (end - in == 1) {
            *pos++ = base64_table[(in[0] & 0x03) << 4];
            *pos++ = '=';
        } else {
            *pos++ = base64_table[((in[0] & 0x03) << 4) |
                (in[1] >> 4)];
            *pos++ = base64_table[(in[1] & 0x0f) << 2];
        }
        *pos++ = '=';
        line_len += 4;
    }

    if (line_len)
        *pos++ = '\n';

    *pos = '\0';
    if (out_len) *out_len = pos - out;
    return (char *)out;
}
