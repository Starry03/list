//
// Created by andre on 4/19/2023.
//

#ifndef SORTING_H
#define SORTING_H

#include <stddef.h>
#include <stdbool.h>
#include "Utils/types.h"

void BubbleSort(Generic *array, size_t size, int (*cmp)(Generic, Generic));

void InsertionSort(Generic *array, size_t size, int (*cmp)(Generic, Generic));

void MergeSort(Generic *array, size_t size, int (*cmp)(Generic, Generic));

void MergeSort_rec(Generic *arr, size_t low, size_t high, int (*cmp)(Generic, Generic));

void Merge(Generic *arr, size_t low, size_t mid, size_t high, int (*cmp)(Generic, Generic));

void QuickSort_rec(int *arr, size_t low, size_t high);

void QuickSort(int *array, size_t size);

void CountingSort(const int array[], int dest[], int size, int k);

void RadixSort(int *array, size_t size);

void BucketSort(Generic *array, int size);

void HeapSort(int *arr, size_t size);

#endif //STARRY_SORTING_H
