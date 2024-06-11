#include <stdio.h>

int factorial(int n)
{
	int factorial = 1;
	while (n)
		factorial *= n--;

	return factorial;
}