
#include "stack.h"

STACK_T stack_new() {
	// Devuelve una pila con los campos inicializados.
	STACK_T stack;
  
	stack.head = NULL;
	stack.size = 0;
	return stack;
}

int stack_size(STACK_T in_stack) {
	// Devuelve el numero de elementos de la pila.
	return in_stack.size;
}

bool stack_empty(STACK_T in_stack) {
	// Devuelve TRUE si la pila esta vacia
	return (in_stack.size == 0);
}

void stack_push(STACK_T * inout_stack, DATATYPE in_data) {
	// Inserta un nuevo elemento en la pila.
	// La pila se pasa por referencia para poder modificar sus campos.
	
	// reservamos memoria para el nuevo nodo
	STACK_NODE_T * ptr_stack_node = malloc(sizeof(STACK_NODE_T));
	// asignamos el valor
	ptr_stack_node->data = in_data;
	// insertamos el nodo al principio, antes que 'head'
	ptr_stack_node->ptr_next = inout_stack->head;
	// cambiamos la direccion de 'head', que ahora es 'ptr_stack_node'
	inout_stack->head = ptr_stack_node;
	// incrementamos 'size'
	(inout_stack->size)++;
}

bool stack_pop(STACK_T * inout_stack, DATATYPE * out_data) {
	// Borra el primer elemento de la pila.
	// La pila se pasa por referencia para poder modificar sus campos.
	
	if(stack_empty(*inout_stack)) {
		return false;
	}
	
	// asignamos el nodo que queremos borrar
	STACK_NODE_T * ptr_del_node = inout_stack->head;
	// obtenemos el dato a devolver
	*out_data = ptr_del_node->data;
	// avanzamos el nodo de la pila
	inout_stack->head = inout_stack->head->ptr_next;
	// borramos el nodo
	free(ptr_del_node);
	// decrementamos 'size'
	(inout_stack->size)--;
	return true;
}

void stack_destroy(STACK_T * inout_stack) {
	while(inout_stack->head != NULL) {
		STACK_NODE_T * ptr_del_node = inout_stack->head;
		inout_stack->head = inout_stack->head->ptr_next;
		free(ptr_del_node);
	}
	inout_stack->head = NULL;
	inout_stack->size = 0;
}

void stack_print(STACK_T in_stack) {
	// recorremos la pila con un puntero auxiliar;
	STACK_NODE_T * ptr_aux_node;
	
	// mostrar el numero de elementos
	printf("Size: %d \n", stack_size(in_stack));
	// recorremos la pila hasta que no sea NULL
	ptr_aux_node = in_stack.head;
	while(ptr_aux_node != NULL) {
		// pintar el elemento por pantalla
		printf(" "DATATYPE_PRINTF" -> ",ptr_aux_node->data);
		// avanzar el puntero
		ptr_aux_node = ptr_aux_node->ptr_next;
	}
	printf("NULL \n\n");
}
