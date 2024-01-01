#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>


//int findPeakElement(int* nums, int numsSize) 
//{
//	if (numsSize == 1)
//	{
//		return 0;
//	}
//
//	int cur = 0;
//
//	if (nums[cur] > nums[cur + 1])
//	{
//		return cur;
//	}
//
//	cur++;
//
//	while (cur < numsSize)
//	{
//		if (cur + 1 < numsSize && nums[cur] > nums[cur - 1]
//			&& nums[cur + 1] < nums[cur])
//		{
//			return cur;
//		}
//		cur++;
//	}
//
//	return cur - 1;
//}


int findPeakElement(int* nums, int numsSize)
{
	int cur = numsSize / 2;

	if (numsSize == 1)
	{
		return cur;
	}

	if (numsSize == 2)
	{
		int cur = nums[0] > nums[1] ? 0 : 1;
		return cur;
	}

	while (cur < numsSize)
	{
		if (cur == numsSize - 1)
		{
			if (nums[cur - 1] > nums[cur])
				cur = cur / 2;
			else
				return cur;
		}

		if (cur == 0)
		{
			if (nums[cur + 1] > nums[cur])
				cur = cur + (numsSize - cur) / 2;
			else
				return cur;
		}

		if (nums[cur - 1] < nums[cur] && nums[cur + 1] < nums[cur])
			return cur;

		if (nums[cur - 1] > nums[cur])
			cur = cur / 2;

		if (nums[cur + 1] > nums[cur])
			cur = cur + (numsSize - cur) / 2;
	}
	return 0;
}

int peakIndexInMountainArray(int* arr, int arrSize)
{
	int left = 0;
	int right = arrSize - 1;
	int ans = 0;
	int mid = (left + right) / 2;

	while (left <= right)
	{
		mid = (left + right) / 2;
		if (arr[mid] > arr[mid + 1])
		{
			ans = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;

	}

	return ans;
}



int comp(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

int* findMissingAndRepeatedValues(int** grid, int gridSize, int* gridColSize, int* returnSize)
{
	int* ans = (int*)malloc(sizeof(int) * 2);

	int n = gridSize * gridSize;

	int p[n];
	int cur = 0;
	for (int i = 0; i < gridSize; i++)
	{
		for (int j = 0; j < gridSize; j++)
		{
			p[cur++] = grid[i][j];
		}
	}

	qsort(p, n, sizeof(int), comp);

	int a = 0;
	int b = 0;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		count += p[i];
		if (i + 1 < n && p[i] == p[i + 1])
			a = p[i];
	}

	int sum = n * (1 + n) / 2;

	b = sum - count + a;

	ans[0] = a;
	ans[1] = b;

	*returnSize = 2;

	return ans;
}

int** divideArray(int* nums, int numsSize, int k, int* returnSize, int** returnColumnSizes)
{
	int** ans = (int**)malloc(sizeof(int*) * (numsSize / 3 + 1));

	for (int i = 0; i < (numsSize / 3 + 1); i++) 
	{
		ans[i] = (int*)malloc(sizeof(int) * 3);
	}

	qsort(nums, numsSize, sizeof(int), comp);

	int j = 0;
	for (int i = 0; i < numsSize - 3; i += 3)
	{
		if (nums[i + 2] - nums[i] > k)
		{
			free(ans);

			*returnSize = 0;
			*returnColumnSizes = NULL;
			return NULL;
		}
		else
		{
			ans[j][0] = nums[i];
			ans[j][1] = nums[i + 1];
			ans[j][2] = nums[i + 2];
			j++;
		}
	}

	*returnSize = j;

	*returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));

	for (int i = 0; i < (*returnSize); i++) 
	{
		(*returnColumnSizes)[i] = 3;
	}

	return ans;
}


long long minimumCost(int* nums, int numsSize) 
{
	long long sum = 0;
	for (int i = 0; i < numsSize; i++)
	{
		sum += nums[i];
	}

	long long avg = sum / numsSize;

}


int main()
{

	return 0;
}