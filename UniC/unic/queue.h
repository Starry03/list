//
// Created by andre on 5/5/2023.
//

#ifndef QUEUE_H
# define QUEUE_H

# include "unic/linkedlist.h"

typedef t_linkedlist	t_queue;

t_queue					queue_init(t_generic info);
void					queue_add(t_queue *queue, t_generic info);
t_queue					queue_poll(t_queue *queue);
void					queue_deallocelement(t_queue queue,
							t_deallocator dealloc);
void					queue_dealloc(t_queue *queue, t_deallocator dealloc);

#endif // QUEUE_H
