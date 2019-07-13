/*
	File: linked_list.c
*/

#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

LINKED_LIST linked_list_new() {
	// Devuelve una lista con los campos inicializados.
	LINKED_LIST my_list;
  
	my_list.head = NULL;
	my_list.tail = NULL;
	my_list.size = 0;
	return my_list;
}

void linked_list_init(LINKED_LIST *my_list) {
	// Inicializa los campos de my_list.
	my_list->head = NULL;
	my_list->tail = NULL;
	my_list->size = 0;
}

int linked_list_size(LINKED_LIST my_list) {
	// Devuelve el numero de elementos de la lista.
	return my_list.size;
}

bool linked_list_empty(LINKED_LIST my_list) {
	// Devuelve TRUE si la lista esta vacia.
	return (my_list.size == 0);
}

void linked_list_add_head(LINKED_LIST *my_list, DATATYPE data) {
	// Inserta un nuevo elemento en la lista por el principio.
	// La lista se pasa por referencia para poder modificar sus campos.
	LINKED_LIST_NODE* ptr_linked_list_node;
	
	// reservamos memoria para el nuevo nodo
	ptr_linked_list_node = malloc(sizeof(LINKED_LIST_NODE));
	// asignamos el valor
	ptr_linked_list_node->data = data;
	ptr_linked_list_node->ptr_next = NULL;
	// si la lista es vacia, los punteros de inicio y fin apuntan al mismo nodo
	if(linked_list_empty(*my_list)) {
		my_list->head = ptr_linked_list_node;
		my_list->tail = ptr_linked_list_node;
	} else {
		// insertar al principio de la lista
		ptr_linked_list_node->ptr_next = my_list->head;
		// cambiamos la direccion de 'head', que ahora es 'ptr_linked_list_node'
		my_list->head = ptr_linked_list_node;
	}	
	// incrementamos 'size'
	(my_list->size)++;
}

void linked_list_add_tail(LINKED_LIST *my_list, DATATYPE data) {
	// Inserta un nuevo elemento en la lista por el final.
	// La lista se pasa por referencia para poder modificar sus campos.
	LINKED_LIST_NODE *ptr_linked_list_node;
	
	// reservamos memoria para el nuevo nodo
	ptr_linked_list_node = malloc(sizeof(LINKED_LIST_NODE));
	// asignamos el valor
	ptr_linked_list_node->data = data;
	ptr_linked_list_node->ptr_next = NULL;
	// si la lista es vacia, los punteros de inicio y fin apuntan al mismo nodo
	if(linked_list_empty(*my_list)) {
		my_list->head = ptr_linked_list_node;
		my_list->tail = ptr_linked_list_node;
	} else {
		// insertar al final de la lista
		my_list->tail->ptr_next = ptr_linked_list_node;
		// cambiamos la direccion de 'tail', que ahora es 'ptr_linked_list_node'
		my_list->tail = ptr_linked_list_node;
	}	
	// incrementamos 'size'
	(my_list->size)++;
}

void linked_list_add(LINKED_LIST* my_list, DATATYPE data, int index) {
	// Inserta un nuevo elemento en la posicion 'index'.
	// La lista se pasa por referencia para poder modificar sus campos.
	LINKED_LIST_NODE *ptr_linked_list_node, *ptr_aux_node;
	int i;
	
	if(index <= 0) {
		// insertar al principio
		linked_list_add_head(my_list, data);
	} else if(index >= linked_list_size(*my_list)) {
		// insertar al final
		linked_list_add_tail(my_list, data);
	} else {
		// recorremos la lista 'index-1' posiciones
		ptr_aux_node = my_list->head;
		for(i=0 ; i<(index-1) ; i++) {
			ptr_aux_node = ptr_aux_node->ptr_next;
		}
		// tenemos que insertar el nuevo nodo entre 
		// 'ptr_aux_node' y 'ptr_aux_node->next'
		
		// creamos el nuevo nodo
		ptr_linked_list_node = malloc(sizeof(LINKED_LIST_NODE));
		ptr_linked_list_node->data = data;
		// primero asignamos el puntero a 'ptr_aux_node->ptr_next' 
		// porque sino perdemos la lista
		ptr_linked_list_node->ptr_next = ptr_aux_node->ptr_next;
		// asignamos 'ptr_aux_node->next' al nuevo nodo
		ptr_aux_node->ptr_next = ptr_linked_list_node;
		// incrementamos 'size'
		(my_list->size)++;
	}
}

