#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
//Ziyao Gao zg8rw 11/02/2020
//linkedlist.c
#define PUSH_FRONT 	0
#define PUSH_BACK 	1
#define POP_FRONT 	2
#define POP_BACK 	3
#define PRINT_LIST 	4
#define HELP 		5
#define QUIT 		6
#define INVALID 	7

#define BUFFER_SIZE 20

void printOptions();
int readInput(int* val);
int isNumber(const char* token);
int isEmpty(const char* input);

int main(){

	// TODO: INSTANTIATE YOUR LINKED LIST HERE.
	struct list_item{
	struct list_item* previous;
	int value;
	struct list_item* next;
	};
	struct list_item* head;
	struct list_item* tail;
	int length=0;
	//int value;
	//----END----
	head=malloc(sizeof(struct list_item));
	tail=malloc(sizeof(struct list_item));
	head->next=tail;
  	tail->previous=head;
  	//head->previous=NULL;
  	//tail->next=NULL;
	int option, val;
	printOptions();

	do {
		option = readInput(&val);
		struct list_item* node;

		switch(option){
			case PUSH_FRONT:// push onto front of list
	// TODO: Insert code to push val onto front of linked list here.
	node=malloc(sizeof(struct list_item));
	node->value=val;
	node->next=head->next;
  	head->next->previous=node;
  	head->next=node;
   	node->previous=tail;
   	length++;
	//free(node);
				//----END----
				break;
			case PUSH_BACK: // push onto back of list
// TODO: Insert code to push val onto back of linked list here.		
	node=malloc(sizeof(struct list_item));	
	node->value=val;
	node->previous=tail->previous;
  	tail->previous->next=node;
   	tail->previous=node;
  	node->next=tail;
	length++;
	//free(node);
	//node->previous=tail;
	//tail=node;
				//----END----
				break;
			case POP_FRONT: 				// remove from front of list
				// TODO: Insert code to remove from front of linked list here.
				// If list is empty, do nothing.
	//node=malloc(sizeof(struct list_item));
	node=head;
	//if(node==NULL){}
	//if(head->previous==NULL){}
	//if(node!=NULL){
	//node->previous->next=node->next;
  	//node->next->previous=node->previous;
  	if(length==0){
  	}
  	else //(node!=NULL)
  	{
  	head=node->next;
	//free(node);
	length--;
	}
	//}
				//----END----
				break;
			case POP_BACK:					// remove from back of list
				// TODO: Insert code to remove from back of linked list here.
				// If list is empty, do nothing.
	node=tail->previous;
	struct list_item* node1;
	if(length==0){
}
	else{
	/*while(node->next!=NULL){
 	node1=node;
  	node=node->next;
  	}*/
   	node1=node->previous;
   	node1->next=tail;
   	tail->previous=node1;
   	free(node);
   	//free(node1);
   	length--;
    }
    

			//----END----
				break;
			case PRINT_LIST:				// print list
				// TODO: Insert code to print list forwards here.
				// Simply print each element separated by a space as shown below:
				// Elements: 1 2 3 4 5 
				printf("Elements: ");
	node=head->next;
	while(node!=NULL&&node->next!=NULL){
	printf("%d ",node->value);
	//printf("\n");
	node=node->next;
	//printf("\n");
	}		
	printf("\n");
			//----END----
				break;
			case HELP: 						// print menu
				printOptions();
				break;
			case QUIT: 						// quit
				break;
			case INVALID: 					// bad input
				fprintf(stderr,"Invalid command or operand, please input a valid command or help to see the list again.\n");
				break;
		}

	} while(option != QUIT);

	// TODO: free any memory used by your linked list here
	struct list_item* node1;
	struct list_item* node2;
	node1=head->next;
	while(node1!=NULL){
	node2=node1;
	node1=node2->next;
	free(node2);
	}
	free(head);
	free(tail);
	//head->next=tail;
	//tail->previous=head;
	

	//----END----

	return 0;
}



//---------------------------------------
//NOTE: EVERYTHING BELOW THIS LINE SHOULD NOT BE TOUCHED. IT HANDLES INPUT AND SUCH FOR YOU
//---------------------------------------

int readInput(int* val){
	char input[BUFFER_SIZE]="";
	while(isEmpty(input)){
		printf("Enter command: ");
		fgets(input, BUFFER_SIZE, stdin);
		input[strcspn(input, "\n")] = 0;
	}

	char* token = strtok(input, " ");
	
	if ((strcmp(token, "af")) == 0){
		token = strtok(NULL, " ");
		if (isNumber(token)){
			*val = atoi(token);
			return PUSH_FRONT;
		} else return INVALID;
	} else if ((strcmp(token, "ab")) == 0){
		token = strtok(NULL, " ");
		if (isNumber(token)){
			*val = atoi(token);
			return PUSH_BACK;
		} else return INVALID;
	} else if ((strcmp(token, "rf")) == 0){
	 	return POP_FRONT;
	} else if ((strcmp(token, "rb")) == 0){
	 	return POP_BACK;
	} else if ((strcmp(token, "p")) == 0){
	 	return PRINT_LIST;
	} else if((strcmp(token, "help")) == 0){
	 	return HELP;
	} else if((strcmp(token, "-1")) == 0){
	 	return QUIT;
	} else {
		return INVALID;
	}
}

void printOptions(){
	printf("----------------------------------------------------\n");
	printf("This test harness operates with one linked list.\n");
	printf("Use any of the following options to manipulate it:\n");
	printf("\t* af <num> --- add integer to front\n");
	printf("\t* ab <num> --- add integer to back\n");
	printf("\t* rf       --- remove front element\n");
	printf("\t* rb       --- remove back element\n");
	printf("\t* p        --- print list forward\n");
	printf("\t* help     --- print off this list\n");
	printf("\t* -1       --- exit harness\n\n");
}

int isNumber(const char* token){
	int length, i = 0;
	if (token == NULL)	return 0;
	if(token[0] == '-') 	i = 1;
	length = strlen(token);
	for (; i < length; i++){
	    if (!isdigit(token[i]))
	    	return 0;
	}

	return 1;
}

int isEmpty(const char* input){
	while (*input != '\0'){
		if (!isspace((unsigned char)*input))
			return 0;
		input++;
	}

	return 1;
}
