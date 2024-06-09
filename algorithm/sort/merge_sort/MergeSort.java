public class MergeSort {

	private static void conquer(Integer[] arr, Integer left, Integer mid, Integer right) {
		Integer leftArrIdx = left;
		Integer rightArrIdx = mid + 1;
		Integer[] sortArr = new Integer[arr.length];

		Integer sIdx = left;
		while (leftArrIdx <= mid && rightArrIdx <= right) {
			if (arr[leftArrIdx] < arr[rightArrIdx]) {
				sortArr[sIdx] = arr[leftArrIdx++];
			} else {
				sortArr[sIdx] = arr[rightArrIdx++];
			}
			sIdx++;
		}

		if (leftArrIdx > mid) {
			for (int i = rightArrIdx; i <= right; i++, sIdx++) {
				sortArr[sIdx] = arr[i];
			}
		} else {
			for (int i = leftArrIdx; i <= mid; i++, sIdx++) {
				sortArr[sIdx] = arr[i];
			}
		}

		for (int i = left; i <= right; i++)
			arr[i] = sortArr[i];
	}

	public static void mergeSort(Integer[] arr, Integer left, Integer right) {
		if (left >= right) {
			return;
		}

		//분할
		Integer mid = (left + right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);

		//병합
		conquer(arr, left, mid, right);
	}

	public static void main(String[] args) {
		Integer[] arr1 = {54, 1, 23, 9, 0, 7, 11};
		Integer[] arr2 = {1, 1, 1, 1, 1, 1, 1};
		Integer[] arr3 = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
		mergeSort(arr3, 0, arr3.length - 1);

		for (int i = 0; i < arr3.length; i++) {
			System.out.println(arr3[i]);
		}
	}
}