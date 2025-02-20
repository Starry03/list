//
// Created by andre on 8/8/2023.
//

#include "unic/linkedlist.h"
#include <stdlib.h>

static inline t_linkedlist	linkedlist_alloc(void)
{
	return (t_linkedlist)malloc(sizeof(t_node_));
}

t_linkedlist	linkedlist_init(t_generic value)
{
	t_linkedlist	list;

	list = linkedlist_alloc();
	if (!list)
		return (LINKEDLIST_EMPTY);
	list->info = value;
	list->next = LINKEDLIST_EMPTY;
	return (list);
}

void	linkedlist_push(t_linkedlist *list, t_generic object)
{
	t_linkedlist	node;

	node = linkedlist_init(object);
	node->next = *list;
	*list = node;
}

t_linkedlist	linkedlist_append(t_linkedlist *list, t_generic value)
{
	t_linkedlist	node;
	t_linkedlist	last;

	if (!list)
		return (LINKEDLIST_EMPTY);
	node = linkedlist_init(value);
	last = linkedlist_getlast(*list);
	if (!last)
		*list = node;
	else
		last->next = node;
	return (node);
}

void	linkedlist_remove(t_linkedlist *node, t_deallocator dealloc)
{
	t_linkedlist	tmp;

	if (!node || !*node)
		return ;
	tmp = *node;
	*node = (*node)->next;
	if (dealloc)
		dealloc(tmp->info);
	free(tmp);
}

void	linkedlist_removebyvalue(t_linkedlist *list, t_generic value,
		t_deallocator dealloc, int (*cmp)(t_generic, t_generic))
{
	if (!list || !*list || !value)
		return ;
	while (*list && cmp(linkedlist_getinfo(*list), value) != 0)
		list = &((*list)->next);
	linkedlist_remove(list, dealloc);
}

t_linkedlist	linkedlist_getnode(t_linkedlist list, t_generic value)
{
	if (!list || !value)
		return (LINKEDLIST_EMPTY);
	while (linkedlist_getinfo(list) != value)
		list = linkedlist_getnext(list);
	return (list);
}

t_linkedlist	linkedlist_getnext(t_linkedlist list)
{
	if (!list)
		return (LINKEDLIST_EMPTY);
	return (list->next);
}

t_generic	linkedlist_getinfo(t_linkedlist list)
{
	if (!list)
		return (GENERIC_NULL);
	return (list->info);
}

void	linkedlist_dealloc(t_linkedlist head, t_deallocator dealloc)
{
	t_linkedlist	next;

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

t_linkedlist	linkedlist_getnth(t_linkedlist list, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		list = linkedlist_getnext(list);
		if (!list)
			return (LINKEDLIST_EMPTY);
		i++;
	}
	return (list);
}

void	linkedlist_removenth(t_linkedlist *list, size_t n,
		t_deallocator dealloc)
{
	if (!list || !*list)
		return ;
	while (n)
	{
		list = &((*list)->next);
		n--;
	}
	linkedlist_remove(list, dealloc);
}

size_t	linkedlist_size(t_linkedlist list)
{
	size_t	size;

	size = 0;
	while (list)
	{
		size++;
		list = linkedlist_getnext(list);
	}
	return (size);
}

t_linkedlist	linkedlist_insert(t_linkedlist *list, t_generic value,
		size_t index)
{
	t_linkedlist	c_node;
	t_linkedlist	n_node;

	if (!list || !*list)
		return (LINKEDLIST_EMPTY);
	if (index == START)
	{
		linkedlist_push(list, value);
		return (*list);
	}
	if (index == LAST)
		return (linkedlist_append(list, value));
	c_node = linkedlist_getnth(*list, index - 1);
	if (!c_node)
		return (LINKEDLIST_EMPTY);
	n_node = linkedlist_init(value);
	n_node->next = c_node->next;
	c_node->next = n_node;
	return (n_node);
}

t_linkedlist	linkedlist_getlast(t_linkedlist list)
{
	if (!list)
		return (LINKEDLIST_EMPTY);
	while (list->next)
		list = list->next;
	return (list);
}

/**
 * @brief Sorts a linked list using the bubble sort algorithm.
 *
 * @attention not tested
 */
#include <stdio.h>
void	linkedlist_sort(t_linkedlist *list, t_comparator cmp)
{
	t_linkedlist	i;
	t_linkedlist	j;
	t_generic		tmp;

	if (!list || !*list || !cmp)
		return ;
	i = *list;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (cmp(i->info, j->info) > 0)
			{
				tmp = i->info;
				i->info = j->info;
				j->info = tmp;
			}
			j = j->next;
		}
		i = i->next;
	}
}
