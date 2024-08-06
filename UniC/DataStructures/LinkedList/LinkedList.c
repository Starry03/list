//
// Created by andre on 8/8/2023.
//

#include "LinkedList.h"
#include <stdlib.h>

static inline LinkedList	LinkedList_Alloc(void)
{
	return (LinkedList)malloc(sizeof(Node_));
}

LinkedList	LinkedList_Init(Generic value)
{
	LinkedList	list;

	list = LinkedList_Alloc();
	if (!list)
		return (LINKEDLIST_EMPTY);
	list->info = value;
	list->next = LINKEDLIST_EMPTY;
	return (list);
}

void	LinkedList_Push(LinkedList *list, Generic object)
{
	LinkedList	node;

	node = LinkedList_Init(object);
	node->next = *list;
	*list = node;
}

LinkedList	LinkedList_Append(LinkedList *list, Generic value)
{
	LinkedList	node;
	LinkedList	last;

	if (!list)
		return (LINKEDLIST_EMPTY);
	node = LinkedList_Init(value);
	last = LinkedList_GetLast(*list);
	if (!last)
		*list = node;
	else
		last->next = node;
	return (node);
}

void	LinkedList_Remove(LinkedList *node, Deallocator dealloc)
{
	LinkedList	tmp;

	if (!node || !*node)
		return ;
	tmp = *node;
	*node = (*node)->next;
	if (dealloc)
		dealloc(tmp->info);
	free(tmp);
}

void	LinkedList_RemoveByValue(LinkedList *list, Generic value,
		Deallocator dealloc, int (*cmp)(Generic, Generic))
{
	if (!list || !*list || !value)
		return ;
	while (*list && cmp(LinkedList_GetInfo(*list), value) != 0)
		list = &((*list)->next);
	LinkedList_Remove(list, dealloc);
}

LinkedList	LinkedList_GetNode(LinkedList list, Generic value)
{
	if (!list || !value)
		return (LINKEDLIST_EMPTY);
	while (LinkedList_GetInfo(list) != value)
		list = LinkedList_GetNext(list);
	return (list);
}

LinkedList	LinkedList_GetNext(LinkedList list)
{
	if (!list)
		return (LINKEDLIST_EMPTY);
	return (list->next);
}

Generic	LinkedList_GetInfo(LinkedList list)
{
	if (!list)
		return (GENERIC_NULL);
	return (list->info);
}

void	LinkedList_Dealloc(LinkedList head, Deallocator dealloc)
{
	LinkedList	next;

	if (!head)
		return ;
	while (head)
	{
		next = head->next;
		if (dealloc)
			dealloc(head->info);
		free(head);
		head = next;
	}
}

LinkedList	LinkedList_GetNth(LinkedList list, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		list = LinkedList_GetNext(list);
		if (!list)
			return (LINKEDLIST_EMPTY);
		i++;
	}
	return (list);
}

void	LinkedList_RemoveNth(LinkedList *list, size_t n, Deallocator dealloc)
{
	if (!list || !*list)
		return ;
	while (n)
	{
		list = &((*list)->next);
		n--;
	}
	LinkedList_Remove(list, dealloc);
}

size_t	LinkedList_Size(LinkedList list)
{
	size_t	size;

	size = 0;
	while (list)
	{
		size++;
		list = LinkedList_GetNext(list);
	}
	return (size);
}

LinkedList	LinkedList_Insert(LinkedList *list, Generic value, size_t index)
{
	LinkedList	c_node;
	LinkedList	n_node;

	if (!list || !*list)
		return (LINKEDLIST_EMPTY);
	if (index == START)
	{
		LinkedList_Push(list, value);
		return (*list);
	}
	if (index == LAST)
		return (LinkedList_Append(list, value));
	c_node = LinkedList_GetNth(*list, index - 1);
	if (!c_node)
		return (LINKEDLIST_EMPTY);
	n_node = LinkedList_Init(value);
	n_node->next = c_node->next;
	c_node->next = n_node;
	return (n_node);
}

LinkedList	LinkedList_GetLast(LinkedList list)
{
	if (!list)
		return (LINKEDLIST_EMPTY);
	while (list->next)
		list = list->next;
	return (list);
}
