#ifndef STACK_H
# define STACK_H

# include "../LinkedList/LinkedList.h"

/*
	Stack is a FIFO data structure that allows for the addition and removal of elements
*/

typedef LinkedList	Stack;

Stack				Stack_Init(Generic value);
void				Stack_Add(Stack stack, Generic value);
Generic				Stack_Poll(Stack *stack);
void 				Stack_Dealloc_Element(Stack stack, Deallocator dealloc);
void				Stack_Free(Stack *stack, void (*dealloc)(Generic));

#endif