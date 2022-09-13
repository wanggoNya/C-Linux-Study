#include <stdio.h>

int main() {
    int number_int = 22;
    double number_double = 7.22f;
    char *buf = "format_string";
    char *data = "modify_string";
    char result[80];  
    int i;
    
    for(i = 0 ; i < 5 ; i++)
    {
        snprintf(result, sizeof(result)-1, "%s %04d %.2f Hello, world!", buf, number_int+i, number_double);
        printf("%s\n", result);
    }
    
    for(i = 0 ; i < 5 ; i++)
    {
        snprintf(result, 10, "%s %04d %.2f Hello, world!", buf, number_int+i, number_double);
        printf("%s\n", result);
    }
    
    for(i = 0 ; i < 5 ; i++)
    {
        snprintf(result, sizeof(result)-1, "%s %04d %.2f Hello, world!", data, number_int+i, number_double);
        printf("%s\n", result);
    }
    
    snprintf(result, sizeof(result)-1, "%s %04d %.2f Hello, world!", data, buf, number_int, number_double);
    
	printf("%s\n", result);
    
	snprintf(result, sizeof(result)-1, "%s %04d %.2f Hello, world!", number_int, number_double);
    
	printf("%s\n", result);

    return 0;
}
