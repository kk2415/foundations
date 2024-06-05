public class InsertionSort {
	public void insertionSort(int[] arr, int len) {
		int i;
		int j;
		int insertionData;

		for (i = 1; i < len; i++) {
			insertionData = arr[i];
			for (j = i - 1; j >= 0; j--) {
				if (arr[j] > insertionData) {
					arr[j + 1] = arr[j];
				} else {
					break;
				}
			}

			arr[j + 1] = insertionData;
		}
	}
}