#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char * number_str = "250.6";
    int number_int;
    double number_double;
    
    number_int = atoi(number_str);
    number_double = atof(number_str);
    printf("string = %s, int = %ld, double = %f", number_str, number_int, number_double);
	return 0;
}
