#include <stdio.h>
#include <sys/types.h>

ssize_t interpolation_search(int arr[], size_t first, size_t last, int target)
{
	if (arr[first] > target || arr[last] < target)
		return -1;

	int pos = ((double)(target - arr[first]) / (arr[last] - arr[first]) * (last - first)) + first;
	if (arr[pos] == target)
		return pos;
	else if (arr[pos] > target)
		return interpolation_search(arr, first, pos - 1, target);
	else
		return interpolation_search(arr, pos + 1, last, target);
}

void main()
{
	int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
	size_t size = sizeof(arr) / sizeof(int);
	ssize_t idx = interpolation_search(arr, 0, size - 1, 20);

	printf("idx: %d\n", idx);
}