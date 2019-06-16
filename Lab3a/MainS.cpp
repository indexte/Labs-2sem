#include<iostream>
#include"Integers.h"
#include"BubbleSort.h"
#include"Quicksort.h"
#include"MergeSort.h"
#include"PrintArr.h"
#include"RandomArr.h"
#include<algorithm>

using std::cout;
using std::endl;


int main() {
	//fill array
	const int SIZE = 100;

	Integers array[SIZE];
	for (int i = 0; i < SIZE; i++) {
		array[i].numbers = i;
	}

	//randomize array

	Random(array, SIZE);

	//print array
	cout << "Randomized array" << endl;

	PrintArr(array, SIZE);

	//----------------------------------------

	//bubble sort
	cout << "Bubble sort: " << endl;

	BubbleSort(array, SIZE);

	PrintArr(array, SIZE);

	Random(array, SIZE); //array randomization after each sorting

	//quick sort
	cout << "Quick sort: " << endl;

	QuickSort(array, 0, SIZE - 1);

	PrintArr(array, SIZE);

	Random(array, SIZE); //array randomization after each sorting

	//merge sort
	cout << "Merge sort: " << endl;

	MergeSort(array, SIZE);
	
	PrintArr(array, SIZE);

	Random(array, SIZE); //array randomization after each sorting

	//combined sort
	cout << "Combined sort (Bubble sort (size less than 200), Quick sort (size more than 200)): " << endl;

	if (SIZE <= 200) {
		BubbleSort(array, SIZE);
	}
	else {
		QuickSort(array, 0, SIZE - 1);
	}

	PrintArr(array, SIZE);

	Random(array, SIZE); //array randomization after each sorting

	//STL sort
	cout << "STL sort: " << endl;

	std::sort(array, array + SIZE, [](const Integers &i1, const Integers &i2) {
		return i1.numbers < i2.numbers;
	});

	PrintArr(array, SIZE);

	//----------------------------------------

	return 0;
}