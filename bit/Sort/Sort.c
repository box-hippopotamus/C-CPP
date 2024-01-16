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

////霍尔取第一个节点做key
//void PartSort1(int* a, int begin, int end)
//{
//	if (begin >= end)
//		return;
//
//	int left = begin, right = end;
//	int keyi = begin;
//
//	while (left < right)
//	{
//		while (left < right && a[right] >= a[keyi])
//		{
//			right--;
//		}
//
//		while (left < right && a[left] <= a[keyi])
//		{
//			left++;
//		}
//
//		Swap(&a[left], &a[right]);
//	}
//
//	Swap(&a[left], &a[keyi]);
//	keyi = left;
//	PartSort1(a, begin, keyi - 1);
//	PartSort1(a, keyi + 1, end);
//}

//三数取中
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
		if (a[end] < a[midi])
			return midi;
		else if (a[end] > a[begin])
			return begin;
		else
			return end;
	}
}

//霍尔三数取中快排 + 小区间优化
int PartSort1(int* a, int begin, int end)
{
	int midi = GetMidi(a, begin, end);
	Swap(&a[midi], &a[begin]);//将取出的中间值放在首位做key

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

	return keyi;
}

// 快速排序挖坑法
int PartSort2(int* a, int begin, int end)
{
	int midi = GetMidi(a, begin, end);
	Swap(&a[midi], &a[begin]);

	int key = a[begin];
	int hole = begin;

	while (begin < end)
	{
		//右边找小，填到右左边的坑
		while (begin < end && a[end] >= key)
		{
			end--;
		}

		a[hole] = a[end];
		hole = end;

		//左边找大，填到右边的坑
		while (begin < end && a[begin] <= key)
		{
			begin++;
		}

		a[hole] = a[begin];
		hole = begin;
	}

	a[hole] = key;
	return hole;
}

// 快速排序前后指针法 
int PartSort3(int* a, int begin, int end)
{
	int midi = GetMidi(a, begin, end);
	Swap(&a[midi], &a[begin]);

	int prev = begin;
	int cur = prev + 1;

	int keyi = begin;

	while (cur <= end)
	{
		if (a[cur] < a[keyi] && ++prev != cur)//避免自己和自己交换
			Swap(&a[prev], &a[cur]);

		cur++;
	}

	Swap(&a[prev], &a[keyi]);
	keyi = prev;

	return keyi;
}

void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
		return;

	//int keyi = PartSort1(a, begin, end);//霍尔
	//int keyi = PartSort2(a, begin, end);//挖坑法
	int keyi = PartSort3(a, begin, end);//前后指针法
	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);
}

// 快速排序 非递归实现
void QuickSortNonR(int* a, int begin, int end)
{
	Stack s;
	StackInit(&s);
	StackPush(&s, end);
	StackPush(&s, begin);

	while (!StackEmpty(&s))
	{
		int left = StackTop(&s);
		StackPop(&s);
		int right = StackTop(&s);
		StackPop(&s);

		int keyi = PartSort3(a, left, right);
		if (left < keyi - 1)
		{
			StackPush(&s, keyi - 1);
			StackPush(&s, left);
		}

		if (keyi + 1 < right)
		{
			StackPush(&s, right);
			StackPush(&s, keyi + 1);
		}
	}
	StackDestroy(&s);
}



// 归并排序递归实现
void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;

	int mid = (begin + end) / 2;
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);

	//归并
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;

	int i = begin;//使拷贝的数组与原数组的位置对应
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}

	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}

	memcpy(a + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fali!");
		return;
	}

	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
}

// 归并排序非递归实现
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fali!");
		return;
	}

	int gap = 1;

	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			//对[begin1, end1][begin2, end2]归并

			if (end1 > n || begin2 > n)
			{
				break;
			}

			if (end2 > n)
			{
				end2 = n - 1;
			}

			int j = begin1;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}

			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}

			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}

			memcpy(a + i, tmp + i, sizeof(int) * (end2 - i + 1));
		}

		gap *= 2;
	}

	free(tmp);
}

// 计数排序
void CountSort(int* a, int n)
{
	int min = a[0], max = a[0];//防止不初始化，导致被给到的随机值参与了比较

	for (int i = 1; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];

		if (a[i] > max)
			max = a[i];
	}

	int range = max - min + 1;
	int* count = (int*)calloc(range, sizeof(int));
	if (count == NULL)
	{
		printf("calloc fail!");
		return;
	}

	for (int i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}

	int i = 0;
	for (int j = 0; j < range; j++)
	{
		while (count[j]--)
		{
			a[i++] = j + min;
		}
	}
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
	int* a8 = (int*)malloc(sizeof(int) * N);
	int* a9 = (int*)malloc(sizeof(int) * N);



	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand() * rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
		a8[i] = a1[i];
		a9[i] = a1[i];

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
	QuickSort(a5, 0, N - 1);
	int end5 = clock();

	int begin6 = clock();
	MergeSort(a6, N);
	int end6 = clock();

	//int begin7 = clock();
	//BubbleSort(a7, N);
	//int end7 = clock();

	int begin8 = clock();
	QuickSortNonR(a8, 0, N - 1);
	int end8 = clock();

	int begin9 = clock();
	CountSort(a9, N);
	int end9 = clock();

	//printf("InsertSort:%d\n", end1 - begin1);//做启动时间与结束时间的差值,得出此排序的时间
	printf("ShellSort:%d\n", end2 - begin2);
	//printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("QuickSort:%d\n", end5 - begin5);
	printf("MergeSort:%d\n", end6 - begin6);
	//printf("BubbleSort:%d\n", end7 - begin7);
	printf("QuickSortNonR:%d\n", end8 - begin8);
	printf("CountSort:%d\n", end9 - begin9);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
	free(a8);
	free(a9);
}
