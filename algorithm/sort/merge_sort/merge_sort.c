#include <stdio.h>
#include <stdlib.h>

void conquer(int arr[], size_t left, size_t mid, size_t right)
{
	size_t left_arr_idx = left;
	size_t right_arr_idx = mid + 1;
	int *sort_arr = (int *)malloc(sizeof(int) * (right + 1));

	int s_idx = left;
	while (left_arr_idx <= mid && right_arr_idx <= right)
	{
		if (arr[left_arr_idx] < arr[right_arr_idx]) // 오름차순 정렬
			sort_arr[s_idx] = arr[left_arr_idx++];
		else
			sort_arr[s_idx] = arr[right_arr_idx++];
		s_idx++;
	}

	if (left_arr_idx > mid)
	{
		for (int i = right_arr_idx; i <= right; i++, s_idx++)
			sort_arr[s_idx] = arr[i];
	}
	else
	{
		for (int i = left_arr_idx; i <= mid; i++, s_idx++)
			sort_arr[s_idx] = arr[i];
	}

	for (int i = left; i <= right; i++)
		arr[i] = sort_arr[i];

	free(sort_arr);
}

void merge_sort(int arr[], size_t left, size_t right)
{
	if (left >= right)
	{
		return;
	}

	// 분할
	size_t mid = (left + right) / 2;
	merge_sort(arr, left, mid);
	merge_sort(arr, mid + 1, right);

	// 정복
	conquer(arr, left, mid, right);
}