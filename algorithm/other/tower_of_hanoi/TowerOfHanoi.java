public class TowerOfHanoi {

	public static void towerOfHanoi(int n, String from, String by, String to) {
		if (n == 1) {
			System.out.printf("원반 1을 %s 막대에서 %s 막대로 이동\n", from, to);
		} else {
			towerOfHanoi(n - 1, from, to, by);
			System.out.printf("원반 %d을(를) %s 막대에서 %s 막대로 이동\n", n, from, to);
			towerOfHanoi(n - 1, by, from, to);
		}
	}
}