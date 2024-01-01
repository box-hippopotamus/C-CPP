#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>

//void sort(int arr[], int n)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < n - 1; i++)
//	{
//		for (j = 0; j < n - 1; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int t = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = t;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int m, n;
//	int arr1[6];
//	int arr2[8];
//
//	for (m = 0; m < 6; m++)
//	{
//		scanf("%d", &arr1[m]);
//	}
//
//	for (m = 0; m < 8; m++)
//	{
//		scanf("%d", &arr2[m]);
//	}
//
//	sort(arr1, 6);
//	sort(arr2, 8);
//
//	for (m = 0; m < 6; m++)
//	{
//		for (n = 0; n < 8; n++)
//		{
//			if (arr1[m] == arr2[n])
//			{
//				printf("%d\n", arr1[m]);
//			}
//		}
//
//	}
//
//	return 0;
//}

//冒泡排序
#include <stdio.h>

void sort(int arr[], int sz)
{
	int m, n;
	for (m = 0; m < (sz-1); m++)//计算趟数
	{
		int flag = 1;//假设没有进行交换
		for (n = 0; n < (sz - 1 - m); n++)//计算每趟交换次数
		{
			if (arr[n] > arr[n + 1])
			{
				//交换
				int tmp = arr[n];
				arr[n] = arr[n + 1];
				arr[n + 1] = tmp;
				flag = 0;//证明这一趟进行了交换
			}

		}
		if (flag != 0)//当if成立，说明这一趟排没有交换数据，已经排序完成，直接跳出
		{
			break;
		}
	}

}

void print(int* arr, int sz)
{
	int m;
	for (m = 0; m < sz; m++)
	{
		printf("%d ", arr[m]);
	}
}

int main()
{
	int arr[10];
	int i;
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < sz; i++)
	{
		scanf("%d", &arr[i]);
	}

	sort(arr, sz);
	print(arr, sz); 

	return 0;
}