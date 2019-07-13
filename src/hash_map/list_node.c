
#include "list_node.h"

void list_node_new(LIST_NODE_T * list) {
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}

bool list_node_is_empty(LIST_NODE_T * list) {
	return list->size == 0;
}

NODE_T * __list_node_new_node(const char * key, const char * value) {
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

void __list_node_free_node(NODE_T * node) {
	free(node->key);
	free(node->value);
	free(node);
}

const char * list_node_get_value(LIST_NODE_T * list, const char * key) {
	NODE_T * ptr = list->head;
	while(ptr != NULL) {

		if(strcmp(ptr->key, key) == 0) {
			return ptr->value;
		}
		ptr = ptr->next;
	}

	return NULL;
}

NODE_T * __list_node_get_node(LIST_NODE_T * list, const char * key) {
	NODE_T * ptr = list->head;
	while(ptr != NULL) {

		if(strcmp(ptr->key, key) == 0) {
			return ptr;
		}
		ptr = ptr->next;
	}

	return NULL;
}

bool list_node_add(LIST_NODE_T * list, const char * key, const char * value) {
	NODE_T * node = __list_node_get_node(list, key);
	if(node != NULL) {
		// The key is into the list
		unsigned int new_length_value = strlen(value);
		if(new_length_value > strlen(node->value)) {
			// Reallocate memory
			free(node->value);
			node->value = calloc(new_length_value + 1, sizeof(char));
		}
		strncpy(node->value, value, new_length_value);
		return false;
	}

	// The key is not into the list, create new node
	node = __list_node_new_node(key, value);

	if(list_node_is_empty(list)) {
		list->head = node;
		list->tail = node;
	} else {
		// Add to the tail
		list->tail->next = node;
		list->tail = node;
	}
	list->size++;
	return true;
}

bool list_node_remove(LIST_NODE_T * list, const char * key) {
	NODE_T * ptr_del;
	if(strcmp(list->head->key, key) == 0) {
		// Is the first node
		ptr_del = list->head;
		list->head = list->head->next;
		__list_node_free_node(ptr_del);
		list->size--;
		return true;
	}

	NODE_T * ptr = list->head;
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
			__list_node_free_node(ptr_del);
			list->size--;
			return true;
		}

		ptr = ptr->next;
	}

	return false;
}

void list_node_clear(LIST_NODE_T * list) {
	NODE_T * ptr_del = NULL;
	while(list->head != NULL) {
		ptr_del = list->head;
		list->head = list->head->next;
		__list_node_free_node(ptr_del);
	}
}
