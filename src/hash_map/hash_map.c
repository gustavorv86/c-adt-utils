
#include "hash_map.h"

void hash_map_new(HASH_MAP_T * map){
	hash_map_new_v2(map, DEFAULT_HASH_MAP_SIZE);
}

void hash_map_new_v2(HASH_MAP_T * map, unsigned int slot_size) {
	map->slots = calloc(slot_size, sizeof(LINKED_MAP_T));
	map->slot_size = slot_size;
	map->size = 0;
}

unsigned int __hash_map_get_key_index(const char * key, unsigned int slot_size) {
	int sum = 0;
	for(unsigned int i = 0; i < strlen(key); i++) {
		sum += key[i];
	}
	return sum % slot_size;
}

LINKED_MAP_T * __hash_map_get_index_lmap(HASH_MAP_T * map, unsigned int index) {
	return &(map->slots[index]);
}

LINKED_MAP_T * __hash_map_get_lmap(HASH_MAP_T * map, const char * key) {
	unsigned int index_key = __hash_map_get_key_index(key, map->slot_size);
	return __hash_map_get_index_lmap(map, index_key);
}

bool hash_map_is_empty(HASH_MAP_T map) {
	return map.size == 0;
}

void hash_map_put(HASH_MAP_T * map, const char * key, const char * value){
	LINKED_MAP_T * lmap = __hash_map_get_lmap(map, key);
	if(linked_map_put(lmap, key, value)) {
		map->size++;
	}
}

const char * hash_map_get(HASH_MAP_T map, const char * key) {
	LINKED_MAP_T * lmap = __hash_map_get_lmap(&map, key);
	return linked_map_get(*lmap, key);
}

void hash_map_remove(HASH_MAP_T * map, const char * key) {
	LINKED_MAP_T * lmap = __hash_map_get_lmap(map, key);
	if(linked_map_remove(lmap, key)) {
		map->size--;
	}
}

void hash_map_clear(HASH_MAP_T * map) {
	for(unsigned int i = 0; i < map->slot_size; i++) {
		LINKED_MAP_T * lmap = __hash_map_get_index_lmap(map, i);
		linked_map_clear(lmap);
	}
}

void hash_map_destroy(HASH_MAP_T * map) {
	hash_map_clear(map);
	free(map->slots);
}

void hash_map_print(HASH_MAP_T map) {
	for(unsigned int i = 0; i < map.slot_size; i++) {
		LINKED_MAP_T * lmap = __hash_map_get_index_lmap(&map, i);

		NODE_T * ptr = lmap->head;
		while(ptr != NULL) {
			printf("(%u) %s: %s\n", i, ptr->key, ptr->value);
			ptr = ptr->next;
		}

	}
}

KEYSET_T hash_map_keyset(HASH_MAP_T map) {
	KEYSET_T keyset;
	keyset.size = map.size;

	// The last index position is NULL, more easy to implements 'hash_map_keyset_clear'
	keyset.keys = calloc((keyset.size + 1), sizeof(char *));

	unsigned int count = 0;
	for(unsigned int i = 0; i < map.slot_size; i++) {
		LINKED_MAP_T * lmap = __hash_map_get_index_lmap(&map, i);

		NODE_T * ptr = lmap->head;
		while(ptr != NULL) {
			const char * key = ptr->key;

			unsigned int key_size = strlen(key) + 1;
			keyset.keys[count] = calloc(key_size, sizeof(char));
			strncpy(keyset.keys[count++], key, key_size);

			ptr = ptr->next;
		}
	}

	return keyset;
}

void hash_map_keyset_destroy(KEYSET_T * keyset) {
	linked_map_keyset_destroy(keyset);
}
