/*
	File: linked_list_main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main() {
	LINKED_LIST my_list, copy_list;
	
	my_list = linked_list_new();
	linked_list_add_head(&my_list, 10);
	linked_list_add_tail(&my_list, 11);
	linked_list_add_head(&my_list, 12);
	linked_list_add_tail(&my_list, 13);
	
	linked_list_printf(my_list);
	
	linked_list_rm_head(&my_list);
	linked_list_rm_tail(&my_list);
	
	linked_list_printf(my_list);
	
	linked_list_rm_tail(&my_list);
	linked_list_rm_tail(&my_list);
	linked_list_rm_tail(&my_list);
	
	linked_list_printf(my_list);

	linked_list_add(&my_list, 10, 0);
	linked_list_printf(my_list);
	linked_list_add(&my_list, 20, 1);
	linked_list_printf(my_list);
	linked_list_add(&my_list, 30, 0);
	linked_list_printf(my_list);
	linked_list_add(&my_list, 40, 1);
	linked_list_printf(my_list);
	linked_list_add(&my_list, 50, 2);
	linked_list_printf(my_list);
	linked_list_add(&my_list, 60, 1);
	linked_list_printf(my_list);
	linked_list_add(&my_list, 70, 3);
	linked_list_printf(my_list);
	linked_list_add(&my_list, 80, 4);
	linked_list_printf(my_list);
	
	linked_list_rm(&my_list, 4);
	linked_list_printf(my_list);
	
	linked_list_rm(&my_list, 0);
	linked_list_printf(my_list);
	
	copy_list = linked_list_copy(my_list);
	linked_list_rm_head(&copy_list);
	linked_list_rm_tail(&copy_list);
	
	linked_list_printf(copy_list);
	
	my_list = linked_list_concat(&my_list, &copy_list);
	
	linked_list_printf(my_list);
	
	return EXIT_SUCCESS;
}
