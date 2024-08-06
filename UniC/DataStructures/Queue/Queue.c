//
// Created by andre on 5/5/2023.
//

#include "Queue.h"
#include <stdlib.h>

#define QUEUE_EMPTY (Queue)0

inline Queue	Queue_Init(Generic info)
{
	return (Queue)LinkedList_Init(info);
}

inline void	Queue_Add(Queue *queue, Generic info)
{
	LinkedList_Append(queue, info);
}

/**
 * @brief Poll the first element of the queue
 * @param queue: the queue
 * @note element is not deallocated, call Queue_DeallocElement
 * @return the first element of the queue
 */
Queue	Queue_poll(Queue *queue)
{
	Queue	out;

	if (!queue || !*queue)
		return (GENERIC_NULL);
	out = *queue;
	*queue = (*queue)->next;
	return (out);
}

/**
 * @brief Deallocate the element of the queue
 * @param queue: the queue
 * @param dealloc: the deallocator function
 * @note use only if poll is called (dealloc poll returned value)
 */
void	Queue_DeallocElement(Queue queue, Deallocator dealloc)
{
	if (!queue)
		return ;
	if (dealloc)
		dealloc(queue->info);
	free(queue);
}

inline void	Queue_Dealloc(Queue *queue, Deallocator dealloc)
{
	LinkedList_Dealloc(*queue, dealloc);
}
