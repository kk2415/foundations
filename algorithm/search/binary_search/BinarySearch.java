public class BinarySearch {
	public static int binarySearch(int[] arr, int len, int target) {
		int first_idx = 0;
		int last_idx = len - 1;
		int mid_idx = (first_idx + last_idx) / 2;

		while (first_idx <= last_idx) {
			if (arr[mid_idx] == target) {
				return mid_idx;
			} else if (arr[mid_idx] > target) {
				last_idx = mid_idx - 1;
			} else {
				first_idx = mid_idx + 1;
			}

			mid_idx = (first_idx + last_idx) / 2;
		}

		return -1;
	}
}