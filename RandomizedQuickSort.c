/* ========================================================================= *
* QuickSort
* Implementation of the QuickSort algorithm.
* ========================================================================= */

#include <stddef.h>
#include "QuickSort.h"
#include "RandomizedQuickSort.h"
#include <stdlib.h>


void RandomizedQuickSort(int* array, int left, int right)
{
	int mid = 0;
	if (right>left)
	{
		mid = RandomizedPartition(array, left, right);
		QuickSort(array, left, mid - 1);
		QuickSort(array, mid + 1, right);
	}
}
int RandomizedPartition(int* array, int left, int right)
{
	int mid = rand() % (right + 1 - left) + left;
	int i = left - 1;
	int pivot = array[mid];

	for (int j = left; j < right; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			Swap(array, i, j);
		}
	}
	Swap(array, i + 1, right);
	return i + 1;
}