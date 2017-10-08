/* ========================================================================= *
* QuickSort
* ========================================================================= */

#ifndef _QUICKSORT_H_
#define _QUICKSORT_H_

#include <stddef.h>


/* ------------------------------------------------------------------------- *
* QuickSort an array of integers.
*
* PARAMETERS
* array        The array to sort
* length       Number of elements in the array
* ------------------------------------------------------------------------- */
void QuickSort(int* array, int left, int right);
int Partition(int* array, int left, int right);
void Swap(int* array, int a, int b);

#endif // !_SORT_H_