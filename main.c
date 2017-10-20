#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Array.h"
#include "Sort.h"
#include "InsertionSort.h"
#include "QuickSort.h"
#include "RandomizedQuickSort.h"
#include <string.h>


/* Prototypes */

/* ------------------------------------------------------------------------- *
* Compute the CPU time (in seconds) used by the Sort function.
*
* PARAMETERS
* array        Array to sort
* length       Number of elements in the array
*
* RETURN
* seconds      The number of seconds used by Sort
* ------------------------------------------------------------------------- */
double cpuTimeInsertionSort(int* array, size_t length)
{
	clock_t start, stop;
	start = clock();
	InsertionSort(array, length);
	stop = clock();
	return ((double)(stop - start)) / CLOCKS_PER_SEC;
}
double cpuTimeQuickSort(int* array, size_t length)
{
	clock_t start, stop;
	start = clock();
	QuickSort(array,0, length-1);
	stop = clock();
	return ((double)(stop - start)) / CLOCKS_PER_SEC;
}
double cpuTimeRandomizedQuickSort(int* array, size_t length)
{
	clock_t start, stop;
	start = clock();
	RandomizedQuickSort(array, 0, length - 1);
	stop = clock();
	return ((double)(stop - start)) / CLOCKS_PER_SEC;
}

/* ------------------------------------------------------------------------- *
* Main
* ------------------------------------------------------------------------- */
int main(void)
{
	srand((unsigned int) time(NULL));//Use an integer seed to get a fix sequence
	char tmp;
	int* array = NULL;
	int* array_copy = NULL;
	int i = 0;
	size_t sizeArray[5] = { 100,1000,10000,100000, 1000000};
	
	int *arrays_p[5];
	int *arrays_tmp[5];
	
	for (i = 0; i < 5; i++)
	{
		arrays_p[i] = createRandomArray(sizeArray[i]);
		arrays_tmp[i] = malloc(sizeof(int)*sizeArray[i]);
	}	

	int e = 1;
	while (e == 1)
	{
		// TODO: this printf is called 2 tilmes after the first run
		printf("Chose benchmark\n1 : Insertion\n2 : QuickSort\n3 : RandomisedQuickSort\n0 : Quit\n\n");
		tmp = getchar();
		switch (tmp)
		{
		case '1':
			for (i = 0; i<5; i++)
			{
				memcpy(arrays_tmp[i], arrays_p[i], sizeArray[i] * sizeof(int));
			}

			printf("----------------------------------------\n");
			printf("InsertionSort\n");
			for (i = 0; i < 5; i++)
			{
				printf("\tSize of the array: %d\n", (int)sizeArray[i]);
				double sec = cpuTimeInsertionSort(arrays_tmp[i], sizeArray[i]);
				printf("\t\tCPU Time: %.10f\n", sec);
			}
			break;
		case '2':
			for (i = 0; i<5; i++)
			{
				memcpy(arrays_tmp[i], arrays_p[i], sizeArray[i] * sizeof(int));
			}

			printf("----------------------------------------\n");
			printf("QuickSort\n");
			for (i = 0; i < 5; i++)
			{
				printf("\tSize of the array: %d\n", (int)sizeArray[i]);
				double sec = cpuTimeQuickSort(arrays_tmp[i], sizeArray[i]);
				printf("\t\tCPU Time: %.10f\n", sec);
			}
			break;
		case '3':
			for (i = 0; i<5; i++)
			{
				memcpy(arrays_tmp[i], arrays_p[i], sizeArray[i] * sizeof(int));
			}

			printf("----------------------------------------\n");
			printf("RandomizedQuickSort\n");
			for (i = 0; i < 5; i++)
			{
				printf("\tSize of the array: %d\n", (int)sizeArray[i]);
				double sec = cpuTimeRandomizedQuickSort(arrays_tmp[i], sizeArray[i]);
				printf("\t\tCPU Time: %.10f\n", sec);
			}
			break;
		case '0':
			e = 0;
			break;
		default:
			break;
		}
	}
	
	free(array);
	return 0;
}
