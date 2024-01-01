#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//int removeElement(int* nums, int numsSize, int val) 
//{
//	assert(nums != NULL);
//	int src = 0;
//	int dst = 0;
//
//	while (src < numsSize)
//	{
//
//		if (nums[src] == val)
//		{
//			src++;
//
//		}
//		else
//		{
//			nums[dst] = nums[src];
//
//			src++;
//			dst++;
//		}
//	}
//
//	return dst;
//}
//
//
//int main()
//{
//	int val = 3;
//	int nums[] = {2};
//	int sz = sizeof(nums) / sizeof(nums[0]);
//	int result = removeElement(nums, sz, val);
//	printf("%d", result);
//
//
//	return 0;
//}



#include <stdio.h>
//
//int removeDuplicates(int* nums, int numsSize) 
//{
//	int str1 = 1;
//	int str2 = 0;
//
//	while (str1 < numsSize)
//	{
//		if (nums[str1] != nums[str2])
//		{
//			if ((str2 - str1) != 1)
//			{
//				str2++;
//				nums[str2] = nums[str1];
//				str1++;
//			}
//			else
//			{
//				str2++;
//				str1++;
//			}
//		}
//		else 
//		{
//			str1++;
//		}
//	}
//
//
//	return str2;
//}
//#include <algorithm>
//
//
//int cmp(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//
//}
//
//void merge(int* nums1, int m, int* nums2, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		nums1[m + i] = nums2[i];
//	}
//	qsort(nums1, m + n, sizeof(int), cmp);
//}
//
//int main()
//{
//
//
//
//}



//void Func3(int N, int M)
//{
//	int count = 0;
//	for (int a = 0; a < M; a++)//时间复杂度为M
//	{
//		for (int k = 0; k < M; ++k)
//		{
//			++count;
//		}
//		for (int k = 0; k < N; ++k)//时间复杂度为N
//		{
//			++count;
//		}
//	}
////}
//
//void Func4(int N)
//{
//	int count = 0;
//	for (int k = 0; k < 100; ++k)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}


//const char* strchr(const char* str, int character)
//{
//	while (*str)
//	{
//		if (*str == character)
//			return str;
//
//		str++;
//	}
//	return NULL;
//}

//void BubbleSort(int* a, int n)
//{
//	for (size_t end = n; end > 0; --end)
//	{
//		int exchange = 0;
//		for (size_t i = 1; i < end; ++i)
//		{
//			if (a[i - 1] > a[i])
//			{
//				Swap(&a[i - 1], &a[i]);
//				exchange = 1;
//			}
//		}
//		if (exchange == 0)
//			break;
//	}
//}



//int BinarySearch(int* a, int n, int x)
//{
//	int begin = 0;
//	int end = n - 1;
//	while (begin <= end)
//	{
//		int mid = begin + ((end - begin) >> 1);
//		if (a[mid] < x)
//			begin = mid + 1;
//		else if (a[mid] > x)
//			end = mid - 1;
//		else
//			return mid;
//	}
//	return -1;
//}



long long Fac(size_t N)
{
	if (0 == N)
		return 1;
	return Fac(N - 1) * N;

}







long long Fib(size_t N)
{
	if (N < 3)
		return 1;
	return Fib(N - 1) + Fib(N - 2);
}


void BubbleSort(int* a, int n)
{
	for (size_t end = n; end > 0; --end)
	{
		int exchange = 0;
		for (size_t i = 1; i < end; ++i)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}
		if (exchange == 0)
			break;
	}
}



long long* Fibonacci(size_t n)
{
	if (n == 0)
		return NULL;
	long long* fibArray = (long long*)malloc((n + 1) * sizeof(long long));
	fibArray[0] = 0;
	fibArray[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
	}
	return fibArray;
}