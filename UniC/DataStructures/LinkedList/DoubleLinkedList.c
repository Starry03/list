#include "DoubleLinkedList.h"
#include <stdlib.h>

DoubleLinkedList	DoubleLinkedList_Init(Generic info)
{
	return (DoubleNode_Init(info));
}

DoubleLinkedList	DoubleLinkedList_Insert(DoubleLinkedList *list,
		Generic info, size_t index)
{
	DoubleLinkedList	temp;
	DoubleLinkedList	node;
	DoubleLinkedList	prev;

	if (!list || !*list || !info)
		return (DOUBLELINKEDLIST_EMPTY);
	if (index == START)
		return (DoubleLinkedList_Push(list, info));
	if (index == LAST)
		return (DoubleLinkedList_Append(*list, info));
	temp = DoubleLinkedList_GetNth(*list, index);
	node = DoubleNode_Init(info);
	if (temp)
		temp->prev = node;
	node->next = temp;
	prev = node->prev;
	node->prev = prev;
	if (prev)
		prev->next = node;
	return (node);
}

DoubleLinkedList	DoubleLinkedList_Append(DoubleLinkedList list, Generic info)
{
	DoubleLinkedList	last;

	last = DoubleLinkedList_GetLast(list);
	last->next = DoubleLinkedList_Init(info);
	last->next->prev = last;
	return (last->next);
}

DoubleLinkedList	DoubleLinkedList_Push(DoubleLinkedList *list, Generic info)
{
	DoubleLinkedList	node;

	node = DoubleLinkedList_Init(info);
	node->next = *list;
	*list = node;
	return (node);
}

void	DoubleLinkedList_Remove(DoubleLinkedList node, Deallocator dealloc)
{
	DoubleLinkedList	next;
	DoubleLinkedList	prev;

	if (!node)
		return ;
	next = (node)->next;
	prev = (node)->prev;
	if (prev)
		prev->next = next;
	if (next)
		next->prev = prev;
	if (dealloc)
		dealloc(node->info);
	free(node);
}

void	DoubleLinkedList_RemoveByValue(DoubleLinkedList list, Comparator cmp,
		Generic info, Deallocator dealloc)
{
	DoubleLinkedList	node;

	node = DoubleLinkedList_Search(list, cmp, info);
	DoubleLinkedList_Remove(node, dealloc);
}

void	DoubleLinkedList_RemoveByIndex(DoubleLinkedList list, size_t index,
		Deallocator dealloc)
{
	DoubleLinkedList_Remove(DoubleLinkedList_GetNth(list, index), dealloc);
}

DoubleLinkedList	DoubleLinkedList_Search(DoubleLinkedList list,
		Comparator cmp, Generic info)
{
	while (list && cmp(DoubleLinkedList_GetInfo(list), info))
		list = DoubleLinkedList_GetNext(list);
	return (list);
}

DoubleLinkedList	DoubleLinkedList_GetNth(DoubleLinkedList list, size_t index)
{
	size_t	i;

	i = 0;
	while (list && i < index)
	{
		list = DoubleLinkedList_GetNext(list);
		i++;
	}
	return (list);
}

DoubleLinkedList	DoubleLinkedList_GetFirst(DoubleLinkedList list)
{
	if (!list)
		return (DOUBLELINKEDLIST_EMPTY);
	return (list);
}
DoubleLinkedList	DoubleLinkedList_GetLast(DoubleLinkedList list)
{
	if (!list)
		return (DOUBLELINKEDLIST_EMPTY);
	while (list->next)
		list = list->next;
	return (list);
}

DoubleLinkedList	DoubleLinkedList_GetNext(DoubleLinkedList list)
{
	if (!list)
		return (DOUBLELINKEDLIST_EMPTY);
	return (list->next);
}

DoubleLinkedList	DoubleLinkedList_GetPrev(DoubleLinkedList list)
{
	if (!list)
		return (DOUBLELINKEDLIST_EMPTY);
	return (list->prev);
}

DoubleLinkedList	DoubleLinkedList_GetInfo(DoubleLinkedList list)
{
	if (!list)
		return (DOUBLELINKEDLIST_EMPTY);
	return (list->next);
}

size_t	DoubleLinkedList_GetLength(DoubleLinkedList list)
{
	size_t	length;

	length = 0;
	while (list)
	{
		list = list->next;
		length++;
	}
	return (length);
}

void	DoubleLinkedList_Dealloc(DoubleLinkedList list, Deallocator dealloc)
{
	DoubleLinkedList	next;

	while (list)
	{
		next = list->next;
		if (dealloc)
			dealloc(list->info);
		free(list);
		list = next;
	}
}
