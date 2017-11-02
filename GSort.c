/* ========================================================================= *
* GSort
* Implementation of the GSort algorithm.
* cf powerpoint dia 185
* ========================================================================= */

#include <stddef.h>
#include "Sort.h"

void GSort(int* array, int p, int r)
{
	int tmp;
	if (p >= r)return;
	GSort(array, p, r - 1);
	if (array[r - 1] > array[r])
	{
		tmp = array[r - 1];
		array[r - 1] = array[r];
		array[r] = tmp;
		GSort(array, p, r - 1);
	}
}