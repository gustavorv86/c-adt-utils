
#ifndef HASHMAP_H
#define	HASHMAP_H

#include <stdio.h>
#include "linked_map.h"

/**
 * Major size, best performance but much memory.
 */
#define DEFAULT_HASH_MAP_SIZE  ((unsigned int)128)

typedef struct {
	LINKED_MAP_T * slots;
	unsigned int slot_size;
	unsigned int size;
} HASH_MAP_T;

void hash_map_new(HASH_MAP_T * map);
void hash_map_new_v2(HASH_MAP_T * map, unsigned int slot_size);
bool hash_map_is_empty(HASH_MAP_T map);
void hash_map_put(HASH_MAP_T * map, const char * key, const char * value);
const char * hash_map_get(HASH_MAP_T map, const char * key);
void hash_map_remove(HASH_MAP_T * map, const char * key);
void hash_map_clear(HASH_MAP_T * map);
void hash_map_destroy(HASH_MAP_T * map);
void hash_map_print(HASH_MAP_T map);

KEYSET_T hash_map_keyset(HASH_MAP_T map);
void hash_map_keyset_destroy(KEYSET_T * keys);

#endif
