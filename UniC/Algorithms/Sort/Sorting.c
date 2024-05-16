//
// Created by andre on 4/19/2023.
//

#include "DataStructures/LinkedList/LinkedList.h"
#include "Sorting.h"
#include "Utils/Logging/Logging.h"
#include "Utils/types.h"
#include <math.h>
#include <string.h>

static void	swap(Generic *a, Generic *b)
{
	Generic	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

// O(n^2)
void	BubbleSort(Generic *array, size_t size, int (*cmp)(Generic, Generic))
{
	bool	swapped;

	swapped = true;
	while (swapped)
	{
		swapped = false;
		for (size_t i = 0; i < size - 1; i++)
		{
			if (cmp(array[i], array[i + 1]) > 0)
			{
				swap(array + i, array + i + 1);
				swapped = true;
			}
		}
	}
}

// O(n^2)
void	InsertionSort(Generic *array, size_t size, int (*cmp)(Generic, Generic))
{
	size_t	currentIndex;

	for (size_t i = 1; i < size; i++)
	{
		currentIndex = i;
		while (currentIndex > 0 && cmp(array[currentIndex], array[currentIndex
				- 1]) < 0)
		{
			swap(array + currentIndex, array + currentIndex - 1);
			currentIndex--;
		}
	}
}

// O(n log n)
void	Merge(Generic *arr, size_t low, size_t mid, size_t high,
		int (*cmp)(Generic, Generic))
{
	const size_t	tempLength = high - low + 1;
	Generic			*temp[tempLength];
	size_t			left;
	size_t			right;
	size_t			tempCounter;

	if (!arr)
		return ;
	// pointers to the left and right sub-arrays
	left = low;
	right = mid + 1;
	tempCounter = 0;
	// basic merge
	while (left <= mid && right <= high)
	{
		if (cmp(arr[left], arr[right]) > 0)
			temp[tempCounter++] = arr[right++];
		else
			temp[tempCounter++] = arr[left++];
	}
	// copy the rest of the sub-array that still has elements
	if (right > high)
		while (left <= mid)
			temp[tempCounter++] = arr[left++];
	else
		while (right <= high)
			temp[tempCounter++] = arr[right++];
	// copy temp to arr
	for (size_t i = 0; i < tempLength; i++)
		arr[low + i] = temp[i];
}

// O(n log n)
void	MergeSort_rec(Generic *arr, size_t low, size_t high, int (*cmp)(Generic,
			Generic))
{
	size_t	mid;

	// low < high when there are at least 2 elements
	if (low >= high)
		return ;
	mid = (low + high) / 2;
	MergeSort_rec(arr, low, mid, cmp);
	MergeSort_rec(arr, mid + 1, high, cmp);
	Merge(arr, low, mid, high, cmp);
}

// O(n log n)
void	MergeSort(Generic *array, size_t size, int (*cmp)(Generic, Generic))
{
	MergeSort_rec(array, 0, size - 1, cmp);
}

// O(n log n)
void	QuickSort_rec(int *arr, size_t low, size_t high)
{
	size_t	left;
	size_t	right;
	int		pivot;

	if (low < high)
	{
		left = low;
		right = high;
		pivot = arr[low];
		// partition
		while (left < right)
		{
			while (arr[right] > pivot)
				right--;
			while (left < right && arr[left] <= pivot)
				left++;
			if (left < right)
				swap((void *)(arr + left), (void *)(arr + right));
		}
		// fix pivot position
		if (low != right)
		{
			arr[low] = arr[right];
			arr[right] = pivot;
		}
		// recursive calls
		if (right - 1 > low)
			QuickSort_rec(arr, low, right - 1);
		if (right + 1 < high)
			QuickSort_rec(arr, right + 1, high);
	}
}

// O(n log n)
void	QuickSort(int *array, size_t size)
{
	QuickSort_rec(array, 0, size - 1);
}

/*
 * O(n + k)
 */
void	CountingSort(const int array[], int dest[], int size, int k)
{
	int	c[k + 1];
	int	n_lower;

	int i, j;
	// number of elements lower than the current element
	memset(c, 0, (k + 1) * sizeof(int));
	for (j = 0; j < size; j++)
		c[array[j]] += 1;
	for (i = 1; i < k + 1; i++)
		c[i] = c[i] + c[i - 1];
	for (j = size - 1; j >= 0; j--)
	{
		n_lower = c[array[j]] - 1;
		dest[n_lower] = array[j];
		c[array[j]] -= 1;
		Log_intarray(dest, size, n_lower);
	}
}

/**
 * O(n)
 *
 * @brief range[0, 1) => 10 buckets of linked lists
 * @param array
 * @param size
 * @warning not runnable
 */
void	BucketSort(Generic *array, int size)
{
	int index __attribute__((unused));
	LinkedList buckets[size] __attribute__((unused));
	for (int i = 0; i < size; i++)
		buckets[i] = LINKEDLIST_EMPTY;
	for (int i = 1; i <= size; i++)
	{
		index = floor(size * (*(int *)array[i]));
		// LinkedList_Append(buckets + index, array[i]);
	}
	for (int i = 0; i < size; i++)
	{
		// InsertionSort(bucket[i], &LinkedList_Cmp)
		// concat lists
	}
}
