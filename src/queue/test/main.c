/*
	File: queue_main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <queue.h>

int main() {
	QUEUE queue;
	
	queue = queue_new();
	queue_enqueue(&queue, 10);
	queue_enqueue(&queue, 20);
	queue_enqueue(&queue, 30);
	queue_enqueue(&queue, 40);
	
	queue_printf(queue);
	
	printf("dequeue "DATATYPE_PRINTF"\n",  queue_dequeue(&queue));
	printf("dequeue "DATATYPE_PRINTF"\n\n",  queue_dequeue(&queue));
	
	queue_printf(queue);
	
	return EXIT_SUCCESS;
}
