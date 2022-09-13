#include <stdio.h>

int main(void) {
	char *str1 = "hello";
	char *str2 = "soo";
	int str1_len, str2_len;
    char *new_str;

    /* null check */

    str1_len = strlen(str1);
    str2_len = strlen(str2);

    new_str = malloc(str1_len + str2_len + 1);

    /* null check */

    memcpy(new_str, str1, str1_len);
    printf("%s\n", new_str);
    memcpy(new_str + str1_len, str2, str2_len + 1);
    printf("%s\n", new_str);
	
	
    return 0;
}
