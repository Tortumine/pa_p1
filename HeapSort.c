/* ========================================================================= *
* HeapSort
* Implementation of the HeapSort algorithm.
* cf powerpoint dia 185
* ========================================================================= */

#include <stddef.h>
#include "HeapSort.h"


void MaxHeapify(int* array, int heapsize, int i)
{
	int left = 2 * i + 1;	// array starts at 0
	int right = 2 * i + 2;	// array starts at 0
	int largest;

	if ((left <= heapsize) && (array[left] >= array[i]))
	{
		largest = left;
	}
	else
	{
		largest = i;
	}
	if ((right < heapsize) && (array[right] > array[largest]))
	{
		largest = right;
	}
	if (largest != i)
	{
		Swap(array, i, largest);
		MaxHeapify(array, heapsize, largest);
	}
}


void BuildMaxHeap(int* array, int lenght)
{
	for (int i = lenght / 2 - 1; i >= 0; i--)
	{
		MaxHeapify(array, lenght-1, i);
	}
}
void HeapSort(int* array, int lenght)
{
	BuildMaxHeap(array, lenght);
	for (int i = lenght-1; i >= 0; i--)
	{
		Swap(array, i, 0);
		MaxHeapify(array, i-1, 0);
	}
}
