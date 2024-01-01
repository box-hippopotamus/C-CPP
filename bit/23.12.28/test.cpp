#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

long long minCost(int* nums, int numsSize, int x)
{
	long long f[numsSize];
	long long count = 0;

	for (long long k = 0; k < numsSize; k++)
	{
		long long sum = 0;
		for (long long j = 0; j < numsSize; j++)
		{
			f[j] = k == 0 ? nums[j] : fmin(f[j], nums[(j + k) % numsSize]);
			sum += f[j];
		}
		count = k == 0 ? sum : fmin(count, sum + x * k);
	}

	return count;
}
int main()
{

	return 0;
}