/*
	File: doubly_linked_list.h
*/

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <math.h>
#include <stdbool.h>

// definimos el tipo que almacena nuestra lista
#define DATATYPE float
#define DATATYPE_ERR NAN
#define DATATYPE_PRINTF "%f"

// Definimos un nodo de la lista 
typedef struct __doubly_linked_list_node {
	DATATYPE data;
	struct __doubly_linked_list_node * ptr_next;
	struct __doubly_linked_list_node * ptr_back;
} DOUBLY_LINKED_LIST_NODE;

// Definimos la lista como una estructura con los siguientes campos:
//  - head: puntero al primer elemento de la lista
//  - tail: puntero al ultimo elemento de la lista
//  - size: numero de elementos
typedef struct {
	DOUBLY_LINKED_LIST_NODE * head;
	DOUBLY_LINKED_LIST_NODE * tail;
	int size;
} DOUBLY_LINKED_LIST;

// Funciones para operar con una lista
DOUBLY_LINKED_LIST doubly_linked_list_new();
int				doubly_linked_list_size(DOUBLY_LINKED_LIST my_list);
bool			   doubly_linked_list_empty(DOUBLY_LINKED_LIST my_list);
void			   doubly_linked_list_add_head(DOUBLY_LINKED_LIST *my_list, DATATYPE data);
void			   doubly_linked_list_add_tail(DOUBLY_LINKED_LIST *my_list, DATATYPE data);
void			   doubly_linked_list_add(DOUBLY_LINKED_LIST *my_list, DATATYPE data, int i);
DATATYPE		   doubly_linked_list_get_head(DOUBLY_LINKED_LIST my_list);
DATATYPE		   doubly_linked_list_get_tail(DOUBLY_LINKED_LIST my_list);
DATATYPE		   doubly_linked_list_get(DOUBLY_LINKED_LIST my_list, int i);
void			   doubly_linked_list_del_head(DOUBLY_LINKED_LIST *my_list);
void			   doubly_linked_list_del_tail(DOUBLY_LINKED_LIST *my_list);
void			   doubly_linked_list_del(DOUBLY_LINKED_LIST *my_list, int i);
void			   doubly_linked_list_clear(DOUBLY_LINKED_LIST *my_list);
DOUBLY_LINKED_LIST doubly_linked_list_copy(DOUBLY_LINKED_LIST my_list);
DOUBLY_LINKED_LIST doubly_linked_list_concat(DOUBLY_LINKED_LIST *my_list_1, DOUBLY_LINKED_LIST *my_list_2);
void			   doubly_linked_list_printf(DOUBLY_LINKED_LIST my_list);

#endif 
