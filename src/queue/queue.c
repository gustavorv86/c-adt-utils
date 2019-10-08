/*
	File: queue.c
*/

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

void _queue_init(QUEUE *my_queue) {
	my_queue->head = NULL;
	my_queue->tail = NULL;
	my_queue->size = 0;
}

QUEUE queue_new(void) {
	// Devuelve una cola con los campos inicializados.
	QUEUE my_queue;

	_queue_init(&my_queue);
	return my_queue;
}

int queue_size(QUEUE my_queue) {
	// Devuelve el numero de elementos de la cola.
	return my_queue.size;
}

bool queue_empty(QUEUE my_queue) {
	// Devuelve TRUE si la cola esta vacia.
	return (my_queue.size == 0);
}

void queue_enqueue(QUEUE *my_queue, DATATYPE data) {
	// Inserta un nuevo elemento en la cola por el final.
	// La cola se pasa por referencia para poder modificar sus campos.
	QUEUE_NODE *ptr_queue_node;
	
	// reservamos memoria para el nuevo nodo
	ptr_queue_node = malloc(sizeof(QUEUE_NODE));
	// asignamos el valor
	ptr_queue_node->data = data;
	ptr_queue_node->ptr_next = NULL;
	// si la cola es vacia, los punteros de inicio y fin apuntan al mismo nodo
	if(queue_empty(*my_queue)) {
		my_queue->head = ptr_queue_node;
		my_queue->tail = ptr_queue_node;
	} else {
		// insertar al final de la cola
		my_queue->tail->ptr_next = ptr_queue_node;
		// cambiamos la direccion de 'tail', que ahora es 'ptr_queue_node'
		my_queue->tail = ptr_queue_node;
	}	
	// incrementamos 'size'
	(my_queue->size)++;
}

bool queue_dequeue(QUEUE *my_queue, DATATYPE * data) {
	// Borra el primer elemento de la cola.
	// La cola se pasa por referencia para poder modificar sus campos.
	QUEUE_NODE *ptr_del_node;
	
	// si la cola es vacia no hacemos nada
	if(queue_empty(*my_queue)) {
		return false;
	}
	// asignamos el valor de retorno
	*data = my_queue->head->data;
	// si solo tenemos un elemento, lo borramos directamente
	if(queue_size(*my_queue) == 1) {
		free(my_queue->head);
		_queue_init(my_queue);
	} else {
		// asignamos el nodo que queremos borrar
		ptr_del_node = my_queue->head;
		// avanzamos el nodo de la cola
		my_queue->head = my_queue->head->ptr_next;
		// borramos el nodo
		free(ptr_del_node);
		// decrementamos 'size'
		(my_queue->size)--;
	}
	return true;
}

void queue_destroy(QUEUE *my_queue) {
	// Borra por completo una cola.
	while(my_queue->head != NULL) {
		// asignamos el nodo que queremos borrar
		QUEUE_NODE * ptr_del_node = my_queue->head;
		// avanzamos el puntero
		my_queue->head = my_queue->head->ptr_next;
		// borramos el nodo
		free(ptr_del_node);
	}
	// inicializamos los campos de la estructura
	_queue_init(my_queue);
}

void queue_print(QUEUE my_queue) {
	// Recorremos la cola con un puntero auxiliar;
	QUEUE_NODE * ptr_aux_node;
	
	// mostrar el numero de elementos
	printf("Size: %d \n", queue_size(my_queue));
	// recorremos la cola hasta que no sea NULL
	ptr_aux_node = my_queue.head;
	while(ptr_aux_node != NULL) {
		// pintar el elemento por pantalla
		printf(" "DATATYPE_PRINTF" <- ",ptr_aux_node->data);
		// avanzar el puntero
		ptr_aux_node = ptr_aux_node->ptr_next;
	}
	printf("NULL \n\n");
}
