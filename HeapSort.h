/* ========================================================================= *
* HeapSort
* ========================================================================= */

#ifndef _HEAPSORT_H_
#define _HEAPSORT_H_

#include <stddef.h>


/* ------------------------------------------------------------------------- *
* HeapSort an array of integers.
*
* PARAMETERS
* array        The array to sort
* length       Number of elements in the array
* ------------------------------------------------------------------------- */
void HeapSort(int* array, int lenght);
void BuildMaxHeap(int* array, int lenght);
void MaxHeapify(int* array, int heapsize, int i);

#endif // !_SORT_H_