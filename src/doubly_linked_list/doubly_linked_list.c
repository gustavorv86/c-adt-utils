/*
	File: doubly_linked_list.c
*/

#include "doubly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

DOUBLY_LINKED_LIST doubly_linked_list_new() {
	// Devuelve una lista con los campos inicializados.
	DOUBLY_LINKED_LIST my_list;
  
	my_list.head = NULL;
	my_list.tail = NULL;
	my_list.size = 0;
	return my_list;
}

void doubly_linked_list_init(DOUBLY_LINKED_LIST *my_list) {
	// Inicializa los campos de my_list.
	my_list->head = NULL;
	my_list->tail = NULL;
	my_list->size = 0;
}

int doubly_linked_list_size(DOUBLY_LINKED_LIST my_list) {
	// Devuelve el numero de elementos de la lista.
	return my_list.size;
}

bool doubly_linked_list_empty(DOUBLY_LINKED_LIST my_list) {
	// Devuelve TRUE si la lista esta vacia.
	return (my_list.size == 0);
}

DOUBLY_LINKED_LIST_NODE* __doubly_linked_list_get_node(DOUBLY_LINKED_LIST my_list, int index) {
	// Devuelve el puntero al nodo que ocupa la posicion 'index'.
	// Recorre la lista por el extremo mas cercano a la posicion 'index'
	int i, size;
	DOUBLY_LINKED_LIST_NODE *ptr_aux_node;
	
	size = doubly_linked_list_size(my_list);
	if(index <= size/2) {
		// recorremos la lista desde 'head' hasta 'index'
		ptr_aux_node = my_list.head;
		for(i=0 ; i<index ; i++) {
			ptr_aux_node = ptr_aux_node->ptr_next;
		}
	} else {
		// recorremos la lista desde 'tail' hasta 'index'
		ptr_aux_node = my_list.tail;
		for(i=(size-1) ; i>index ; i--) {
			ptr_aux_node = ptr_aux_node->ptr_back;
		}
	}
	return ptr_aux_node;
}

void doubly_linked_list_add_head(DOUBLY_LINKED_LIST *my_list, DATATYPE data) {
	// Inserta un nuevo elemento en la lista por el principio.
	// La lista se pasa por referencia para poder modificar sus campos.
	DOUBLY_LINKED_LIST_NODE *ptr_linked_list_node;
	
	// reservamos memoria para el nuevo nodo
	ptr_linked_list_node = malloc(sizeof(DOUBLY_LINKED_LIST_NODE));
	// asignamos el valor
	ptr_linked_list_node->data = data;
	ptr_linked_list_node->ptr_next = NULL;
	ptr_linked_list_node->ptr_back = NULL;
	// si la lista es vacia, los punteros de inicio y fin apuntan al mismo nodo
	if(doubly_linked_list_empty(*my_list)) {
		my_list->head = ptr_linked_list_node;
		my_list->tail = ptr_linked_list_node;
	} else {
		// insertar al principio de la lista
		ptr_linked_list_node->ptr_next = my_list->head;
		my_list->head->ptr_back = ptr_linked_list_node;
		// cambiamos la direccion de 'head', que ahora es 'ptr_linked_list_node'
		my_list->head = ptr_linked_list_node;
	}	
	// incrementamos 'size'
	(my_list->size)++;
}

void doubly_linked_list_add_tail(DOUBLY_LINKED_LIST *my_list, DATATYPE data) {
	// Inserta un nuevo elemento en la lista por el final.
	// La lista se pasa por referencia para poder modificar sus campos.
	DOUBLY_LINKED_LIST_NODE *ptr_linked_list_node;
	
	// reservamos memoria para el nuevo nodo
	ptr_linked_list_node = malloc(sizeof(DOUBLY_LINKED_LIST_NODE));
	// asignamos el valor
	ptr_linked_list_node->data = data;
	ptr_linked_list_node->ptr_next = NULL;
	ptr_linked_list_node->ptr_back = NULL;
	// si la lista es vacia, los punteros de inicio y fin apuntan al mismo nodo
	if(doubly_linked_list_empty(*my_list)) {
		my_list->head = ptr_linked_list_node;
		my_list->tail = ptr_linked_list_node;
	} else {
		// insertar al final de la lista
		my_list->tail->ptr_next = ptr_linked_list_node;
		ptr_linked_list_node->ptr_back = my_list->tail;
		// cambiamos la direccion de 'tail', que ahora es 'ptr_linked_list_node'
		my_list->tail = ptr_linked_list_node;
	}	
	// incrementamos 'size'
	(my_list->size)++;
}

