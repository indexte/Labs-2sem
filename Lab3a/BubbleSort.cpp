#include "BubbleSort.h"

void BubbleSort(Integers array[], int size) {

	for (int i = 0; i < size ; i++) {
		for (int j = 0; j < (size - 1); j++) {
			if (array[i].numbers < array[j].numbers)
				swapM(array[i], array[j]);
		}
	}
}
