
#ifndef LINKED_MAP_H
#define	LINKED_MAP_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct __s_node_t {
	char * key;
	char * value;
	struct __s_node_t * next;
} NODE_T;

typedef struct {
	NODE_T * head;
	NODE_T * tail;
	unsigned int size;
} LINKED_MAP_T;

typedef struct {
	char ** keys;
	unsigned int size;
} KEYSET_T;

void linked_map_new(LINKED_MAP_T * lmap);
bool linked_map_is_empty(LINKED_MAP_T lmap);
bool linked_map_put(LINKED_MAP_T * lmap, const char * key, const char * value);
const char * linked_map_get(LINKED_MAP_T lmap, const char * key);
bool linked_map_remove(LINKED_MAP_T * lmap, const char * key);
void linked_map_clear(LINKED_MAP_T * lmap);
void linked_map_destroy(LINKED_MAP_T * lmap);
void linked_map_print(LINKED_MAP_T lmap);

KEYSET_T linked_map_keyset(LINKED_MAP_T lmap);
void linked_map_keyset_destroy(KEYSET_T * keyset);

#endif