void doubly_linked_list_add(DOUBLY_LINKED_LIST *my_list, DATATYPE data, int index) {
	// Inserta un nuevo elemento en la posicion 'index'.
	// La lista se pasa por referencia para poder modificar sus campos.
	DOUBLY_LINKED_LIST_NODE *ptr_new_node, *ptr_aux_node;

	if(index <= 0) {
		// insertar al principio
		doubly_linked_list_add_head(my_list, data);
	} else if(index >= doubly_linked_list_size(*my_list)) {
		// insertar al final
		doubly_linked_list_add_tail(my_list, data);
	} else {
		// insertamos por el extremo mas cercano
		ptr_aux_node = __doubly_linked_list_get_node(*my_list, index);
		// creamos el nuevo nodo
		ptr_new_node = malloc(sizeof(DOUBLY_LINKED_LIST_NODE));
		ptr_new_node->data = data;
		// insertar el nuevo nodo moviendo los punteros
		ptr_new_node->ptr_next = ptr_aux_node;
		ptr_new_node->ptr_back = ptr_aux_node->ptr_back;
		ptr_new_node->ptr_back->ptr_next = ptr_new_node;
		ptr_new_node->ptr_next->ptr_back = ptr_new_node;
		// incrementamos 'size'
		(my_list->size)++;
	}
}

DATATYPE doubly_linked_list_get_head(DOUBLY_LINKED_LIST my_list) {
	// Devuelve el primer elemento de la lista.
	if(doubly_linked_list_empty(my_list)) {
		return DATATYPE_ERR;
	}
	return my_list.head->data;
}

DATATYPE doubly_linked_list_get_tail(DOUBLY_LINKED_LIST my_list) {
	// Devuelve el ultimo elemento de la lista.
	if(doubly_linked_list_empty(my_list)) {
		return DATATYPE_ERR;
	}
	return my_list.tail->data;
}

DATATYPE doubly_linked_list_get(DOUBLY_LINKED_LIST my_list, int index) {
	// Devuelve el elemento que ocupa la posicion 'index'.
	DOUBLY_LINKED_LIST_NODE *ptr_aux_node;

	if(index <= 0) {
		// devolver el primer elemento
		return doubly_linked_list_get_head(my_list);
	} else if(index >= doubly_linked_list_size(my_list)) {
		// devolver el ultimo elemento
		return doubly_linked_list_get_tail(my_list);
	} else {
		ptr_aux_node = __doubly_linked_list_get_node(my_list, index);
		// devolvemos el dato
		return ptr_aux_node->data;
	}
}

void doubly_linked_list_del_head(DOUBLY_LINKED_LIST *my_list) {
	// Borra el primer elemento de la lista.
	// La lista se pasa por referencia para poder modificar sus campos.
	DOUBLY_LINKED_LIST_NODE *ptr_del_node;
	
	// si la lista es vacia no hacemos nada
	if(doubly_linked_list_empty(*my_list)) {
		return;
	}
	// si solo tenemos un elemento, lo borramos directamente
	if(doubly_linked_list_size(*my_list) == 1) {
		free(my_list->head);
		doubly_linked_list_init(my_list);
	} else {
		// asignamos el nodo que queremos borrar
		ptr_del_node = my_list->head;
		// avanzamos el nodo de la lista
		my_list->head = my_list->head->ptr_next;
		my_list->head->ptr_back = NULL;
		// borramos el nodo
		free(ptr_del_node);
		// decrementamos 'size'
		(my_list->size)--;
	}
}

void doubly_linked_list_del_tail(DOUBLY_LINKED_LIST *my_list) {
	// Borra el ultimo elemento de la lista.
	// La lista se pasa por referencia para poder modificar sus campos.
	DOUBLY_LINKED_LIST_NODE *ptr_del_node;
	
	// si la lista es vacia no hacemos nada
	if(doubly_linked_list_empty(*my_list)) {
		return;
	}
	// si solo tenemos un elemento, lo borramos directamente
	if(doubly_linked_list_size(*my_list) == 1) {
		free(my_list->head);
		doubly_linked_list_init(my_list);
	} else {
		// asignamos el nodo que queremos borrar
		ptr_del_node = my_list->tail;
		// retrocedemos el nodo de la lista
		my_list->tail = my_list->tail->ptr_back;
		my_list->tail->ptr_next = NULL;
		// borramos el nodo
		free(ptr_del_node);
		// decrementamos 'size'
		(my_list->size)--;
	}
}

