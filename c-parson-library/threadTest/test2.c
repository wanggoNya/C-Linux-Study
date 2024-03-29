#include <stdio.h>
#include "./parson/parson.h"    // parson.h 헤더 파일 포함
#include <stdlib.h>
#include <time.h>

struct Jparser 
{
		int repeat;
		int thread;
		char *random_char;
};

struct Jparser printRepeat(struct Jparser *jp1)
{
	srand((unsigned int)time(NULL));
	int temp = jp1->repeat;
	int rand_num, big_low, ascii;
	char * copy = NULL;
	copy = malloc(temp * sizeof(char) + 1 );
	char *  charAscii = malloc(temp * sizeof(char));

	while(temp > 0) {
		big_low = rand() % 2 + 1;
		rand_num = rand();
		
		if (big_low == 1) {
			ascii = rand_num % 26 + 65; // 1~ 90 대문자 
		}
		else if (big_low == 2)  {
			ascii = rand_num % 26 + 97; // 1~ 90 대문자 
		}
		
		sprintf(charAscii, "%c", ascii);
		charAscii[-1] = '\0';
		printf("charAscii :  %s\n", charAscii);
		if(temp == jp1->repeat) strcpy(copy, charAscii); 
		else strcat(copy, charAscii);

		printf("copy : %s\n", copy);
		temp--;	
	}

	strcpy((*jp1).random_char, copy);
	//(*jp1).random_char = copy;
	free(copy);
	printf("jp1 random_char : %s\n", (*jp1).random_char);
	return *jp1;
}


void saveJson(struct Jparser jp1) 
{
	printf("save json repeat : %d\n", jp1.repeat);
	printf("random_char : %s\n", jp1.random_char);

	
	JSON_Value *rootValue;
	JSON_Object *rootObject;

	rootValue = json_value_init_object();
	rootObject = json_value_get_object(rootValue);
	// 빈 객체 {}가 생성됨 
	
	json_object_set_number(rootObject, "repeat_cnt", jp1.repeat);
	json_object_set_value(rootObject, "repeat", json_value_init_array());
	JSON_Array *repeat = json_object_get_array(rootObject, "repeat");
	
	JSON_Object *arrayObject = json_value_get_object(repeat);

	char *copy;
	//strcpy(copy, jp1.random_char);
	copy = jp1.random_char;
	char temp[2];
	int i;
	for(i = 0; i < jp1.repeat; i++ ) {
		temp[0] = copy[i];
		temp[1] = '\0'; 
	 	printf("temp [i] : %s\n", temp);
		json_array_append_string(repeat, temp);
	}
	
	json_serialize_to_file_pretty(rootValue, "repeat.json");
	json_value_free(rootValue);

	char* buffer;
    int size;
    int count;

    FILE *fp = fopen("repeat.json", "r");
    if (NULL == fp) {
        return -1;
    }

    fseek(fp, 0, SEEK_END); // 파일 포인터를 파일의 끝으로 이동시킴
    size = ftell(fp);        // 파일 포인터의 현재 위치를 얻음 => 파일 사이즈

    buffer = malloc(size * sizeof(char) + 1);    // 파일 크기 + 1바이트(문자열 마지막의 NULL) 만큼 동적 메모리 할당
    memset(buffer, 0, size + 1);// 파일 크기 +1바이트만큼 메모리 0으로 초기화

    fseek(fp, 0, SEEK_SET);                // 파일 포인터를 파일의 처음으로 이동시킴
    count = fread(buffer, size, 1, fp);    // 파일 크기만큼 값을 읽음
	
	printf("\n%s\n", buffer);

    fclose(fp);        // 파일 포인터 닫기
    free(buffer);    // 동적 메모리 해제
}


int main()
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
	jp1->random_char = malloc(sizeof(char) * repeat + 1);
	printf("struct repeat : %d\n", jp1->repeat);

    saveJson(printRepeat(jp1));
	
	printf("thread_num : %d\n", (int)json_object_get_number(rootObject, "thread_num"));
    
	// thread 
	printf("thread:\n");

    // 객체에서 키에 해당하는 배열을 가져옴
    JSON_Array *array = json_object_get_array(rootObject, "thread");
    for (int i = 0; i < json_array_get_count(array); i++)     // 배열의 요소 개수만큼 반복
    {
    
			// 배열에 인덱스를 지정하여 문자열을 가져옴
        printf("  %s\n", json_array_get_string(array, i));
    }
	
	free(jp1);
    // 객체에서 키에 해당하는 불 값을 가져옴
    /* 해제 */
    json_value_free(rootValue);    // JSON_Value에 할당된 동적 메모리 해제

    return 0;
}
