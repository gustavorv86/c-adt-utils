/* 
 * File:   hashmap.h
 * Author: gustavo
 *
 * Created on 5 de febrero de 2015, 9:15
 */

#ifndef HASHMAP_H
#define	HASHMAP_H

#include "entity_list.h"

#define ASCII_0 48
#define ASCII_9 57
#define ASCII_A 65
#define ASCII_Z 90
#define ASCII_a 97
#define ASCII_z 122

// 0-9 (10) , A-Z (26)
#define SIZE 36


typedef ENTITY_LIST HASHMAP[SIZE];

void hash_map_new(HASHMAP map);
void hash_map_add(HASHMAP map , char * key , char * value);

#endif
