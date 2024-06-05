#include <sys/types.h>
#include <stdio.h>

void bubble_sort(int arr[], size_t len)
{
	int temp;

	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < (len - i) - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}