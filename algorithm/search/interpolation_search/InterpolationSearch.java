public class InterpolationSearch {

	public Integer interpolationSearch(Integer[] arr, Integer first, Integer last, Integer target) {
		if (target < arr[first] || target > arr[last])
			return -1;

		Integer pos = first + (int)((double)(target - arr[first]) / (arr[last] - arr[first]) * (last - first));
		if (arr[pos] == target)
			return pos;
		else if (arr[pos] > target)
			return interpolationSearch(arr, first, pos - 1, target);
		else 
			return interpolationSearch(arr, pos + 1, last, target);
	}
}