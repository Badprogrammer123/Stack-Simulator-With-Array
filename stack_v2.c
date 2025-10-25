#include <stdio.h>

#include <stdbool.h>

#include <string.h>

#define STACK_CAPACITY 100


int top = 100;



void push(int*, int);

void pop(int *);

void clear(int*); 

void dump(int *, int); 



int equal(char *command, char *string){
	return strcmp(command, string) == 0; 
}

bool empty(){
    return top == STACK_CAPACITY;
}

bool not_empty(){
    return top != STACK_CAPACITY;
}

bool overflow(){
	return top == 0; 
}


int main(){
    	int stack[100]; 
	int value = 0;
    	char command[10];
    	for(;;){
      		scanf("%s", command); 
		//push
		if(equal(command, "push")){
			scanf("%d", &value); 
			if(!overflow()){
        			push(stack, value);
			}
			else {
				printf("ERROR: STACK FULL\n");
			}
		}
		//pop
		else if(equal(command, "pop")){ 
			if(empty()){
				printf("ERRO: STACK EMPTY\n");
			}
			else if(not_empty()){
				pop(stack);
			}
		}
		//clear
		else if(equal(command, "clear")){
			if(empty()){
				printf("ERROR: STACK EMPTY\n");
			}
			if(not_empty()){
				clear(stack);
			}
		}
		//dump
		else if(equal(command, "dump")){
			for(int i = top; i != 100; i ++)
				dump(stack, i);
		}
		//peek
		else if(equal(command, "peek")){
			if(not_empty())
				printf("%d\n", stack[top]); 
			else
				printf("ERROR: STACK EMPTY\n");
		}
		//Non existing command
		else
			printf("ERROR: WTF IS THIS COMMAND Hahaha : )\n");
		//Sets value equal to 0 so you don't push previous values
		value = 0;
    	}
}

void push(int *stack, int value){
	top -= 1;
	stack[top] = value;
	return;	
}

void pop(int *stack){
	printf("%d\n", stack[top]);
        stack[top] = 0;
	top+= 1;
	return;
}

void clear(int *stack){ 
	for(top; top != STACK_CAPACITY; top++)
		stack[top] = 0;
		printf("%d", top); 

	return;
}

void dump(int * stack, int i){
	printf("VALUE: %d ", stack[i]);
	return; 
}
