
#include <stdlib.h>
#include "queue.h"
#include <pthread.h>

/* Remember to initilize the queue before using it */
void initialize_queue(struct pqueue_t * q) {
	q->head = q->tail = NULL;
	pthread_mutex_init(&q->lock, NULL);
}

/* Return non-zero if the queue is empty */
int empty(struct pqueue_t * q) {
	return (q->head == NULL);
}

/* Get PCB of a process from the queue (q).
 * Return NULL if the queue is empty */
struct pcb_t * de_queue(struct pqueue_t * q) {
	struct pcb_t * proc = NULL;
	// TODO: return q->head->data and remember to update the queue's head
	// and tail if necessary. Remember to use 'lock' to avoid race
	// condition

	// YOUR CODE HERE
	if (q->head != NULL)
	{
		pthread_mutex_lock(&q->lock);
		proc = q->head->data;
		if (q->head != q->tail) q->head = q->head->next;
		else {
			q->head = NULL;
			q->tail = NULL;
		}
		pthread_mutex_unlock(&q->lock);
	}

	return proc;
}

/* Put PCB of a process to the queue. */
void en_queue(struct pqueue_t * q, struct pcb_t * proc) {
	// TODO: Update q->tail.
	// Remember to use 'lock' to avoid race condition

	// YOUR CODE HERE

	struct qitem_t * block = (struct qitem_t *)malloc(sizeof(struct qitem_t));
	block->data = proc;
	block->next = NULL;


	pthread_mutex_lock(&q->lock);
	if (q->head == NULL)
	{
		q->head = block;
		q->tail = block;
	}
	else{
		q->tail->next = block;
		q->tail = block;
	}

	pthread_mutex_unlock(&q->lock);
}


