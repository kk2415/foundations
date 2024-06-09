int gcd(int a, int b)
{
	while (a >= 1 && b >= 1)
	{
		if (a >= b)
			a = a % b;
		else
			b = b % a;
	}

	if (a > 1)
		return a;
	return b;
}

int recur_gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return recur_gcd(b, a % b);
}