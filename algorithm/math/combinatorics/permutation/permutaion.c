unsigned long permutaion(int n, int r)
{
	unsigned long permutaion = 1;
	for (int i = 0; i < r; i++)
	{
		permutaion *= (n - i);
	}

	return permutaion;
}