#include <sys/types.h>

void insertion_sort(int arr[], size_t len)
{
	int i, j;
	int sort_target;

	for (i = 1; i < len; i++)
	{
		sort_target = arr[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (arr[j] > sort_target)
			{
				arr[j + 1] = arr[j];
			}
			else
				break;
		}
		arr[j + 1] = sort_target;
	}
}