void doubly_linked_list_del(DOUBLY_LINKED_LIST *my_list, int index) {
	// Borra el elemento de la posicion 'index'.
	// La lista se pasa por referencia para poder modificar sus campos.
	DOUBLY_LINKED_LIST_NODE *ptr_del_node;
	
	if(index <= 0) {
		// borrar el primer elemento
		doubly_linked_list_del_head(my_list);
	} else if(index >= doubly_linked_list_size(*my_list)) {
		// borrar el ultimo elemento
		doubly_linked_list_del_tail(my_list);
	} else {
		// obtener el nodo que queremos borrar
		ptr_del_node = __doubly_linked_list_get_node(*my_list, index);
		// cambiamos los punteros para saltarnos el nodo 'ptr_del_node'
		ptr_del_node->ptr_back->ptr_next = ptr_del_node->ptr_next;
		ptr_del_node->ptr_next->ptr_back = ptr_del_node->ptr_back;
		// borramos el nodo
		free(ptr_del_node);
		// decrementamos 'size'
		(my_list->size)--;
	}
}

void doubly_linked_list_clear(DOUBLY_LINKED_LIST *my_list) {
	// Borra por completo una lista.
	DOUBLY_LINKED_LIST_NODE *ptr_aux_node, *ptr_del_node;
	
	ptr_aux_node = my_list->head;
	while(ptr_aux_node != NULL) {
		// asignamos el nodo que queremos borrar
		ptr_del_node = ptr_aux_node;
		// avanzamos el puntero
		ptr_aux_node = ptr_aux_node->ptr_next;
		// borramos el nodo
		free(ptr_del_node);
	}
	// inicializamos los campos de la estructura
	doubly_linked_list_init(my_list);
}

DOUBLY_LINKED_LIST doubly_linked_list_copy(DOUBLY_LINKED_LIST my_list) {
	// Copia una lista entera.
	DOUBLY_LINKED_LIST copy_list;
	DOUBLY_LINKED_LIST_NODE *ptr_aux_node;
	
	copy_list = doubly_linked_list_new();
	// recorremos la lista 'my_list'
	ptr_aux_node = my_list.head;
	while(ptr_aux_node != NULL) {
		// insertamos en 'copy_list' los elementos por el final
		doubly_linked_list_new(&copy_list, ptr_aux_node->data);
		// azanzamos el puntero
		ptr_aux_node = ptr_aux_node->ptr_next;
	}
	// devolvemos la lista copia
	return copy_list;
}

DOUBLY_LINKED_LIST doubly_linked_list_concat(DOUBLY_LINKED_LIST *my_list_1, DOUBLY_LINKED_LIST *my_list_2) {
	// Concatena dos listas
	DOUBLY_LINKED_LIST my_list;
	
	// solo es necesario mover los punteros
	my_list = doubly_linked_list_new();
	my_list.head = my_list_1->head;
	my_list_1->tail->ptr_next = my_list_2->head;
	my_list_2->head->ptr_back = my_list_1->tail;
	my_list.tail = my_list_2->tail;
	my_list.size = my_list_1->size + my_list_2->size;
	// inicializamos los campos de las estructuras
	doubly_linked_list_init(my_list_1);
	doubly_linked_list_init(my_list_2);
	// devolvemos la lista concatenada
	return my_list;
}

void doubly_linked_list_printf(DOUBLY_LINKED_LIST my_list) {
	// Recorremos la lista con un puntero auxiliar;
	DOUBLY_LINKED_LIST_NODE  *ptr_aux_node;
	
	// mostrar el numero de elementos
	printf("Size: %d \n", doubly_linked_list_size(my_list));
	// recorremos la lista hasta que no sea NULL
	ptr_aux_node = my_list.head;
	while(ptr_aux_node != NULL) {
		// pintar el elemento por pantalla
		printf(" "DATATYPE_PRINTF" <-> ",ptr_aux_node->data);
		// avanzar el puntero
		ptr_aux_node = ptr_aux_node->ptr_next;
	}
	printf("NULL \n\n");
}
