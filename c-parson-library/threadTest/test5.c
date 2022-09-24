#include <stdio.h>
#include "./parson/parson.h"    // parson.h 헤더 파일 포함
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define LENGTH 10

char copy[LENGTH + 1];

struct Jparser 
{
		int repeat;
		int thread;
		char *random_char;
};

static char * printRepeat(void)
{
	int rand_num, big_low, ascii, count = LENGTH;
	char charAscii[LENGTH + 1];
/*
	copy[0] = '\0';
	copy[LENGTH] = '\0';
	charAscii[0] = '\0';
	charAscii[LENGTH] = '\0';
	rand_num = 0;
	memset(copy, 0, LENGTH + 1);
*/
	while(count > 0) {
		big_low = rand() % 2 + 1;
		rand_num = rand();
			
		printf("rand_num : %d\n", rand_num); 

		if (big_low == 1) {
			ascii = rand_num % 26 + 65; // 1~ 90 대문자 
		}
		else if (big_low == 2)  {
			ascii = rand_num % 26 + 97; // 1~ 90 대문자 
		}
		
		sprintf(charAscii, "%c", ascii);
		if(count == LENGTH) strcpy(copy, charAscii);
		else strcat(copy, charAscii);
		
		
		count--;	
	}
	
	return copy;
}

static void saveJson(struct Jparser jp1) 
{
	JSON_Value *rootValue;
	JSON_Object *rootObject;

	rootValue = json_value_init_object();
	rootObject = json_value_get_object(rootValue);
	// 빈 객체 {}가 생성됨 
	
	json_object_set_number(rootObject, "repeat_cnt", jp1.repeat);
	json_object_set_value(rootObject, "repeat", json_value_init_array());
	JSON_Array *repeat = json_object_get_array(rootObject, "repeat");

	char * string;
	int i;
	srand((unsigned int)time(NULL));
	for(i = 1; i <= jp1.repeat; i++ ) {

		string[0] = '\0';
		string = printRepeat(); 
		
		printf("string : %s\n", string);
		JSON_Value *arrayValue = json_value_init_object();
		JSON_Object *arrayObject = json_value_get_object(arrayValue);
		json_object_set_string(arrayObject, "repeat_string", string);
		json_array_append_value(repeat, arrayValue);

	}
	
	json_serialize_to_file_pretty(rootValue, "repeat.json");
	json_value_free(rootValue);
}

static int printFile(void)
{
	char* buffer;
    int size;
    FILE *fp = fopen("repeat.json", "r");
    if (NULL == fp) {
   		return -1;
	}

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);

    buffer = malloc(size * sizeof(char) + 1);
    memset(buffer, 0, size + 1);

    fseek(fp, 0, SEEK_SET);  
    fread(buffer, size, 1, fp);
	
	printf("\n%s\n\n", buffer);

    fclose(fp); 
    free(buffer);
	return 0;
}

int main(void)
{
	struct Jparser *jp1 = malloc(sizeof(struct Jparser));

    JSON_Value *rootValue;
    JSON_Object *rootObject;
	
	// 초기화 
	int repeat = 0; 
   	jp1->repeat = 0;
	jp1->thread = 0;
	jp1->random_char = NULL;

	/* 초기화 */
    rootValue = json_parse_file("jparser.json");      // JSON 파일을 읽어서 파싱
  
	rootObject = json_value_get_object(rootValue);    // JSON_Value에서 JSON_Object를 얻음
    
    /* 사용 */
    // 객체에서 키에 해당하는 숫자를 가져옴
	repeat = (int)json_object_get_number(rootObject, "repeat");
	jp1->repeat = repeat; 
	jp1->random_char = malloc(sizeof(char) * repeat * LENGTH + 1);

    saveJson(*jp1);
	printFile();
	

	if (jp1) {
		if (jp1->random_char) {
			free(jp1->random_char);
			jp1->random_char = NULL;
		}
		free(jp1);
		jp1 = NULL;
	}
    // 객체에서 키에 해당하는 불 값을 가져옴
    /* 해제 */
    json_value_free(rootValue);    // JSON_Value에 할당된 동적 메모리 해제

    return 0;
}
