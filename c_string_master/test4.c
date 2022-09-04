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

static const unsigned char base64_table[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
static const char base64code_ascii[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";



int main() {
	char *str = "hello base64 !";
	char base64_code[128] = { 0, };
	char text[128] = { 0, };
	int ret = 0;

	printf("%s\n", str);
//	
//	ret = base64_encoder(str, strlen(str), base64_code, 128);
//	printf("base64 encoding : %s\n",base64_code);

	ret = sd_string_alloc_base64_encode(str, strlen(str), base64_code);
	printf("base64 encoding : %s\n", base64_code);
}

char * sd_string_alloc_base64_encode(const unsigned char *src, size_t len, size_t *out_len)
// int base64_encoder(char *in, int in_size, char *out, int out_size) //
{
    unsigned char *out, *pos;
    const unsigned char *end, *in; // 상수, const 예약어  
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
    
    while (end - in >= 3) { // end와 in의 차이가 3 이상이 면  
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


int base64_encoder(char *in, int in_size, char *out, int out_size)
{
 int i = 0;
 int o = 0;

 if (!in || !out) return 0;
// if (text2base64_size(in) > out_size) return 0;

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


