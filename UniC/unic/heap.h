#ifndef HEAP_H
# define HEAP_H
# include "unic/types.h"
# include <stdbool.h>
# include <stddef.h>
# define ENTRY_LEFT(i) (2 * i + 1)
# define ENTRY_RIGHT(i) (2 * i + 2)
# define ENTRY_PARENT(i) ((i - 1) / 2)

typedef struct s_heap_entry
{
	size_t				index;
	t_generic			key;
	t_generic			value;
}						t_heap_entry_;

typedef t_heap_entry_	*t_heap_entry;

typedef struct s_heap
{
	t_heap_entry		*entries;
	size_t				length;
	size_t				capacity;
	t_comparator		cmp;
	t_deallocator		dealloc;
	bool				is_min_heap;
}						t_heap_;

typedef t_heap_			*t_heap;

t_heap_entry			heap_entry_Init(t_generic key, t_generic value);
t_heap_entry			heap_entry_getleftchild(t_heap heap, size_t i);
t_heap_entry			heap_entry_getrightchild(t_heap heap, size_t i);
t_heap_entry			heap_entry_getparent(t_heap heap, size_t i);

t_heap					heap_init(size_t capacity, t_comparator cmp,
							t_deallocator dealloc, bool is_min_heap);
void					heap_free(t_heap heap);
void					heap_heapify(t_heap heap, size_t index);
void					heap_build(t_heap heap);
void					heap_insert(t_heap heap, t_heap_entry entry);
t_heap_entry			heap_pollmin(t_heap heap);
t_heap_entry			heap_pollmax(t_heap heap);
t_generic				heap_getmin(t_heap heap);
t_generic				heap_getmax(t_heap heap);
void					heap_increase(t_heap heap, size_t index);
void					heap_decrease(t_heap heap, size_t index);
void					heap_replacekey(t_heap heap, t_heap_entry entry,
							t_generic key, t_deallocator dealloc);

#endif