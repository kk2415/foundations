import java.util.stream.*;
import java.math.*;

public class Permutation {

	public static BigInteger permutation(int n, int r) {
		return IntStream.rangeClosed((n - r) + 1, n)
			.mapToObj(BigInteger::valueOf)
			.reduce(BigInteger.ONE, BigInteger::multiply);
	}
}