DATATYPE linked_list_get_head(LINKED_LIST my_list) {
	// Devuelve el primer elemento de la lista.
	if(linked_list_empty(my_list)) {
		return DATATYPE_ERR;
	}
	return my_list.head->data;
}

DATATYPE linked_list_get_tail(LINKED_LIST my_list) {
	// Devuelve el ultimo elemento de la lista.
	if(linked_list_empty(my_list)) {
		return DATATYPE_ERR;
	}
	return my_list.tail->data;
}

DATATYPE linked_list_get(LINKED_LIST my_list, int index) {
	// Devuelve el elemento que ocupa la posicion 'index'.
	LINKED_LIST_NODE *ptr_aux_node;
	int i;
	
	if(index <= 0) {
		// devolver el primer elemento
		return linked_list_get_head(my_list);
	} else if(index >= linked_list_size(my_list)) {
		// devolver el ultimo elemento
		return linked_list_get_tail(my_list);
	} else {
		// recorremos la lista 'index' posiciones
		ptr_aux_node = my_list.head;
		for(i=0 ; i<index ; i++) {
			ptr_aux_node = ptr_aux_node->ptr_next;
		}
		// devolvemos el dato
		return ptr_aux_node->data;
	}
}

void linked_list_rm_head(LINKED_LIST *my_list) {
	// Borra el primer elemento de la lista.
	// La lista se pasa por referencia para poder modificar sus campos.
	LINKED_LIST_NODE *ptr_rm_node;
	
	// si la lista es vacia no hacemos nada
	if(linked_list_empty(*my_list)) {
		return;
	}
	// si solo tenemos un elemento, lo borramos directamente
	if(linked_list_size(*my_list) == 1) {
		free(my_list->head);
		linked_list_init(my_list);
	} else {
		// asignamos el nodo que queremos borrar
		ptr_rm_node = my_list->head;
		// avanzamos el nodo de la lista
		my_list->head = my_list->head->ptr_next;
		// borramos el nodo
		free(ptr_rm_node);
		// decrementamos 'size'
		(my_list->size)--;
	}
}

void linked_list_rm_tail(LINKED_LIST *my_list) {
	// Borra el ultimo elemento de la lista.
	// La lista se pasa por referencia para poder modificar sus campos.
	LINKED_LIST_NODE *ptr_aux_node;
	
	// si la lista es vacia no hacemos nada
	if(linked_list_empty(*my_list)) {
		return;
	}
	// si solo tenemos un elemento, lo borramos directamente
	if(linked_list_size(*my_list) == 1) {
		free(my_list->head);
		linked_list_init(my_list);
	} else {
		// para borrar el ultimo nodo es necesario recorrer toda la lista, ya
		// que necesitamos el puntero del nodo anterior.
		ptr_aux_node = my_list->head;
		while(ptr_aux_node->ptr_next->ptr_next != NULL){
			ptr_aux_node = ptr_aux_node->ptr_next;
		}
		// 'ptr_aux_node' apunta al penultimo elemento de la lista
		// 'ptr_aux_node->ptr_next' apunta al ultimo elemento de la lista y tiene
		//	  la misma direccion que 'my_list->tail'

		// borramos el ultimo nodo
		free(my_list->tail);
		// cambiamos la direccion de 'my_list->tail' al penultimo nodo
		my_list->tail = ptr_aux_node;
		// asignamos el siguiente nodo de 'tail' a NULL
		my_list->tail->ptr_next = NULL;
		// decrementamos 'size'
		(my_list->size)--;   
	}
}

