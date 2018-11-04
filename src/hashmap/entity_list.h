
#ifndef ENTITY_LIST_H
#define	ENTITY_LIST_H

#include "entity.h"

typedef struct{
    ENTITY* head;
    ENTITY* tail;
}ENTITY_LIST;

void entity_list_new(ENTITY_LIST*list);
void entity_list_add_head(ENTITY_LIST*list , ENTITY entity);
void entity_list_add_tail(ENTITY_LIST*list , ENTITY entity);
void entity_list_get(ENTITY_LIST*list , char* key);
void entity_list_del(ENTITY_LIST*list , char* key);

#endif
