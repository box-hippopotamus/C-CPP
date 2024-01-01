#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//void rotate(int* nums, int numsSize, int k) 
//{
//	int arr[k];
//	int i = 0;
//	for (i = 0; i < k; i++)
//	{
//		arr[i] = nums[i];
//
//	}
//	for (i = numsSize; i > 0; i--)
//	{
//		if (i < numsSize - k)
//			nums[i] = arr[i];
//		if (i >= numsSize - k)
//			nums[k + i] = nums[k];
//	}
//
//}
//
//int main()
//{
//	return 0;
//}

#include <stdio.h>

int findout(int* nums,int numssize) 
{
	int n = numssize;
	int a = 0;
	int i = 0;

	for (i = 0; i < numssize; i++)
	{
		a ^= nums[i];
	}

	for (i = 0; i <= numssize; i++)
	{
		a ^= i;
	}

	return a;
}

int main()
{
	int nums[10] = { 0,1,2,3,5,6,7,8,9,10 };
	int sz = sizeof(nums) / sizeof(nums[0]);
	printf("%d", findout(nums, sz));
	return 0;
}