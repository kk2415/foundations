public class BubbleSort {
	public void bubbleSort(int[] arr, int len) {
		int temp;

		for (int i = 0; i < len - 1; i++) {
			for (int j = 0; j < (len - 1) - i; j++) {
				if (arr[j] > arr[j + 1]) {
					temp = arr[j + 1];
					arr[j + 1] = arr[j];
					arr[j] = temp;
				}
			}
		}
	}
}