
#include <stdio.h>
#include <stdlib.h>
#include <stack.h>

int main() {
	STACK_T my_stack;
	DATATYPE data;
	
	my_stack = stack_new();
	stack_push(&my_stack, 10);
	stack_push(&my_stack, 11);
	stack_push(&my_stack, 12);
	stack_push(&my_stack, 13);
	stack_push(&my_stack, 14);
	stack_push(&my_stack, 15);
	
	stack_print(my_stack);
	
	if(stack_pop(&my_stack, &data)) {
		printf(DATATYPE_PRINTF"\n", data);
	} else {
		printf("ERROR: stack is empty. \n");
	}
	
	if(stack_pop(&my_stack, &data)) {
		printf(DATATYPE_PRINTF"\n\n", data);
	} else {
		printf("ERROR: stack is empty. \n\n");
	}
	
	stack_print(my_stack);
	
	stack_pop(&my_stack, &data);
	stack_pop(&my_stack, &data);
	
	stack_print(my_stack);
	
	stack_destroy(&my_stack);
	
	return EXIT_SUCCESS;
}

