#include <glib.h>
#include <stdio.h>
#include <math.h>

#define BUCKET_NUM 10

void radix_sort(int arr[], int arr_len, int max_index)
{
	GQueue *buckets[BUCKET_NUM];
	int bi;
	int ai;
	int number;
	int digit;

	for (bi = 0; bi < BUCKET_NUM; bi++)
		buckets[bi] = g_queue_new();

	for (int i = 0; i < max_index; i++)
	{
		for (ai = 0; ai < arr_len; ai++)
		{
			digit = (arr[ai] / (int)pow(10, i)) % 10;
			g_queue_push_tail(buckets[digit], GINT_TO_POINTER(arr[ai]));
		}

		for (bi = 0, ai = 0; bi < BUCKET_NUM; bi++)
		{
			while (!g_queue_is_empty(buckets[bi]))
			{
				number = GPOINTER_TO_INT(g_queue_pop_head(buckets[bi]));
				arr[ai++] = number;
			}
		}
	}

	for (int bi = 0; bi < BUCKET_NUM; bi++)
		g_queue_free(buckets[bi]);
}

void main()
{
	int arr[] = {13, 212, 14, 7141, 10987, 6, 15};
	int len = sizeof(arr) / sizeof(int);

	radix_sort(arr, len, 5);

	for (int i = 0; i < len; i++)
	{
		printf("%d, ", arr[i]);
	}
	printf("\n");
}