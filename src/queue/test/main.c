/*
	File: queue_main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <queue.h>

int main() {
	QUEUE queue;
	DATATYPE data;
	
	queue = queue_new();
	queue_enqueue(&queue, 10);
	queue_enqueue(&queue, 20);
	queue_enqueue(&queue, 30);
	queue_enqueue(&queue, 40);
	
	queue_print(queue);
	
	if(queue_dequeue(&queue, &data)) {
		printf("dequeue "DATATYPE_PRINTF"\n",  data);
	} else {
		printf("ERROR: queue is empty.\n");
	}
	
	if(queue_dequeue(&queue, &data)) {
		printf("dequeue "DATATYPE_PRINTF"\n",  data);
	} else {
		printf("ERROR: queue is empty.\n");
	}
	
	queue_print(queue);
	
	queue_destroy(&queue);
	
	return EXIT_SUCCESS;
}
