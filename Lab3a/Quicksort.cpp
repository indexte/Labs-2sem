#include"Quicksort.h"
#include"Swap.h"

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
	array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot*/
int partition(Integers arr[], int low, int high)
{
	int pivot = arr[high].numbers;    // pivot 
	int i = (low - 1);  // Index of smaller element 

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or 
		// equal to pivot 
		if (arr[j].numbers <= pivot)
		{
			i++;    // increment index of smaller element 
			swapM(arr[i], arr[j]);
		}
	}
	swapM(arr[i + 1], arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */

void QuickSort(Integers arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		   at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before 
		// partition and after partition 
		QuickSort(arr, low, pi - 1);
		QuickSort(arr, pi + 1, high);
	}
}