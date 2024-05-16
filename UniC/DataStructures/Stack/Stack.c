#include "Stack.h"

#define STACK_EMPTY (Stack)0

inline Stack	stack_init(Generic value)
{
	return (Stack)(LinkedList_Init(value));
}

/**
 * @brief adds a value on top of the stack
 *
 * @param stack
 * @param value
 */
inline void	stack_add(Stack stack, Generic value)
{
	LinkedList_Push((LinkedList *)&stack, value);
}

/**
 * @brief removes the top value from the stack
 *
 * @param stack
 * @param dealloc
 * @return Generic
 */
Generic	stack_poll(Stack *stack, void (*dealloc)(Generic))
{
	Generic	out;

	if (!stack)
		return (GENERIC_NULL);
	out = LinkedList_GetInfo(*stack);
	LinkedList_Remove(stack, dealloc);
	return (out);
}

inline void	stack_free(Stack *stack, void (*dealloc)(Generic))
{
	LinkedList_Dealloc(*stack, dealloc);
}