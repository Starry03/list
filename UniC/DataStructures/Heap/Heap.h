#ifndef HEAP_H
# define HEAP_H
# include "../../Utils/types.h"
# include <stdbool.h>
# include <stddef.h>
# define ENTRY_LEFT(i) (2 * i + 1)
# define ENTRY_RIGHT(i) (2 * i + 2)
# define ENTRY_PARENT(i) ((i - 1) / 2)

typedef struct s_heap_entry
{
	size_t				index;
	Generic				key;
	Generic				value;
}						t_heap_entry_;

typedef t_heap_entry_	*t_heap_entry;

typedef struct s_heap
{
	t_heap_entry		*entries;
	size_t				length;
	size_t				capacity;
	Comparator			cmp;
	Deallocator			dealloc;
	bool				is_min_heap;
}						t_heap_;

typedef t_heap_			*t_heap;

t_heap_entry			HeapEntry_Init(Generic key, Generic value);
t_heap_entry			HeapEntry_GetLeftChild(t_heap heap, size_t i);
t_heap_entry			HeapEntry_GetRightChild(t_heap heap, size_t i);
t_heap_entry			HeapEntry_GetParent(t_heap heap, size_t i);

t_heap					Heap_Init(size_t capacity, Comparator cmp,
							Deallocator dealloc, bool is_min_heap);
void					Heap_Free(t_heap heap);
void					Heap_Heapify(t_heap heap, size_t index);
void					Heap_Build(t_heap heap);
void					Heap_Insert(t_heap heap, t_heap_entry entry);
t_heap_entry			Heap_PollMin(t_heap heap);
t_heap_entry			Heap_PollMax(t_heap heap);
Generic					Heap_GetMin(t_heap heap);
Generic					Heap_GetMax(t_heap heap);
void					Heap_Increase(t_heap heap, size_t index);
void					Heap_Decrease(t_heap heap, size_t index);
void					Heap_ReplaceKey(t_heap heap, t_heap_entry entry,
							Generic key, Deallocator dealloc);

#endif