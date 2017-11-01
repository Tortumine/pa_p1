/* ========================================================================= *
* QuickSort
* Implementation of the QuickSort algorithm.
* ========================================================================= */

#include <stddef.h>
#include "Sort.h"


void QuickSort(int* array, int left, int right)
{
	int mid=0;
	if(right>left)
	{
		mid = Partition(array,left,right);
		QuickSort(array, left, mid-1);
		QuickSort(array, mid + 1, right);
	}
}
int Partition(int* array, int left, int right)
{
	int i = left - 1;
	int pivot = array[right];

	for (int j = left; j < right; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			Swap(array, i, j);
		}
	}
	Swap(array, i + 1, right);
	return i+1;
}

void Swap(int* array, int a, int b)
{
	int tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;
}