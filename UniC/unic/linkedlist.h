//
// Created by andre on 8/8/2023.
//

#ifndef LINKEDLIST_H
# define LINKEDLIST_H

# include "unic/nodes.h"
# include <stddef.h>

typedef t_node	t_linkedlist;

# define LINKEDLIST_EMPTY (t_linkedlist)0

t_linkedlist	linkedlist_init(t_generic value);

void			linkedlist_push(t_linkedlist *list, t_generic object);

t_linkedlist	linkedlist_append(t_linkedlist *list, t_generic value);

t_linkedlist	linkedlist_insert(t_linkedlist *list, t_generic value,
					size_t index);

void			linkedlist_remove(t_linkedlist *node, t_deallocator dealloc);

void			linkedlist_removebyvalue(t_linkedlist *list, t_generic value,
					t_deallocator dealloc, int (*cmp)(t_generic, t_generic));

t_linkedlist	linkedlist_getnext(t_linkedlist list);

t_generic		linkedlist_getinfo(t_linkedlist list);

t_linkedlist	linkedlist_getnode(t_linkedlist list, t_generic value);

t_linkedlist	linkedlist_getnth(t_linkedlist list, size_t n);

void			linkedlist_removenth(t_linkedlist *list, size_t n,
					t_deallocator dealloc);

t_linkedlist	linkedlist_getlast(t_linkedlist list);

void			linkedlist_dealloc(t_linkedlist head, t_deallocator dealloc);

size_t			linkedlist_size(t_linkedlist list);

void			linkedlist_sort(t_linkedlist *list, t_comparator cmp);

#endif // LINKEDLIST_H
