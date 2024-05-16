//
// Created by andre on 5/5/2023.
//

#ifndef QUEUE_H
#define QUEUE_H

#include "../LinkedList/LinkedList.h"

typedef LinkedList Queue;

Queue Queue_Init(Generic info);

void Queue_Add(Queue queue, Generic info);

Generic	Queue_poll(Queue *queue, void (*dealloc)(Generic));

void Queue_Dealloc(Queue *queue, void (*dealloc)(Generic));

#endif //QUEUE_H
