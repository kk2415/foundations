#include <sys/types.h>

ssize_t linear_search(int arr[], size_t len, int target)
{
	for (int i = 0; i < len; i++)
	{
		if (arr[i] == target)
		{
			return i;
		}
	}

	return -1;
}