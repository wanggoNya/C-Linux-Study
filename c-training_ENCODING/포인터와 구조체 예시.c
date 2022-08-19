#include <stdio.h>


int main(void) {
	// 0x100 "hello"\0 10Byte
// %s => 0x100 ~ 0x109 \0 10byte 

		for (i = 0; i < 10; i++) { 
		if (strlen(s[i].name)) printf("name : %s\n", s[i].name);
		else {
			printf("no name\n");
			break;
		}
	}	
		/*for (i = 0; i < 10; i++) { 
		if (strlen(s[i].name)) printf("name : %s\n", s[i].name);
		else {
			printf("no name\n");
			break;
		}
	}*/
	
  /*         // 0x20,  0x10  
void func1(int num, int *num1) {
	num = 30;
	*num1 = 30;
	return;
}
*/

  /*         // 0x20,  0x10  
void func1(int num, int *num1) {
	num = 30;
	*num1 = 30;
	return;
}
*/

	//0x10
/*	int *test;
	*test = 20;
	printf("%d\n", *test);
	func1(*test, test);
	printf("%d\n", *test);
	*/
	return 0;
}
