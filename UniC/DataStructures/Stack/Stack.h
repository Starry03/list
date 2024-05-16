#ifndef STACK_H
# define STACK_H

# include "../LinkedList/LinkedList.h"

/*
	Stack is a FIFO data structure that allows for the addition and removal of elements
*/

typedef LinkedList	Stack;

Stack				stack_init(Generic value);
void				stack_add(Stack stack, Generic value);
Generic				stack_poll(Stack *stack, void (*dealloc)(Generic));
void				stack_free(Stack *stack, void (*dealloc)(Generic));

#endif