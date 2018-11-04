
#include "hashmap.h"

void hash_map_new(HASHMAP map){
	int i;
	
	for(i=0 ; i<SIZE ; i++){
		entity_list_new(map[i]);
	}
}

void hash_map_add(HASHMAP map , char* key , char* value){
	char c;
	
	c = key[0];
	
	
	
}
