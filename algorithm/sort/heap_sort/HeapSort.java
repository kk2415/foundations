import java.util.PriorityQueue;
import java.util.stream.*;
import java.util.Arrays;

public class HeapSort {

	public void heapSort(Integer[] arr, Integer len) {
		PriorityQueue<Integer> heap = new PriorityQueue<>();

		Arrays.stream(arr).forEach(e -> heap.offer(e));

		for (int i = 0; i < len; i++) {
			arr[i] = heap.poll();
		}
	}
}