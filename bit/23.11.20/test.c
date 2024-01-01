#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int maxSubArray(int* nums, int numsSize) 
{
	int num1 = 0;
	int num2 = 0;

	int cur = 0;
	int tail = 0;

	while (numsSize--)
	{
		num1 = nums[tail] + num1;
		tail++;
	}


}

int main()
{
	
	return 0;
}