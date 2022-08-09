#include <stdio.h>

int main(void) {
	FILE *fp = NULL;
	int c;
	
	fp = fopen("input.txt", "r");
	
	if(fp == NULL) {
		printf("파일 열기에 실패\n");
		
	} else {
		printf("파일 열기에 성공 \n");
	}
	
	while((c = fgetc(fp)) != EOF) // 지금 열려있는 파일에서 문자 하나를 읽고 c에 저장한다. 
	{
		putchar(c); // 콘솔창에 해당 문자를 출력 // 파일이 끝날 때 까지 모두 출 력   
	 } 
	 
	 fclose(fp);
	 
	 return 0;
}


