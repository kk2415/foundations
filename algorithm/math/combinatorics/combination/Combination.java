import java.util.stream.*;
import java.math.*;

public class Combination {

	public static BigInteger factorial(int n) {
		return IntStream.rangeClosed(1, n)
			.mapToObj(BigInteger::valueOf)
			.reduce(BigInteger.ONE, BigInteger::multiply);
	}

	public static BigInteger permutation(int n, int r) {
		return IntStream.rangeClosed((n - r) + 1, n)
			.mapToObj(BigInteger::valueOf)
			.reduce(BigInteger.ONE, BigInteger::multiply);
	}

	public static BigInteger combination(int n, int r) {
		return permutation(n, r).divide(factorial(r));
	}
}