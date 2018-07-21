/*
    File: stack_main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
    STACK my_stack;
    DATATYPE data;
    
    my_stack = stack_new();
    stack_push(&my_stack, 10);
    stack_push(&my_stack, 11);
    stack_push(&my_stack, 12);
    stack_push(&my_stack, 13);
    
    stack_printf(my_stack);
    
    data = stack_pop(&my_stack);
    printf(DATATYPE_PRINTF"\n", data);
    
    data = stack_pop(&my_stack);
    printf(DATATYPE_PRINTF"\n\n", data);
    
    stack_printf(my_stack);
    
    stack_pop(&my_stack);
    stack_pop(&my_stack);
    
    stack_printf(my_stack);
    
    return EXIT_SUCCESS;
}

