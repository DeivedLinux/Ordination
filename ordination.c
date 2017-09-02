#include "ordination.h"
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define Swap(a,b)  {int temp; temp = a; a = b; b = temp;}


inline __attribute__((always_inline))void SwapObj(void* Obj1, void* Obj2)
{
	void* temp;

	temp = Obj1;
	Obj1 = Obj2;
	Obj2 = temp;
}

static void merge(int* vector, int start, int middle, int end)
{
	bool isEndFirstVector;
	bool isEndSecondVector;
	unsigned size;
	unsigned startFirstVector;
	unsigned startSecondVector;
	int* vectorAux;
	unsigned i,j,k;

	size = end-start+1;
	isEndFirstVector = false;
	isEndSecondVector = false;
	startFirstVector = start;
	startSecondVector = middle+1;
	vectorAux = (int*)calloc(size,sizeof(int));

	if(vectorAux != NULL)
	{
		for(i = 0; i < size; i++)
		{
			if(!isEndFirstVector && !isEndSecondVector)
			{
				if(vector[startFirstVector] < vector[startSecondVector])
				{
					vectorAux[i] = vector[startFirstVector++];
					startFirstVector += 1;
				}
				else 
				{
					vectorAux[i] = vector[startSecondVector];
					startSecondVector += 1;
				}
				if(startFirstVector > middle)
					isEndFirstVector = true;

				if(startSecondVector > end)
					isEndSecondVector = true;
			}
			else
			{
				if(!isEndFirstVector)
				{
					vectorAux[i] = vector[startFirstVector];
					startFirstVector += 1;
				}
				else
				{
					vectorAux[i] = vector[startSecondVector];
					startSecondVector += 1;
				}
			}
		}
		for(j = 0, k = start; j < size; j++,k++)
			vector[k] = vectorAux[j];
	}

	free(vectorAux);
}

static int partitionVector(int* vector, int start, int end)
{
	int pivot;
	int left;
	int right;

	left = start;
	right = end;
	pivot = vector[start];

	while(left < right)
	{
		while(vector[left] <= pivot)
			left += 1;
		while(vector[right] > pivot)
			right -= 1;

		if(left < right)
		{
			Swap(vector[left],vector[right]);
		}
	}
	vector[start] = vector[right];
	vector[right] = pivot;

	return right;
}

void quickSort(int* vector, int start, int end)
{
	int pivot;

	if(end > start)
	{
		pivot = partitionVector(vector,start,end);
		quickSort(vector,start,pivot-1);
		quickSort(vector,pivot+1,end);
	}
}


void mergeSort(int* vector, int start, int end)
{
	int middle;

	if(start < end)
	{
		middle = floor((start+end)/2);
    	mergeSort(vector,start,middle);
    	mergeSort(vector,middle+1,end);
    	merge(vector,start,middle,end);
    }
    printf("%i\n",start );
}


void insertSort(int* vector, unsigned n)
{
	int i;
	int j;
	int key;

	for(j = 1; j < n; j++)
	{
		key = vector[j];
		i = j - 1;

		while(i >= 0 && vector[i] > key)
		{
			vector[i+1] = vector[i];
			i -= 1;
		}
		
		vector[i + 1] = key;
	}
}

void bubbleSort(int* vector, int n)

{
	bool swapped = false;
	unsigned i;

	do
	{
		swapped = false;
		for(i = 0; i < n-1; i++)
		{
			if(vector[i] > vector[i + 1])
			{   
				Swap(vector[i],vector[i+1]);
				swapped = true;
			}
		}
	}while(swapped);

}