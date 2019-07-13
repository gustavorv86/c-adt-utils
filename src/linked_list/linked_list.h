/*
	File: linked_list.h
*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <math.h>
#include <stdbool.h>

// definimos el tipo que almacena nuestra lista
#define DATATYPE		 float
#define DATATYPE_ERR	 NAN
#define DATATYPE_PRINTF  "%f"

// Definimos un nodo de la lista 
typedef struct __linked_list_node {
	DATATYPE data;
	struct __linked_list_node * ptr_next;
} LINKED_LIST_NODE;

// Definimos la lista como una estructura con los siguientes campos:
//  - head: puntero al primer elemento de la lista
//  - tail: puntero al ultimo elemento de la lista
//  - size: numero de elementos
typedef struct {
	LINKED_LIST_NODE * head;
	LINKED_LIST_NODE * tail;
	int size;
} LINKED_LIST;

// Funciones para operar con una lista
LINKED_LIST linked_list_new();
int		 linked_list_size(LINKED_LIST my_list);
bool		linked_list_empty(LINKED_LIST my_list);
void		linked_list_add_head(LINKED_LIST *my_list, DATATYPE data);
void		linked_list_add_tail(LINKED_LIST *my_list, DATATYPE data);
void		linked_list_add(LINKED_LIST *my_list, DATATYPE data, int i);
DATATYPE	linked_list_get_head(LINKED_LIST my_list);
DATATYPE	linked_list_get_tail(LINKED_LIST my_list);
DATATYPE	linked_list_get(LINKED_LIST my_list, int i);
void		linked_list_rm_head(LINKED_LIST *my_list);
void		linked_list_rm_tail(LINKED_LIST *my_list);
void		linked_list_rm(LINKED_LIST *my_list, int i);
void		linked_list_clear(LINKED_LIST *my_list);
LINKED_LIST linked_list_copy(LINKED_LIST my_list);
LINKED_LIST linked_list_concat(LINKED_LIST *my_list_1, LINKED_LIST *my_list_2);
void		linked_list_printf(LINKED_LIST my_list);

#endif 
