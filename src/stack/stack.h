/*
    File: stack.h
*/

#ifndef STACK_H
#define STACK_H

#include <math.h>
#include <stdbool.h>

// definimos el tipo que almacena nuestra pila
#define DATATYPE         float
#define DATATYPE_ERR     NAN
#define DATATYPE_PRINTF  "%f"

// Definimos un nodo de la pila 
typedef struct __stack_node {
    DATATYPE data;
    struct __stack_node * ptr_next;
} STACK_NODE;

// Definimos la pila como una estructura con los siguientes campos:
//  - head: puntero al primer elemento de la pila
//  - size: numero de elementos
typedef struct {
    STACK_NODE * head;
    int size;
} STACK;

// Funciones para operar con una pila
STACK    stack_new    (void);
int      stack_size   (STACK my_stack);
bool     stack_empty  (STACK my_stack);
void     stack_push   (STACK* my_stack, DATATYPE data);
DATATYPE stack_pop    (STACK* my_stack);
void     stack_printf (STACK my_stack);

#endif 