void linked_list_rm(LINKED_LIST* my_list, int index) {
	// Borra el elemento de la posicion 'index'.
	// La lista se pasa por referencia para poder modificar sus campos.
	LINKED_LIST_NODE *ptr_aux_node, *ptr_rm_node;
	int i;
	
	if(index <= 0) {
		// borrar el primer elemento
		linked_list_rm_head(my_list);
	} else if(index >= linked_list_size(*my_list)) {
		// borrar el ultimo elemento
		linked_list_rm_tail(my_list);
	} else {
		// recorremos la lista 'index-1' posiciones
		ptr_aux_node = my_list->head;
		for(i=0 ; i<(index-1) ; i++) {
			ptr_aux_node = ptr_aux_node->ptr_next;
		}
		// tenemos que borrar el nodo 'ptr_aux_node->ptr_next'
		ptr_rm_node = ptr_aux_node->ptr_next;
		// nos saltamos el nodo que queremos borrar
		ptr_aux_node->ptr_next = ptr_aux_node->ptr_next->ptr_next;
		// borramos el nodo
		free(ptr_rm_node);
		// decrementamos 'size'
		(my_list->size)--;
	}
}

void linked_list_clear(LINKED_LIST *my_list) {
	// Borra por completo una lista.
	LINKED_LIST_NODE *ptr_aux_node, *ptr_rm_node;
	
	ptr_aux_node = my_list->head;
	while(ptr_aux_node != NULL) {
		// asignamos el nodo que queremos borrar
		ptr_rm_node = ptr_aux_node;
		// avanzamos el puntero
		ptr_aux_node = ptr_aux_node->ptr_next;
		// borramos el nodo
		free(ptr_rm_node);
	}
	// inicializamos los campos de la estructura
	linked_list_init(my_list);
}

LINKED_LIST linked_list_copy(LINKED_LIST my_list) {
	// Copia una lista entera.
	LINKED_LIST copy_list;
	LINKED_LIST_NODE *ptr_aux_node;
	
	copy_list = linked_list_new();
	// recorremos la lista 'my_list'
	ptr_aux_node = my_list.head;
	while(ptr_aux_node != NULL) {
		// insertamos en 'copy_list' los elementos por el final
		linked_list_add_tail(&copy_list, ptr_aux_node->data);
		// azanzamos el puntero
		ptr_aux_node = ptr_aux_node->ptr_next;
	}
	// devolvemos la lista copia
	return copy_list;
}

LINKED_LIST linked_list_concat(LINKED_LIST *my_list_1, LINKED_LIST *my_list_2) {
	// Concatena dos listas
	LINKED_LIST my_list;
	
	// solo es necesario mover los punteros
	my_list = linked_list_new();
	my_list.head = my_list_1->head;
	my_list_1->tail->ptr_next = my_list_2->head;
	my_list.tail = my_list_2->tail;
	my_list.size = my_list_1->size + my_list_2->size;
	// inicializamos los campos de las estructuras
	linked_list_init(my_list_1);
	linked_list_init(my_list_2);
	// devolvemos la lista concatenada
	return my_list;
}

void linked_list_printf(LINKED_LIST my_list) {
	// Recorremos la lista con un puntero auxiliar;
	LINKED_LIST_NODE* ptr_aux_node;
	
	// mostrar el numero de elementos
	printf("Size: %d \n", linked_list_size(my_list));
	// recorremos la lista hasta que no sea NULL
	ptr_aux_node = my_list.head;
	while(ptr_aux_node != NULL) {
		// pintar el elemento por pantalla
		printf(" "DATATYPE_PRINTF" -> ",ptr_aux_node->data);
		// avanzar el puntero
		ptr_aux_node = ptr_aux_node->ptr_next;
	}
	printf("NULL \n\n");
}
