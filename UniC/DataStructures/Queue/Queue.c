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

inline void	Queue_Add(Queue queue, Generic info)
{
	LinkedList_Append(&queue, info);
}

Generic	Queue_poll(Queue *queue, void (*dealloc)(Generic))
{
	Generic	out;

	if (!queue || !*queue)
		return (GENERIC_NULL);
	out = (*queue)->info;
	LinkedList_Remove(queue, dealloc);
	return (out);
}

inline void	Queue_Dealloc(Queue *queue, void (*dealloc)(Generic))
{
	LinkedList_Dealloc(*queue, dealloc);
}
