#include "unic/stack.h"
#include <stdlib.h>

#define STACK_EMPTY (t_stack)0

inline t_stack	stack_init(t_generic value)
{
	return (t_stack)(linkedlist_init(value));
}

/**
 * @brief adds a value on top of the stack
 *
 * @param stack
 * @param value
 */
inline void	stack_add(t_stack stack, t_generic value)
{
	linkedlist_push((t_linkedlist *)&stack, value);
}

/**
 * @brief removes the top value from the stack
 *
 * @param stack
 * @param dealloc
 * @note does not deallocate the value, call stack_dealloc_element
 * @return Generic
 */
t_generic	stack_poll(t_stack *stack)
{
	t_generic	out;

	if (!stack)
		return (GENERIC_NULL);
	out = linkedlist_getinfo(*stack);
	*stack = linkedlist_getnext(*stack);
	return (out);
}

/**
 * @brief deallocates the stack element
 *
 * @param stack
 * @param dealloc
 */
void	stack_dealloc_element(t_stack stack, t_deallocator dealloc)
{
	if (!stack)
		return ;
	if (dealloc)
		dealloc(stack->info);
	free(stack);
}

inline void	stack_free(t_stack *stack, void (*dealloc)(t_generic))
{
	linkedlist_dealloc(*stack, dealloc);
}
