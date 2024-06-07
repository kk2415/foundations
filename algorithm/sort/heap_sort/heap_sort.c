#include <stdio.h>
#include <string.h>
#include <glib.h>

int compare_ints(gconstpointer a, gconstpointer b, gpointer user_data)
{
	return (*(const int *)a - *(const int *)b);
}

void heap_sort(int arr[], size_t len)
{
	int temp_arr[len];
	size_t size = sizeof(temp_arr);
	memcpy(temp_arr, arr, size);

	GQueue *priority_queue = g_queue_new();
	for (int i = 0; i < len; i++)
	{
		g_queue_insert_sorted(priority_queue, &temp_arr[i], compare_ints, NULL);
	}

	for (int i = 0; i < len; i++)
	{
		int *data = (int *)g_queue_pop_head(priority_queue);
		arr[i] = *data;
	}

	g_queue_free(priority_queue);
}