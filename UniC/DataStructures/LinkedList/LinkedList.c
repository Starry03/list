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
	if (!node)
		return (LINKEDLIST_EMPTY);
	if (!*list)
	{
		*list = node;
		return (node);
	}
	last = LinkedList_GetLast(*list);
	last->next = node;
	return (node);
}

void	LinkedList_Remove(LinkedList *node, void (*dealloc)(Generic))
{
	LinkedList	temp;

	if (!node || !*node)
		return ;
	temp = *node;
	(*node) = (*node)->next;
	if (dealloc)
		dealloc(temp->info);
	free(temp);
}

void	LinkedList_RemoveByValue(LinkedList *list, Generic value,
		void (*dealloc)(Generic), int (*cmp)(Generic, Generic))
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

void	LinkedList_Dealloc(LinkedList head, void (*dealloc)(Generic))
{
	LinkedList	next;

	if (!head)
		return ;
	while (head != NULL)
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
	c_node = LinkedList_GetNth(*list, index);
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
