#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//int bin_search(int arr[], int left, int right, int key)
//{
//
//	while (left <= right)
//	{
//	
//		int mid = (left + right) / 2;
//		int found = 0;
//		if (arr[mid] == key)
//		{
//			return mid;
//		}
//		else if (arr[mid] < key)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > key)
//		{
//			right = mid - 1;
//		}
//	}
//	return -1;
//}
////
//
//int main()
//{
//	int a;
//	int arr[10];
//	scanf("%d", &a);
//
//	return 0;
//}

//#include<stdio.h>
//#include<math.h>
//
//int main()
//{
//	int i;
//	for (i=1;i< 100000;i++)
//	{
//		int count = 0;
//		int num = i;
//		//求几位数
//		while (num)
//		{
//			num = num / 10;
//			count++;
//		}
//
//		num = i;
//		int sum = 0;
//		while (num)
//		{
//			sum += pow(num % 10, count);
//			num = num / 10;
//		}
//
//		if (sum == i)
//		{
//			printf("%d\n", i);
//		}
//	}
//
//	return 0;
//}
//
//#include<stdio.h>
//
//int main() 
//{
//	int a, i;
//	scanf("%d", &a);
//	int sum = a;
//	int x = 0;
//	for (i = 1; i <= 5; i++)
//	{
//		x = x * 10 + a;
//		sum += x;
//	}
//
//	printf("%d", sum);
//
//	return 0;
//}
//
//#include<stdio.h>
//
//int pow(int n, int k)
//{
//	if(k>1)
//	    return n*pow(n, k - 1);
//	if (k == 1)
//		return n;
//}
//
//int main()
//{
//	int n, k;
//	scanf("%d %d", &n, &k);
//	int a = pow(n, k);
//	printf("%d", a);
//
//	return 0;
//}
//
//#include<stdio.h>
//
//int DigitSum(int n)
//{
//	if (n > 9)
//		return n % 10 + DigitSum(n / 10);
//	else if (0 <= n <= 9)
//		return n;
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int a = DigitSum(n);
//	printf("%d", a);
//
//	return 0;
//}

//#include<stdio.h>
//int sum(int n)
//{
//	if (n > 1)
//		return n * sum(n - 1);
//	if (n == 1)
//		return n;
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int num = sum(n);
//	printf("%d", num);
//	return 0;
//}
//
//////
//
//
//#include<stdio.h>
//
//int main()
//{
//	int a;
//	int sum = 1;
//	scanf("%d", &a);
//	int i;
//	for (i = 0; i < a; i++)
//	{
//		sum = sum * (a - i);
//	}
//	printf("%d", sum);
//	return 0;
//}

#include<stdio.h>

int flact(int n)
{
	if (n > 9)
	{
		flact(n / 10);
		int a = n % 10;
		printf("%d ", a);
	}
	else if (0<=n<=9)
	{
		printf("%d ", n);
	}
	return 0;
}

int main()
{
	int  n;
	scanf("%d", &n);
	flact(n);
	return 0;
}
