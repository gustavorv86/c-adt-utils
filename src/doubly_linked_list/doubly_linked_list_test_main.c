/*
    File: doubly_linked_list_main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

int main() {
    int size;
    DOUBLY_LINKED_LIST my_list;
    
    my_list = doubly_linked_list_new();
    doubly_linked_list_add_head(&my_list, 10);
    doubly_linked_list_add_tail(&my_list, 11);
    doubly_linked_list_add_head(&my_list, 12);
    doubly_linked_list_add_tail(&my_list, 13);
    doubly_linked_list_add_head(&my_list, 14);
    doubly_linked_list_add_tail(&my_list, 15);
    
    doubly_linked_list_printf(my_list);
    
    // borramos el 3er elemento, indice 2 (el primer elemento tiene indice = 0)
    doubly_linked_list_del(&my_list, 2);
    
    doubly_linked_list_printf(my_list);
    
    // insertar en la penultima posicion
    size = doubly_linked_list_size(my_list);
    doubly_linked_list_add(&my_list, 16 , size-1);
    
    // insertar en la antepenultima posicion
    size = doubly_linked_list_size(my_list);
    doubly_linked_list_add(&my_list, 17 , size-2);
    
    doubly_linked_list_printf(my_list);
    
    // obtener segundo elemento
    printf("\t"DATATYPE_PRINTF" \n",doubly_linked_list_get(my_list, 1));
    
    // obtener penultimo elemento
    size = doubly_linked_list_size(my_list);
    printf("\t"DATATYPE_PRINTF" \n",doubly_linked_list_get(my_list, size-2));

    // borrar por completo la lista
    doubly_linked_list_clear(&my_list);
        
    return EXIT_SUCCESS;
}
