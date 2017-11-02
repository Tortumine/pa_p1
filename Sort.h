/* ========================================================================= *
* InsertionSort
* ========================================================================= */

#ifndef _SORT_H_
#define _SORT_H_

#include <stddef.h>



/* ------------------------------------------------------------------------- *
* InsertionSort an array of integers.
*
* PARAMETERS
* array        The array to sort
* length       Number of elements in the array
* ------------------------------------------------------------------------- */
void InsertionSort(int* array, size_t length);

/* ------------------------------------------------------------------------- *
* QuickSort an array of integers.
*
* PARAMETERS
* array        The array to sort
* length       Number of elements in the array
* ------------------------------------------------------------------------- */
void QuickSort(int* array, int left, int right);
int Partition(int* array, int left, int right);


/* ------------------------------------------------------------------------- *
* RandomizedQuickSort an array of integers.
*
* PARAMETERS
* array        The array to sort
* length       Number of elements in the array
* ------------------------------------------------------------------------- */
void RandomizedQuickSort(int* array, int left, int right);
int RandomizedPartition(int* array, int left, int right);

/* ------------------------------------------------------------------------- *
* HeapSort an array of integers.
*
* PARAMETERS
* array        The array to sort
* length       Number of elements in the array
* ------------------------------------------------------------------------- */
void HeapSort(int* array, size_t  lenght);
void BuildMaxHeap(int* array, int lenght);
void MaxHeapify(int* array, int heapsize, int i);

/* ------------------------------------------------------------------------- *
* GSort an array of integers.
*
* PARAMETERS
* array        The array to sort
* length       Number of elements in the array
* ------------------------------------------------------------------------- */
void GSort(int* array, int left, int right);

#endif // !_SORT_H_