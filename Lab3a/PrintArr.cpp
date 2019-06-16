#include "PrintArr.h"

using std::cout;
using std::endl;

void PrintArr(Integers array[], int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i].numbers << ", ";
	}
	cout << endl;
}