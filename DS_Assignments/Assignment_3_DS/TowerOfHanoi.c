#include <stdio.h>

void printmove(int start, int end)
{
	printf("%d -> %d\n", start, end);
}

int othertower(int start, int end)
{
	return 6-(start+end); 
}

void hanoi(int n, int start, int end)
{
	if (n==1)
	{
		printmove(start,end);
	}
	else
	{
		hanoi(n-1, start, othertower(start,end));
		printmove(start,end);
		hanoi(n-1, othertower(start,end), end);
	}
}

int main()
{
	hanoi(10,3,1);
	return 0;
}