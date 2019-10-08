
#include "linked_map.h"

void linked_map_new(LINKED_MAP_T * lmap) {
	lmap->head = NULL;
	lmap->tail = NULL;
	lmap->size = 0;
}

NODE_T * __linked_map_new_node(const char * key, const char * value) {
	NODE_T * new_node = calloc(1, sizeof(NODE_T));

	unsigned int key_size = strlen(key);
	unsigned int value_size = strlen(value);

	new_node->key   = calloc(key_size + 1, sizeof(char));
	new_node->value = calloc(value_size + 1, sizeof(char));
	new_node->next  = NULL;

	strncpy(new_node->key, key, key_size);
	strncpy(new_node->value, value, value_size);

	return new_node;
}

void __linked_map_free_node(NODE_T * node) {
	free(node->key);
	free(node->value);
	free(node);
}

NODE_T * __linked_map_get_node(LINKED_MAP_T lmap, const char * key) {
	NODE_T * ptr = lmap.head;
	while(ptr != NULL) {

		if(strcmp(ptr->key, key) == 0) {
			return ptr;
		}
		ptr = ptr->next;
	}

	return NULL;
}

bool linked_map_is_empty(LINKED_MAP_T lmap) {
	return lmap.size == 0;
}

bool linked_map_put(LINKED_MAP_T * lmap, const char * key, const char * value) {
	NODE_T * node = __linked_map_get_node(*lmap, key);
	if(node != NULL) {
		// The key is into the lmap
		unsigned int new_length_value = strlen(value);
		if(new_length_value > strlen(node->value)) {
			// Reallocate memory
			free(node->value);
			node->value = calloc(new_length_value + 1, sizeof(char));
		}
		strncpy(node->value, value, new_length_value);
		return false;
	}

	// The key is not into the lmap, create new node
	node = __linked_map_new_node(key, value);

	if(linked_map_is_empty(*lmap)) {
		lmap->head = node;
		lmap->tail = node;
	} else {
		// Add to the tail
		lmap->tail->next = node;
		lmap->tail = node;
	}
	lmap->size++;
	return true;
}

const char * linked_map_get(LINKED_MAP_T lmap, const char * key) {
	NODE_T * ptr = lmap.head;
	while(ptr != NULL) {

		if(strcmp(ptr->key, key) == 0) {
			return ptr->value;
		}
		ptr = ptr->next;
	}

	return NULL;
}

bool linked_map_remove(LINKED_MAP_T * lmap, const char * key) {
	NODE_T * ptr_del;
	if(strcmp(lmap->head->key, key) == 0) {
		// Is the first node
		ptr_del = lmap->head;
		lmap->head = lmap->head->next;
		__linked_map_free_node(ptr_del);
		lmap->size--;
		return true;
	}

	NODE_T * ptr = lmap->head;
	while(ptr->next != NULL) {

		if(strcmp(ptr->next->key, key) == 0) {
			// Node found. Delete 'ptr->next'
			ptr_del = ptr->next;
			// ... -> 'ptr' -> 'ptr_del' -> 'ptr_del->next' -> ...
			ptr->next = ptr_del->next;
			/**
			 * Jumping 'ptr_del'...
			 *              _____________
			 *              |           |
			 * ... -> 'ptr' - 'ptr_del' -> 'ptr_del->next' -> ...
			 *
			 */
			__linked_map_free_node(ptr_del);
			lmap->size--;
			return true;
		}

		ptr = ptr->next;
	}

	return false;
}

void linked_map_clear(LINKED_MAP_T * lmap) {
	NODE_T * ptr_del = NULL;
	while(lmap->head != NULL) {
		ptr_del = lmap->head;
		lmap->head = lmap->head->next;
		__linked_map_free_node(ptr_del);
	}
	lmap->head = NULL;
	lmap->tail = NULL;
	lmap->size = 0;
}

void linked_map_destroy(LINKED_MAP_T * lmap) {
	linked_map_clear(lmap);
}

void linked_map_print(LINKED_MAP_T lmap) {
	NODE_T * ptr = lmap.head;
	while(ptr != NULL) {
		printf("%s: %s\n", ptr->key, ptr->value);
		ptr = ptr->next;
	}
}

KEYSET_T linked_map_keyset(LINKED_MAP_T lmap) {
	KEYSET_T keyset;

	keyset.size = lmap.size;
	
	// The last index position is NULL, more easy to implements 'linked_map_keyset_clear'
	keyset.keys = calloc(keyset.size + 1, sizeof(char *));
	
	unsigned int count = 0;
	NODE_T * ptr = lmap.head;
	while(ptr != NULL) {
		unsigned int key_size = strlen(ptr->key) + 1;
		keyset.keys[count] = calloc(key_size, sizeof(char));
		strncpy(keyset.keys[count], ptr->key, key_size);
		count++;
		ptr = ptr->next;
	}

	return keyset;
}

void linked_map_keyset_destroy(KEYSET_T * keyset) {
	unsigned int c = 0;
	while(keyset->keys[c] != NULL) {
		free(keyset->keys[c++]);
	}
	free(keyset->keys);
	keyset->size = 0;
}
