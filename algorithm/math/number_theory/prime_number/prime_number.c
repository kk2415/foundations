#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool poor_primality_test(unsigned long n)
{
	for (unsigned long i = 2; i < n; i++)
	{
		if (n % i == 0)
			return false;
	}

	return true;
}

bool simple_primality_test(unsigned long n)
{
	unsigned long limit = (unsigned long)sqrt(n) + 1;

	for (unsigned long i = 2; i < limit; i++)
	{
		if (n % i == 0)
			return false;
	}

	return true;
}