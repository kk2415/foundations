#include <stdio.h>

void swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int mid_of_three(int arr[], int left, int right)
{
	int samples[] = {left, (left + right) / 2, right};

	if (arr[samples[0]] > arr[samples[1]])
		swap(samples, 0, 1);

	if (arr[samples[1]] > arr[samples[2]])
		swap(samples, 1, 2);

	if (arr[samples[0]] > arr[samples[1]])
		swap(samples, 0, 1);

	return samples[1];
}

int partition(int arr[], int left, int right)
{
	int mid = mid_of_three(arr, left, right);
	int pivot = arr[mid];
	int low = left + 1;
	int high = right;

	swap(arr, left, mid);
	while (low <= high)
	{
		while (pivot >= arr[low] && low <= right)
			low++;

		while (pivot <= arr[high] && high >= (left + 1))
			high--;

		if (low <= high)
			swap(arr, low, high);
	}

	swap(arr, left, high);
	return high;
}

void quick_sort(int arr[], int left, int right)
{
	if (left < right)
	{
		int pivot = partition(arr, left, right);
		quick_sort(arr, left, pivot - 1);
		quick_sort(arr, pivot + 1, right);
	}
}