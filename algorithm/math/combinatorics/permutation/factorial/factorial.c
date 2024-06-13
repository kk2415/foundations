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
	if (n <= 1)
		return 1; // 0! = 1 and 1! = 1

	return n * factorial(n - 1);
}