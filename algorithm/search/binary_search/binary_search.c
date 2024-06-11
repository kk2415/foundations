#include <sys/types.h>

ssize_t binary_search(int arr[], size_t len, int target)
{
	size_t first_idx = 0;
	size_t last_idx = len - 1;
	size_t mid = (first_idx + last_idx) / 2;

	while (first_idx <= last_idx)
	{
		if (arr[mid] == target)
		{
			return mid;
		}
		else
		{
			if (arr[mid] > target)
				last_idx = mid - 1;
			else
				first_idx = mid + 1;
		}
		mid = (first_idx + last_idx) / 2;
	}

	return -1;
}

ssize_t recur_binary_search(int arr[], size_t first, size_t last, int target)
{
	if (first > last)
		return -1;

	int mid = (first + last) / 2;
	if (arr[mid] == target)
		return mid;
	else if (arr[mid] > target)
		return recur_binary_search(arr, first, mid - 1, target);
	else
		return recur_binary_search(arr, mid + 1, last, target);
}