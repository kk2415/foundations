#include <stdio.h>

void selection_sort(int arr[], size_t len)
{
	int i, j;
	int min_idx;
	int temp;

	for (i = 0; i < len - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < len; j++)
		{
			if (arr[min_idx] > arr[j])
			{
				min_idx = j;
			}
		}

		temp = arr[i];
		arr[i] = arr[min_idx];
		arr[min_idx] = temp;
	}
}