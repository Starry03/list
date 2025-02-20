#include "unic/doublelinkedlist.h"
#include <stdlib.h>

t_double_linkedlist	double_linkedlist_init(t_generic info)
{
	return (doublenode_init(info));
}

t_double_linkedlist	double_linkedlist_insert(t_double_linkedlist *list,
		t_generic info, size_t index)
{
	t_double_linkedlist	temp;
	t_double_linkedlist	node;
	t_double_linkedlist	prev;

	if (!list || !*list || !info)
		return (DOUBLELINKEDLIST_EMPTY);
	if (index == START)
		return (double_linkedlist_push(list, info));
	if (index == LAST)
		return (double_linkedlist_append(*list, info));
	temp = double_linkedlist_getnth(*list, index);
	node = doublenode_init(info);
	if (temp)
		temp->prev = node;
	node->next = temp;
	prev = node->prev;
	node->prev = prev;
	if (prev)
		prev->next = node;
	return (node);
}

t_double_linkedlist	double_linkedlist_append(t_double_linkedlist list,
		t_generic info)
{
	t_double_linkedlist	last;

	last = double_linkedlist_getlast(list);
	last->next = double_linkedlist_init(info);
	last->next->prev = last;
	return (last->next);
}

t_double_linkedlist	double_linkedlist_push(t_double_linkedlist *list,
		t_generic info)
{
	t_double_linkedlist	node;

	node = double_linkedlist_init(info);
	node->next = *list;
	*list = node;
	return (node);
}

void	double_linkedlist_remove(t_double_linkedlist node,
		t_deallocator dealloc)
{
	t_double_linkedlist	next;
	t_double_linkedlist	prev;

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

void	double_linkedlist_removebyvalue(t_double_linkedlist list,
		t_comparator cmp, t_generic info, t_deallocator dealloc)
{
	t_double_linkedlist	node;

	node = double_linkedlist_search(list, cmp, info);
	double_linkedlist_remove(node, dealloc);
}

void	double_linkedlist_removebyindex(t_double_linkedlist list, size_t index,
		t_deallocator dealloc)
{
	double_linkedlist_remove(double_linkedlist_getnth(list, index), dealloc);
}

t_double_linkedlist	double_linkedlist_search(t_double_linkedlist list,
		t_comparator cmp, t_generic info)
{
	while (list && cmp(double_linkedlist_getinfo(list), info))
		list = double_linkedlist_getNext(list);
	return (list);
}

t_double_linkedlist	double_linkedlist_getnth(t_double_linkedlist list,
		size_t index)
{
	size_t	i;

	i = 0;
	while (list && i < index)
	{
		list = double_linkedlist_getNext(list);
		i++;
	}
	return (list);
}

t_double_linkedlist	double_linkedlist_getfirst(t_double_linkedlist list)
{
	if (!list)
		return (DOUBLELINKEDLIST_EMPTY);
	return (list);
}
t_double_linkedlist	double_linkedlist_getlast(t_double_linkedlist list)
{
	if (!list)
		return (DOUBLELINKEDLIST_EMPTY);
	while (list->next)
		list = list->next;
	return (list);
}

t_double_linkedlist	double_linkedlist_getNext(t_double_linkedlist list)
{
	if (!list)
		return (DOUBLELINKEDLIST_EMPTY);
	return (list->next);
}

t_double_linkedlist	double_linkedlist_getprev(t_double_linkedlist list)
{
	if (!list)
		return (DOUBLELINKEDLIST_EMPTY);
	return (list->prev);
}

t_double_linkedlist	double_linkedlist_getinfo(t_double_linkedlist list)
{
	if (!list)
		return (DOUBLELINKEDLIST_EMPTY);
	return (list->next);
}

size_t	double_linkedlist_getlength(t_double_linkedlist list)
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

void	double_linkedlist_dealloc(t_double_linkedlist list,
		t_deallocator dealloc)
{
	t_double_linkedlist	next;

	while (list)
	{
		next = list->next;
		if (dealloc)
			dealloc(list->info);
		free(list);
		list = next;
	}
}
