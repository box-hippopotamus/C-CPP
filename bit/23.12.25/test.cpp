#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* numOfBurgers(int tomatoSlices, int cheeseSlices, int* returnSize)
{
	int* ans = (int*)malloc(sizeof(int) * 2);

	float jumbo = 0;
	float small = 0;

	jumbo = (tomatoSlices - 2 * cheeseSlices) / 2;
	small = cheeseSlices - jumbo;

	if (tomatoSlices % 2 != 0 || jumbo < 0 || small < 0)
	{
		*returnSize = 0;
		return ans;
	}

	ans[0] = (int)jumbo;
	ans[1] = (int)small;
	*returnSize = 2;

	return ans;
}

int main() {


	return 0;
}