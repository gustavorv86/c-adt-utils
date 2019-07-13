/*
	File: stack.c
*/

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

STACK stack_new() {
	// Devuelve una pila con los campos inicializados.
	STACK my_stack;
  
	my_stack.head = NULL;
	my_stack.size = 0;
	return my_stack;
}

int stack_size(STACK my_stack) {
	// Devuelve el numero de elementos de la pila.
	return my_stack.size;
}

bool stack_empty(STACK my_stack) {
	// Devuelve TRUE si la pila esta vacia
	return (my_stack.size == 0);
}

void stack_push(STACK* ref_my_stack, DATATYPE data) {
	// Inserta un nuevo elemento en la pila.
	// La pila se pasa por referencia para poder modificar sus campos.
	STACK_NODE* ptr_stack_node;
	
	// reservamos memoria para el nuevo nodo
	ptr_stack_node = malloc(sizeof(STACK_NODE));
	// asignamos el valor
	ptr_stack_node->data = data;
	// insertamos el nodo al principio, antes que 'head'
	ptr_stack_node->ptr_next = ref_my_stack->head;
	// cambiamos la direccion de 'head', que ahora es 'ptr_stack_node'
	ref_my_stack->head = ptr_stack_node;
	// incrementamos 'size'
	(ref_my_stack->size)++;
}

DATATYPE stack_pop(STACK* ref_my_stack) {
	// Borra el primer elemento de la pila.
	// La pila se pasa por referencia para poder modificar sus campos.
	STACK_NODE* ptr_del_node;
	DATATYPE ret_value;
	
	if(stack_empty(*ref_my_stack)) {
		return DATATYPE_ERR;
	}
	
	// asignamos el nodo que queremos borrar
	ptr_del_node = ref_my_stack->head;
	ret_value = ptr_del_node->data;
	// avanzamos el nodo de la pila
	ref_my_stack->head = ref_my_stack->head->ptr_next;
	// borramos el nodo
	free(ptr_del_node);
	// decrementamos 'size'
	(ref_my_stack->size)--;
	return ret_value;
}

void stack_printf(STACK my_stack) {
	// Recorremos la pila con un puntero auxiliar;
	STACK_NODE* ptr_aux_node;
	
	// mostrar el numero de elementos
	printf("Size: %d \n", stack_size(my_stack));
	// recorremos la pila hasta que no sea NULL
	ptr_aux_node = my_stack.head;
	while(ptr_aux_node != NULL) {
		// pintar el elemento por pantalla
		printf(" "DATATYPE_PRINTF" -> ",ptr_aux_node->data);
		// avanzar el puntero
		ptr_aux_node = ptr_aux_node->ptr_next;
	}
	printf("NULL \n\n");
}
