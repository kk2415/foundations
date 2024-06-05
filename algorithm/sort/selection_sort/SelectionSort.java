public class SelectionSort {

	public void selectionSort(int[] arr, int len) {
		int temp;
		int min_idx;

		for (int i = 0; i < len - 1; i++) {
			min_idx = i;
			for (int j = i + 1; j < len; j++) {
				if (arr[min_idx] > arr[j]) {
					min_idx = j;
				}
			}

			temp = arr[i];
			arr[i] = arr[min_idx];
			arr[min_idx] = temp;
		}
	}
}