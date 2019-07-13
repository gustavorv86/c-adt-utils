
#include "hash_map.h"

void hash_map_new(HASH_MAP_T * map){
	for(unsigned int i = 0 ; i < HASH_MAP_SIZE ; i++){
		LIST_NODE_T * list = &(map->slots[i]);
		list_node_new(list);
	}
	map->size = 0;
}

unsigned int __hash_map_get_key_index(const char * key) {
	int sum = 0;
	for(unsigned int i = 0; i < strlen(key); i++) {
		sum += key[i];
	}
	return sum % HASH_MAP_SIZE;
}

LIST_NODE_T * __hash_map_get_index_list(HASH_MAP_T * map, unsigned int index) {
	return &(map->slots[index]);
}

LIST_NODE_T * __hash_map_get_list(HASH_MAP_T * map, const char * key) {
	unsigned int index_key = __hash_map_get_key_index(key);
	return __hash_map_get_index_list(map, index_key);
}

void hash_map_put(HASH_MAP_T * map, const char * key, const char * value){
	LIST_NODE_T * list = __hash_map_get_list(map, key);
	if(list_node_add(list, key, value)) {
		map->size++;
	}
}

const char * hash_map_get(HASH_MAP_T map, const char * key) {
	LIST_NODE_T * list = __hash_map_get_list(&map, key);
	return list_node_get_value(list, key);
}

void hash_map_remove(HASH_MAP_T * map, const char * key) {
	LIST_NODE_T * list = __hash_map_get_list(map, key);
	if(list_node_remove(list, key)) {
		map->size--;
	}
}

void hash_map_clear(HASH_MAP_T * map) {
	for(unsigned int i = 0; i < HASH_MAP_SIZE; i++) {
		LIST_NODE_T * list = __hash_map_get_index_list(map, i);
		list_node_clear(list);
	}
}

void hash_map_print(HASH_MAP_T map) {
	for(unsigned int i = 0; i < HASH_MAP_SIZE; i++) {
		LIST_NODE_T * list = __hash_map_get_index_list(&map, i);

		NODE_T * ptr = list->head;
		while(ptr != NULL) {
			printf("(%u) [%s] = %s\n", i, ptr->key, ptr->value);
			ptr = ptr->next;
		}

	}
}

HASH_MAP_KEYS_T hash_map_get_keys(HASH_MAP_T map) {
	HASH_MAP_KEYS_T map_keys;
	map_keys.size = map.size;

	// The last index position is NULL, more easy to implements 'hash_map_free_keys'
	map_keys.keys = calloc((map_keys.size + 1), sizeof(char *));

	unsigned int count_keys = 0;
	for(unsigned int i = 0; i < HASH_MAP_SIZE; i++) {
		LIST_NODE_T * list = __hash_map_get_index_list(&map, i);

		NODE_T * ptr = list->head;
		while(ptr != NULL) {
			const char * key = ptr->key;

			unsigned int key_len = strlen(key);
			map_keys.keys[count_keys] = calloc(key_len + 1, sizeof(char));
			strncpy(map_keys.keys[count_keys], key, key_len);
			count_keys++;

			ptr = ptr->next;
		}
	}

	return map_keys;
}

void hash_map_free_keys(HASH_MAP_KEYS_T * map_keys) {
	unsigned int c = 0;
	while(map_keys->keys[c] != NULL) {
		free(map_keys->keys[c++]);
	}
	free(map_keys->keys);
	map_keys->size = 0;
}
