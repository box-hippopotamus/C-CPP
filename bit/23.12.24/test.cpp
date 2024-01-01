#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

long long minimumPerimeter(long long neededApples) 
{
	long long n = 0;
	long long c = 1;
	long long apples = 0;

	while (apples < neededApples)
	{
		n++;
		apples = 2 * n * (n + 1) * (n + 2);
		c = 8 * n;
	}

	return c;
}


int main()
{
	return 0;
}