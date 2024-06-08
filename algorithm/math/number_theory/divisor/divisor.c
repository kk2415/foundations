#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 비교 함수 (오름차순 정렬)
int compare(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int *find_divisors(int n)
{
	int *divisors = (int *)malloc(sizeof(int) * n);
	int index = 0;
	int limit = sqrt(n);

	for (int i = 1; i <= limit; i++)
	{
		if (n % i == 0)
		{
			divisors[index++] = i;
			if (n / i != i)
				divisors[index++] = n / i;
		}
	}

	qsort(divisors, index, sizeof(int), compare);

	return divisors;
}