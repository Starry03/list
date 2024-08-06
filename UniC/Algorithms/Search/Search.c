//
// Created by andre on 4/18/2023.
//

#include "Search.h"

/**
 * @brief Linear search algorithm
 * @param arr Array to search
 * @param length Length of the array
 * @param target Target to search
 * @param cmp Comparison function
 */
size_t	LinearSearch(const Generic *arr, size_t length, Generic target,
		Comparator cmp)
{
	size_t	count;

	count = 0;
	while (count < length)
	{
		if (!cmp(arr[count], target))
			return (count);
		count++;
	}
	return (-1);
}

/**
 * @brief Binary search algorithm
 * @param arr Array to search
 * @param length Length of the array
 * @param target Target to search
 * @param cmp Comparison function
 */
size_t	BinarySearch(const Generic *arr, size_t length, Generic target,
		Comparator cmp)
{
	size_t	left;
	size_t	right;
	size_t	mid;

	left = 0;
	right = length - 1;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (!cmp(arr[mid], target))
			return (mid);
		if (cmp(arr[mid], target) > 0)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}
