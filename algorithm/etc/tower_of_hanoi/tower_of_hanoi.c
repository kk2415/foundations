#include <stdio.h>

void tower_of_hanoi(int n, char from, char by, char to)
{
	if (n == 1)
	{
		printf("원반1을 %c 막대에서 %c 막대로 이동\n", from, to);
	}
	else
	{
		tower_of_hanoi(n - 1, from, to, by);
		printf("원반%d을(를) %c 막대에서 %c 막대로 이동\n", n, from, to);
		tower_of_hanoi(n - 1, by, from, to);
	}
}

void main()
{
	tower_of_hanoi(3, 'A', 'B', 'C');
}