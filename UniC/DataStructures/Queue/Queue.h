//
// Created by andre on 5/5/2023.
//

#ifndef QUEUE_H
# define QUEUE_H

# include "../LinkedList/LinkedList.h"

typedef LinkedList	Queue;

Queue				Queue_Init(Generic info);

void				Queue_Add(Queue *queue, Generic info);

Queue				Queue_poll(Queue *queue);

void				Queue_DeallocElement(Queue queue, Deallocator dealloc);

void				Queue_Dealloc(Queue *queue, Deallocator dealloc);

#endif // QUEUE_H
