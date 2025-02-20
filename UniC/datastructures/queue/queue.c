//
// Created by andre on 5/5/2023.
//

#include "unic/queue.h"
#include <stdlib.h>

#define QUEUE_EMPTY (Queue)0

inline t_queue	queue_init(t_generic info)
{
	return ((t_queue)linkedlist_init(info));
}

inline void	queue_add(t_queue *queue, t_generic info)
{
	linkedlist_append(queue, info);
}

/**
 * @brief Poll the first element of the queue
 * @param queue: the queue
 * @note element is not deallocated, call queue_deallocelement
 * @return the first element of the queue
 */
t_queue	queue_poll(t_queue *queue)
{
	t_queue	out;

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
void	queue_deallocelement(t_queue queue, t_deallocator dealloc)
{
	if (!queue)
		return ;
	if (dealloc)
		dealloc(queue->info);
	free(queue);
}

inline void	queue_dealloc(t_queue *queue, t_deallocator dealloc)
{
	linkedlist_dealloc(*queue, dealloc);
}
