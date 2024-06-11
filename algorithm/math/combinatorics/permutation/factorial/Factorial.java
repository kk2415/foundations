import java.math.*;
import java.util.stream.*;

public class Factorial {

	public static int factorial(int n) {
		return IntStream.rangeClosed(1, n)
			.reduce(1, (int a, int b) -> a * b);
	}

	public static BigInteger large_factorial(int n) {
		return IntStream.rangeClosed(1, n)
			.mapToObj(BigInteger::valueOf)
			.reduce(BigInteger.ONE, BigInteger::multiply);
	}
}