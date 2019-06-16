#include"Swap.h"

void swapM(Integers & x, Integers & y)
{
	Integers temp = x;
	x = y;
	y = temp;
}