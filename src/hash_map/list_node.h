
#ifndef ENTITY_LIST_H
#define	ENTITY_LIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct __s_node_t {
	char * key;
	char * value;
	struct __s_node_t * next;
} NODE_T;

typedef struct{
	NODE_T * head;
	NODE_T * tail;
	unsigned int size;
} LIST_NODE_T;

void list_node_new(LIST_NODE_T * list);
bool list_node_is_empty(LIST_NODE_T * list);
const char * list_node_get_value(LIST_NODE_T * list, const char * key);
bool list_node_add(LIST_NODE_T * list, const char * key, const char * value);
bool list_node_remove(LIST_NODE_T * list, const char * key);
void list_node_clear(LIST_NODE_T * list);

#endif
