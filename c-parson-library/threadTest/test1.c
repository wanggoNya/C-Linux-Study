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
	(*jp1).random_char = copy;
	printf("jp1 random_char : %s\n", (*jp1).random_char);
	printf("ptr random_char : %p\n",&copy);
	printf("ptr copy : %p\n",&(*jp1).random_char);
	free(copy);
	printf("jp1 random_char : %s\n", (*jp1).random_char);
	return *jp1;
}


void saveJson(struct Jparser jp1) 
{
	printf("repeat : %d\n", jp1.repeat);
	printf("random_char : %s\n", *jp1.random_char);
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
	
	printf("test\n");
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
//    printf("KoreaRelease: %d\n", json_object_get_boolean(rootObject, "KoreaRelease"));

    /* 해제 */
    json_value_free(rootValue);    // JSON_Value에 할당된 동적 메모리 해제


    return 0;
}

