#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Array.h"
#include "Sort.h"
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
	return ((double)(stop - start))/* / CLOCKS_PER_SEC*/;
}
double cpuTimeQuickSort(int* array, size_t length)
{
	clock_t start, stop;
	start = clock();
	QuickSort(array,0, length-1);
	stop = clock();
	return ((double)(stop - start))/* / CLOCKS_PER_SEC*/;
}
double cpuTimeRandomizedQuickSort(int* array, size_t length)
{
	clock_t start, stop;
	start = clock();
	RandomizedQuickSort(array, 0, length - 1);
	stop = clock();
	return ((double)(stop - start))/* / CLOCKS_PER_SEC*/;
}
double cpuTimeHeapSort(int* array, size_t length)
{
	clock_t start, stop;
	start = clock();
	HeapSort(array, length - 1);
	stop = clock();
	return ((double)(stop - start))/* / CLOCKS_PER_SEC*/;
}
double cpuTimeGSort(int* array, size_t length)
{
	clock_t start, stop;
	start = clock();
	GSort(array,0, length - 1);
	stop = clock();
	return ((double)(stop - start))/* / CLOCKS_PER_SEC*/;
}

void clearBuffer()
{
	int c = 0;
	while (c != '\n' && c != EOF)
	{
		c = getchar();
	}
}
//void initTmpArrays(int* arrays_tmp,int* arrays_p,int* sizeArray)
//{
//	for (int i = 0; i<5; i++)
//	{
//		memcpy(arrays_tmp[i], arrays_p[i], sizeArray[i] * sizeof(int));
//	}
//}

/* ------------------------------------------------------------------------- *
* Main
* ------------------------------------------------------------------------- */
int main(void)
{
	srand((unsigned int) time(NULL));//Use an integer seed to get a fix sequence
	char tmp;
	int *arrays_p[5];
	int *arrays_tmp[5];
	int i = 0;
	size_t sizeArray[5] = { 100,1000,10000,100000, 1000000};
	

	
	for (i = 0; i < 5; i++)
	{
		arrays_p[i] = createRandomArray(sizeArray[i]);
		arrays_tmp[i] = malloc(sizeof(int)*sizeArray[i]);
	}

	int e = 1;
	while (e == 1)
	{
		printf("Chose benchmark\n1 : Insertion\n2 : QuickSort\n3 : RandomisedQuickSort\n4 : HeapSort\n5 : GSort\n0 : Quit\n\n");
		scanf("%c",&tmp);
		clearBuffer();
		switch (tmp)
		{
		case '1':
			//initTmpArrays(arrays_tmp, arrays_p, sizeArray);
			for (int i = 0; i<5; i++)
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
			//initTmpArrays(arrays_tmp, arrays_p, sizeArray);
			for (int i = 0; i<5; i++)
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
				if (i == 0)
				{
					for (int j = 0; j < 5; j++)
					{
						printf("%d\n", arrays_tmp[i][j]);
					}
				}
			}
			break;
		case '3':
			//initTmpArrays(arrays_tmp, arrays_p, sizeArray);
			for (int i = 0; i<5; i++)
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
		case '4':
			//initTmpArrays(arrays_tmp, arrays_p, sizeArray);
			for (int i = 0; i<5; i++)
			{
				memcpy(arrays_tmp[i], arrays_p[i], sizeArray[i] * sizeof(int));
			}
			printf("----------------------------------------\n");
			printf("HeapSort\n");
			for (i = 0; i < 5; i++)
			{
				printf("\tSize of the array: %d\n", (int)sizeArray[i]);
				double sec = cpuTimeHeapSort(arrays_tmp[i], sizeArray[i]);
				printf("\t\tCPU Time: %.10f\n", sec);
			}
			break;
		case '5':
			//initTmpArrays(arrays_tmp, arrays_p, sizeArray);
			for (int i = 0; i<5; i++)
			{
				memcpy(arrays_tmp[i], arrays_p[i], sizeArray[i] * sizeof(int));
			}
			printf("----------------------------------------\n");
			printf("GSort\n");
			for (i = 0; i < 2; i++)
			{
				printf("\tSize of the array: %d\n", (int)sizeArray[i]);
				double sec = cpuTimeGSort(arrays_tmp[i], sizeArray[i]);
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
	free(arrays_p);
	free(arrays_tmp);
	return 0;
}

