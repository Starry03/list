#ifndef DOUBLELINKEDLIST_H
# define DOUBLELINKEDLIST_H

# include "unic/nodes.h"
# include <stddef.h>

typedef t_doublenode	t_double_linkedlist;

# define DOUBLELINKEDLIST_EMPTY (t_double_linkedlist) NULL

t_double_linkedlist		double_linkedlist_init(t_generic info);
t_double_linkedlist		double_linkedlist_insert(t_double_linkedlist *list,
							t_generic info, size_t index);
t_double_linkedlist		double_linkedlist_append(t_double_linkedlist list,
							t_generic info);
t_double_linkedlist		double_linkedlist_push(t_double_linkedlist *list,
							t_generic info);
void					double_linkedlist_removebyvalue(t_double_linkedlist list,
							t_comparator cmp, t_generic info,
							t_deallocator dealloc);
void					double_linkedlist_remove(t_double_linkedlist node,
							t_deallocator dealloc);
void					double_linkedlist_removebyindex(t_double_linkedlist list,
							size_t index, t_deallocator dealloc);
t_double_linkedlist		double_linkedlist_search(t_double_linkedlist list,
							t_comparator cmp, t_generic info);
t_double_linkedlist		double_linkedlist_getnth(t_double_linkedlist list,
							size_t index);
t_double_linkedlist		double_linkedlist_getfirst(t_double_linkedlist list);
t_double_linkedlist		double_linkedlist_getlast(t_double_linkedlist list);
t_double_linkedlist		double_linkedlist_getNext(t_double_linkedlist list);
t_double_linkedlist		double_linkedlist_getprev(t_double_linkedlist list);
t_double_linkedlist		double_linkedlist_getinfo(t_double_linkedlist list);
size_t					double_linkedlist_getlength(t_double_linkedlist list);
void					double_linkedlist_dealloc(t_double_linkedlist list,
							t_deallocator dealloc);

#endif