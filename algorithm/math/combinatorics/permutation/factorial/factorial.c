#include <stdio.h>

int factorial(int n)
{
	int factorial = 1;
	while (n)
		factorial *= n--;

	return factorial;
}

int recur_factorial(int n)
{
	if (n == 0)
		return 1;

	return n * factorial(n - 1);
}