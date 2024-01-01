#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct turn {
	int profit;
	int turning;
};

int minOperationsMaxProfit(int* customers, int customersSize, int boardingCost, int runningCost)
{
	struct turn  max, accumlate;
	int remain;

	if (customers[0] >= 4)
	{
		accumlate.profit = 4 * boardingCost - runningCost;
		accumlate.turning = 1;
		remain = customers[0] - 4;
		max = accumlate;
	}
	else
	{
		accumlate.profit = customers[0] * boardingCost - runningCost;
		accumlate.turning = 1;
		remain = 0;
		max = accumlate;
	}

	for (int i = 1; i < customersSize; i++)
	{
		if (customers[i] + remain >= 4)
		{
			accumlate.profit = 4 * boardingCost - runningCost + accumlate.profit;
			accumlate.turning++;
			remain = remain + customers[i] - 4;
		}
		else
		{
			accumlate.profit = (remain + customers[i]) * boardingCost - runningCost + accumlate.profit;
			accumlate.turning++;
			remain = 0;
		}
		max = max.profit >= accumlate.profit ? max : accumlate;
	}

	while (remain > 0)
	{
		accumlate.profit = remain >= 4 ? 4 * boardingCost - runningCost + accumlate.profit : remain * boardingCost - runningCost + accumlate.profit;
		accumlate.turning++;
		max = max.profit >= accumlate.profit ? max : accumlate;

		remain -= 4;
	}

	return max.profit > 0 ? max.turning : -1;
}

int main()
{
	int customers[3] = { 10, 9, 6 };
	int bo = 6;
	int run = 4;
	int a = minOperationsMaxProfit(customers, 3, bo, run);
	printf("%d", a);
	return 0;
}