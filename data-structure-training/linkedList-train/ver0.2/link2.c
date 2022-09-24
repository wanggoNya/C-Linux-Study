#include "linkedList.h"


int main(void) 
{ 
		List *l1 = addList();
		int select;
		char *data;
		data = calloc(LENGTH, sizeof(char));
		Node *newNode;
		while(select != 4) 
		{
				printf("=============linked list world=============\n");	
				printf("1. push \n2. pop \n3. print \n4. exit\n");
				printf("===========================================\n");	
				scanf("%d", &select);

				switch (select) {
						case 1:
								printf("----------push mode----------\n");	
								printf("Enter string : ");
								scanf("%s", data);
								printf("-----------------------------\n");
								newNode = addNode(l1, data, newNode);
								break;
						case 2:
								printf("----------pop mode----------\n");	
								printf("Select string number : ");
								printf("----------------------------\n");
								break;
						case 3:
								
								printf("----------print mode----------\n");	
								printNode(l1);
								printf("----------------------------\n");

								break;
						case 4:
								printf("bye bye\n");
								break;
				}
		}

		freeNode(l1);
		if(l1)
		{
				free(l1);
				l1 = NULL;
		}
		if (data) {
				
				free(data);
				data = NULL;
		}

		return 0;
}

