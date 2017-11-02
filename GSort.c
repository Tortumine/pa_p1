/* ========================================================================= *
* GSort
* Implementation of the GSort algorithm.
* cf powerpoint dia 185
* ========================================================================= */

#include <stddef.h>
#include "Sort.h"

void GSort(int* array, int left, int right)
{
	int tmp;
	if (left >= right)return;
	GSort(array, left, right - 1);
	if (array[right - 1] > array[right])
	{
		tmp = array[right - 1];
		array[right - 1] = array[right];
		array[right] = tmp;
		GSort(array, left, right - 1);
	}
}