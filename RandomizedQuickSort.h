/* ========================================================================= *
* QuickSort
* ========================================================================= */

#ifndef _RANDOMIZEDQUICKSORT_H_
#define _RANDOMIZEDQUICKSORT_H_

#include <stddef.h>


/* ------------------------------------------------------------------------- *
* RandomizedQuickSort an array of integers.
*
* PARAMETERS
* array        The array to sort
* length       Number of elements in the array
* ------------------------------------------------------------------------- */
void RandomizedQuickSort(int* array, int left, int right);
int RandomizedPartition(int* array, int left, int right);

#endif // !_RANDOMIZEDQUICKSORT_H_