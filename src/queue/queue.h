/*
    File: queue.h
*/

#ifndef QUEUE_H
#define QUEUE_H

#include <math.h>
#include <stdbool.h>

// definimos el tipo que almacena nuestra cola
#define DATATYPE         float
#define DATATYPE_ERR     NAN
#define DATATYPE_PRINTF  "%f"

// Definimos un nodo de la cola 
typedef struct __queue_node {
    DATATYPE data;
    struct __queue_node * ptr_next;
} QUEUE_NODE;

// Definimos la cola como una estructura con los siguientes campos:
//  - head: puntero al primer elemento de la cola
//  - tail: puntero al ultimo elemento de la cola
//  - size: numero de elementos
typedef struct {
    QUEUE_NODE * head;
    QUEUE_NODE * tail;
    int size;
} QUEUE;

// En una cola se insertan los elementos por un extremo y se extraen por otro
// extremo. Para optimizar las operaciones, insertaremos los elementos por el
// 'tail', y los extraeremos por el 'head'.

// Funciones para operar con una cola
QUEUE    queue_new();
int      queue_size(QUEUE my_queue);
bool     queue_empty(QUEUE my_queue);
void     queue_enqueue(QUEUE *my_queue, DATATYPE data);
DATATYPE queue_dequeue(QUEUE *my_queue);
void     queue_clear(QUEUE *my_queue);
void     queue_printf(QUEUE my_queue);

#endif 
