#include "../../Algorithms/Sort/Sorting.h"
#include "Heap.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Create a new heap entry.
 * @param capacity: the capacity of the heap
 * @param cmp: function to compare the keys of the heap entries
 * @param dealloc: function to deallocate the entry of the heap (key + value
	+ entry itself)
 * @param is_min_heap: if the heap is a min heap
 */
t_heap	Heap_Init(size_t capacity, Comparator cmp, Deallocator dealloc,
		bool is_min_heap)
{
	t_heap	heap;

	heap = malloc(sizeof(t_heap_));
	if (!heap)
		return (NULL);
	heap->entries = malloc(sizeof(t_heap_entry) * capacity);
	if (!heap->entries)
	{
		free(heap);
		return (NULL);
	}
	heap->length = 0;
	heap->capacity = capacity;
	heap->cmp = cmp;
	heap->dealloc = dealloc;
	heap->is_min_heap = is_min_heap;
	return (heap);
}

/**
 * @brief Free the heap
 */
void	Heap_Free(t_heap heap)
{
	size_t			i;
	t_heap_entry	*entries;
	Deallocator		dealloc;

	if (!heap)
		return ;
	i = 0;
	entries = heap->entries;
	dealloc = heap->dealloc;
	while (i < heap->length)
	{
		dealloc(entries[i]);
		i++;
	}
	free(heap->entries);
	free(heap);
}

/**
 * @brief swap entrie values
 */
static void	swap_entries(t_heap_entry a, t_heap_entry b)
{
	Generic	key;
	Generic	value;

	if (!a || !b)
		return ;
	key = a->key;
	value = a->value;
	a->key = b->key;
	a->value = b->value;
	b->key = key;
	b->value = value;
}

/**
 * @brief gets null terminated array length
 */
static size_t	limit_arr(t_heap_entry *arr, size_t expected_lenth)
{
	size_t	i;

	if (!arr || !expected_lenth)
		return (0);
	i = 0;
	while (i < expected_lenth && arr[i])
		i++;
	return (i);
}

/**
 * @brief Heapify the heap at index i
 */
void	Heap_Heapify(t_heap heap, size_t index)
{
	t_heap_entry	temp[3];
	t_heap_entry	swap;
	size_t			max_length;

	if (!heap || !heap->length)
		return ;
	temp[0] = heap->entries[index];
	temp[1] = HeapEntry_GetLeftChild(heap, index);
	temp[2] = HeapEntry_GetRightChild(heap, index);
	max_length = limit_arr(temp, 3);
	if (!max_length)
		return ;
	MergeSort((Generic *)temp, max_length, heap->cmp);
	if (heap->is_min_heap)
		swap = temp[0];
	else
		swap = temp[max_length - 1];
	if (swap->index == index)
		return ;
	swap_entries(heap->entries[index], swap);
	Heap_Heapify(heap, swap->index);
}

/**
 * @brief Build the heap from a generic array
 */
void	Heap_Build(t_heap heap)
{
	size_t	i;

	i = heap->length / 2;
	while (i > 0)
	{
		Heap_Heapify(heap, i);
		i--;
	}
}

/**
 * @brief get min
 * @return actual value
 */
Generic	Heap_GetMin(t_heap heap)
{
	if (!heap || !heap->is_min_heap)
		return (NULL);
	if (heap->length == 0)
		return (NULL);
	return (heap->entries[0]->value);
}

/**
 * @brief get max
 * @return actual value
 */
Generic	Heap_GetMax(t_heap heap)
{
	if (!heap || heap->is_min_heap)
		return (NULL);
	if (heap->length == 0)
		return (NULL);
	return (heap->entries[0]->value);
}

/**
 * @brief Poll the min value from the heap
 * @return the heap entry containing the min value
 */
t_heap_entry	Heap_PollMin(t_heap heap)
{
	t_heap_entry	min;

	if (!heap || !heap->is_min_heap || !heap->length)
		return (NULL);
	min = heap->entries[0];
	heap->entries[0] = heap->entries[heap->length - 1];
	heap->length--;
	Heap_Heapify(heap, 0);
	return (min);
}

/**
 * @brief Poll the max value from the heap
 * @return the heap entry containing the max value
 */
t_heap_entry	Heap_PollMax(t_heap heap)
{
	t_heap_entry	max;

	if (!heap || heap->is_min_heap || !heap->length)
		return (NULL);
	max = heap->entries[0];
	heap->entries[0] = heap->entries[heap->length - 1];
	heap->length--;
	Heap_Heapify(heap, 0);
	return (max);
}

/**
 * @brief Increase the key of the heap at index
 */
void	Heap_Increase(t_heap heap, size_t index)
{
	t_heap_entry	parent;

	if (!heap)
		return ;
	while (index && (parent = HeapEntry_GetParent(heap, index))
		&& heap->cmp(parent, heap->entries[index]) < 0)
	{
		swap_entries(heap->entries[index], parent);
		index = ENTRY_PARENT(index);
	}
}

/**
 * @brief Decrease the key of the heap at index
 */
void	Heap_Decrease(t_heap heap, size_t index)
{
	t_heap_entry	parent;

	if (!heap)
		return ;
	while (index && (parent = HeapEntry_GetParent(heap, index))
		&& heap->cmp(parent, heap->entries[index]) > 0)
	{
		swap_entries(heap->entries[index], parent);
		index = ENTRY_PARENT(index);
	}
}

/**
 * @brief Insert a new entry in the heap
 */
void	Heap_Insert(t_heap heap, t_heap_entry entry)
{
	if (!heap || !entry || !entry->key)
		return ;
	if (heap->length == heap->capacity)
		return ;
	entry->index = heap->length;
	heap->entries[heap->length] = entry;
	heap->length++;
	if (heap->is_min_heap)
		Heap_Decrease(heap, heap->length - 1);
	else
		Heap_Increase(heap, heap->length - 1);
}

/**
 * @brief Replace the key of the entry in the heap
 */
void	Heap_ReplaceKey(t_heap heap, t_heap_entry entry, Generic key,
		Deallocator dealloc)
{
	void	(*func)(t_heap, size_t);

	if (!heap || !entry || !key)
		return ;
	func = (heap->is_min_heap) ? Heap_Decrease : Heap_Increase;
	if (dealloc)
		dealloc(entry->key);
	entry->key = key;
	func(heap, entry->index);
}
