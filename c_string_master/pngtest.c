#include <stdio.h>
#include <string.h>
//#include "stdlib.h"
//#include "unistd.h"
//#include "fcntl.h"

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

int html_pointer();
char* png_insert(char* buffer);

int main() {
	char buffer;
	char* base64;
	
	base64 = png_insert(&buffer);
	html_pointer(base64);
	
	free(&buffer); 
	
	return 0;
}

int html_pointer(char * base64) {
	FILE *html;
	FILE *html_encoding;
	char buffer[256];
	
	html = fopen("body.html", "r");
	html_encoding = fopen("base64.html", "w");
	
	if(html == NULL) {
		printf("파일 열기에 실패했습니다. \n");
	}
	
	else {
		printf("파일 열기에 성공했습니다. \n");
	}
	
	char front[100000] = "data:image/png;base64,";
	char *back = "\"";
	strcat(front, base64);
	char *buffer64 = (char *)malloc(strlen(front)+1024);
	
	while(fgets(buffer, 256, html)) { // 읽으면서 buffer에 저장시켜놓기 
		
		char *ptr = strstr(buffer, "src=");
			
		if(ptr) { // buffer에 포함되어 있다면
            strcpy(buffer64, buffer);
            strcpy(strstr(buffer64, "src=")+5, front);
            strcat(buffer64, back);
			fputs(buffer64, html_encoding);
		}
		else {
			fputs(buffer, html_encoding);
		}
	}
	
	free(buffer64);
	fclose(html_encoding);
	fclose(html);
	return 0;
}

char* png_insert(char* buffer) {
	FILE* png;
	size_t result;
	long lSize;
	
	png = fopen("body.png", "rb");
	
	if (png == NULL) {
		printf("File Error");
		exit(1);
	}
	
	// 파일 크기를 lSize에 저장 
	fseek(png, 0, SEEK_END);
	lSize = ftell(png);
	rewind(png);
	
	// 전체 파일의 내용을 받을 수 있을 정도의 크기로 메모리를 할당
	buffer = (char*)malloc(sizeof(char) * lSize);

	if (buffer == NULL) {
		printf("Memory Error");
		exit(2);
	}
	
	// 그 파일의 내용을 버퍼에 저장
	result = fread(buffer, 1, lSize, png);
	
	if (result != lSize) {
		printf("Reading Error", stderr);
		exit(3);
	}
	
	size_t* out_ptr = (size_t*)malloc(sizeof(size_t));
	
	// 모든 파일의 내용이 버퍼에 들어감
	// 종료
	fclose(png);

	return sd_string_alloc_base64_encode(buffer, result, out_ptr);
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
