#include"RandomArr.h"
#include"Swap.h"
#include<iostream>

void Random(Integers array[], int size) {
	for (size_t i = 0; i < size; i++) {
		swapM(array[i], array[rand() % size]);
	}
}