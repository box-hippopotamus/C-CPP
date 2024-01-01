#include "Sort.h"

// 排序实现的接口

//交换
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

// 插入排序 
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		//设前[0, end]是一个有序数列，将end+1插入
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}

		a[end + 1] = tmp;
	}
}

// 希尔排序
void ShellSort(int* a, int n)
{
	int gap = n;
	//gap > 1时是预排序，目的是让其接近有序
	//gap == 1是是最终插入排序，目的是让其有序
	while (gap > 1)
	{
		//gap = gap / 2;  但是这样要排序太多了，所以可以使用/3
		gap = gap / 3 + 1;//为了保证最后一次一定是1，此处要+1

		for (int i = 0; i < n - gap; i++)//此处限制在n-gap内，最后一次end + gap就不会越界
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}

// 选择排序
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;

	while (begin < end)
	{
		int mini = begin, maxi = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}

			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}

		Swap(&a[begin], &a[mini]);
		if (maxi == begin)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);

		begin++;
		end--;
	}
}

// 堆排序
void AdjustDwon(int* a, int n, int parent)
{
	int child = parent * 2 + 1;

	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child++;
		}

		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* a, int n)
{
	//建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDwon(a, n, i);
	}

	//排序
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		end--;
	}
}

// 冒泡排序
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		bool exchange = false;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				exchange = true;
			}
		}

		if (exchange == false)  
			break;
	}
}

// 快速排序递归实现
// 快速排序hoare版本
int GetMidi(int* a, int begin, int end)
{
	int midi = (begin + end) / 2;
	//选begin end midi 的中位数
	if (a[begin] < a[midi])
	{
		if (a[midi] < a[end])
			return midi;
		else if (a[begin] > a[end])
			return begin;
		else
			return end;
	}
	else
	{

	}
}

void PartSort1(int* a, int begin, int end) 
{
	if (begin >= end)
		return;

	 
	int left = begin, right = end;
	int keyi = begin; 

	while (left < right)
	{
		while (left < right && a[right] >= a[keyi])
		{
			right--;
		}

		while (left < right && a[left] <= a[keyi])
		{
			left++;
		}

		Swap(&a[left], &a[right]);
	}

	Swap(&a[left], &a[keyi]);
	keyi = left;
	PartSort1(a, begin, keyi - 1);
	PartSort1(a, keyi + 1, end);
}

// 快速排序挖坑法
int PartSort2(int* a, int left, int right)
{

}

// 快速排序前后指针法
int PartSort3(int* a, int left, int right)
{

}

void QuickSort(int* a, int left, int right)
{

}

// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right)
{

}

// 归并排序递归实现
void MergeSort(int* a, int n)

{}

// 归并排序非递归实现
void MergeSortNonR(int* a, int n)
{

}

// 计数排序
void CountSort(int* a, int n)
{

}

// 测试排序的性能对比
void TestOP()
{
	srand(time(0));
	const int N = 10000000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	int* a7 = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand() * rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
	}

	//clock函数返回从系统启动到执行此语句的毫秒数
	//int begin1 = clock();
	//InsertSort(a1, N);
	//int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	//int begin3 = clock();
	//SelectSort(a3, N);
	//int end3 = clock();

	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();

	int begin5 = clock();
	PartSort1(a5, 0, N - 1);
	int end5 = clock();

	int begin6 = clock();
	MergeSort(a6, N);
	int end6 = clock();

	//int begin7 = clock();
	//BubbleSort(a7, N);
	//int end7 = clock();

	//printf("InsertSort:%d\n", end1 - begin1);//做启动时间与结束时间的差值,得出此排序的时间
	printf("ShellSort:%d\n", end2 - begin2);
	//printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("QuickSort:%d\n", end5 - begin5);
	printf("MergeSort:%d\n", end6 - begin6);
	//printf("BubbleSort:%d\n", end7 - begin7);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
}