#include <stdio.h>
#include "./parson/parson.h"    // parson.h 헤더 파일 포함
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define LENGTH 10
#include <pthread.h>
#include <unistd.h>

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
	
	copy[0] = '\0';
	copy[LENGTH] = '\0';
	charAscii[0] = '\0';
	charAscii[LENGTH] = '\0';
	rand_num = 0;
	memset(copy, 0, LENGTH + 1);
	
	while(count > 0) {
		big_low = rand() % 2 + 1;
		rand_num = rand();
			
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

static void* thread_routine(void * arg){
      //  pthread_t tid;
     //   tid=pthread_self();
       // printf("\ttid:%lx\n",tid);
		char* threadName = (char*)arg;
        int i=0;
        while(1){
                printf(" \033[37m\t%s running \033[31mtime : \033[37m%ds\n",threadName,i);
                i++;
                sleep(1);
        }

	return NULL;
}



int main(void)
{
	struct Jparser *jp1 = malloc(sizeof(struct Jparser));

    JSON_Value *rootValue;
    JSON_Object *rootObject;
	JSON_Object *threadOb;
	JSON_Array *array;

	// 초기화 
	int repeat = 0; 
   	jp1->repeat = 0;
	jp1->thread = 0;
	jp1->random_char = NULL;

	/* 초기화 */
    rootValue = json_parse_file("jparser.json");      
  
	rootObject = json_value_get_object(rootValue);   
    
    /* 사용 */
    // 객체에서 키에 해당하는 숫자를 가져옴
	repeat = (int)json_object_get_number(rootObject, "repeat");
	jp1->repeat = repeat; 
	jp1->random_char = malloc(sizeof(char) * repeat * LENGTH + 1);

    saveJson(*jp1);
	printFile();
	
	jp1->thread = (int)json_object_get_number(rootObject, "thread_num");
	printf("thread_num : %d\n", jp1->thread);

    array = json_object_get_array(rootObject, "thread"); // 객체에서 키에 해당하는 배열을 가져옴
	int arrayCount = (int)json_array_get_count(array);
	
	int thread_num = jp1->thread;
	if(thread_num == 0 || !thread_num || thread_num != arrayCount) {
		printf("error\n");
		return 0;
	}

	
	const char* threadName;
    pthread_t *thread2 = (pthread_t*)malloc(arrayCount * sizeof(pthread_t));
	pthread_attr_t attr;
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	int status;
	int pid;
    for (int i = 0 ; i < arrayCount ; i++)
    {
        // 배열에 인덱스를 지정하여 문자열을 가져옴
		threadOb = json_array_get_object(array, i);
		threadName = json_object_get_string(threadOb, "name");
		printf("threadOb : %s\n", threadName);
	
		pid = pthread_create(&(thread2[i]),NULL,thread_routine, (void *)threadName);
		
        if (pid < 0)
  		{
    	    perror("thread create error : ");
     		exit(0);
  		}
//		pthread_attr_t attr;
//		pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	}
			pthread_join(thread2[0], (void **)&status);
			pthread_join(thread2[1], (void **)&status);
			pthread_join(thread2[2], (void **)&status);
	//pid = pthread_create(&thread,NULL,thread_routine(NULL, threadName), (void *)threadName);
 	/*	pid = pthread_create(&thread2[0],NULL,thread_routine, (void *)threadName);
		
        if (pid < 0)
  		{
    	    perror("thread create error : ");
     		exit(0);
  		}
		threadName = "test2";
 		pid = pthread_create(&thread2[1],NULL,thread_routine, (void *)threadName);
		
        if (pid < 0)
  		{
    	    perror("thread create error : ");
     		exit(0);
  		}
		threadName = "test3";
		pid = pthread_create(&(thread2[2]),NULL,thread_routine, (void *)threadName);
		
        if (pid < 0)
  		{
    	    perror("thread create error : ");
     		exit(0);
  		}

*/


//	int i=0;
  	 // printf("tid:%lx\n",pthread_self());
	/* while(1){
        printf("main_thread running time : %ds\n",i);
        i++;
        sleep(1);
    }*/
    //pthread_join(thread,NULL); // join하려는 thread를 명시해주고, start_routine이 반환하는 값을 null에 저장


	if (jp1) {
		if (jp1->random_char) {
			free(jp1->random_char);
			jp1->random_char = NULL;
		}
		free(jp1);
		jp1 = NULL;
	}
    
	free(thread2);
    json_value_free(rootValue);
	
    return 0;
}
