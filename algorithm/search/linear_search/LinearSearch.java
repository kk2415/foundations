public class LinearSearch {

	public int linearSearch(int[] arr, int len, int target) {
		for (int i = 0; i < len; i++) {
			if (arr[i] == target) {
				return i;
			}
		}

		return -1;
	}
}