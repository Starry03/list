#ifndef STACK_H
# define STACK_H

# include "unic/linkedlist.h"

typedef t_linkedlist	t_stack;

t_stack					stack_init(t_generic value);
void					stack_add(t_stack stack, t_generic value);
t_generic				stack_poll(t_stack *stack);
void					stack_dealloc_element(t_stack stack,
							t_deallocator dealloc);
void					stack_free(t_stack *stack, void (*dealloc)(t_generic));

#endif