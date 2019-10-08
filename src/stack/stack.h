/*
	File: stack.h
*/

#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// definimos el tipo que almacena nuestra pila
#define DATATYPE		 float
#define DATATYPE_PRINTF  "%f"

// Definimos un nodo de la pila 
typedef struct __stack_node {
	DATATYPE data;
	struct __stack_node * ptr_next;
} STACK_NODE_T;

// Definimos la pila como una estructura con los siguientes campos:
//  - head: puntero al primer elemento de la pila
//  - size: numero de elementos
typedef struct {
	STACK_NODE_T * head;
	int size;
} STACK_T;

// Funciones para operar con una pila
STACK_T stack_new     (void);
int     stack_size    (STACK_T in_stack);
bool    stack_empty   (STACK_T in_stack);
void    stack_push    (STACK_T * inout_stack, DATATYPE in_data);
bool    stack_pop     (STACK_T * inout_stack, DATATYPE * out_data);
void    stack_destroy (STACK_T * inout_stack);
void    stack_print   (STACK_T in_stack);

#endif 
