
#ifndef HASHMAP_H
#define	HASHMAP_H

#include <stdio.h>
#include "list_node.h"

/**
 * Major size, best performance but much memory.
 */
#define HASH_MAP_SIZE  ((unsigned int)6)

typedef struct {
	LIST_NODE_T slots[HASH_MAP_SIZE];
	unsigned int size;
} HASH_MAP_T;

typedef struct {
	char ** keys;
	unsigned int size;
} HASH_MAP_KEYS_T;

void hash_map_new(HASH_MAP_T * map);
void hash_map_put(HASH_MAP_T * map, const char * key, const char * value);
const char * hash_map_get(HASH_MAP_T map, const char * key);
void hash_map_remove(HASH_MAP_T * map, const char * key);
void hash_map_clear(HASH_MAP_T * map);
void hash_map_print(HASH_MAP_T map);

HASH_MAP_KEYS_T hash_map_get_keys(HASH_MAP_T map);
void hash_map_free_keys(HASH_MAP_KEYS_T * keys);

#endif
