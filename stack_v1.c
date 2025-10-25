#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int top = 100;

int equal(char *command, char *string){
	return strcmp(command, string) == 0; 

}

bool empty(){
    return top == 100;
}

bool full(){
    return top != 100;
}

bool overflow(){
	return top == 0; 
}

void push(int*, int);

void pop(int *);

void clear(int*); 

void dump(int *, int); 

int main()
{
    	int stack[100]; 
	int value = 0;
    	char command[10];
    	for(;;){
      		scanf("%s", command); 
		//push
		if(equal(command, "push")){
			scanf("%d", &value); 
        		push(stack, value);
		}
		//pop
		else if(equal(command, "pop")){ 
			pop(stack);
		}
		//clear
		else if(equal(command, "clear")){
			clear(stack);
		}
		//dump
		else if(equal(command, "dump")){
			for(int i = top; i != 100; i ++)
				dump(stack, i);
		}
		//peek
		else if(equal(command, "peek")){
			if(full())
				printf("%d\n", stack[top]); 
			else
				printf("ERROR: STACK EMPTY");
		}
		else
			printf("ERROR: WTF IS THIS COMMAND Hahaha : )\n");
		value = 0;
    	}
}

void push(int *stack, int value){
	if(!overflow()){
		top -= 1;
		stack[top] = value;
	}
	else printf("ERROR: STACK FULL");
}

void pop(int *stack){
        if(empty()){
		printf("ERROR: STACK EMPTY");
		return;
	}
	if(full()){
		printf("%d\n", stack[top]);
        	stack[top] = 0;
		top+= 1;
	}
}

void clear(int *stack){
	if(empty())
		return; 
	for(top; top != 100; top++)
		stack[top] = 0;
		printf("%d", top); 

	return;
}

void dump(int * stack, int i){
	printf("VALUE: %d ", stack[i]);
}

