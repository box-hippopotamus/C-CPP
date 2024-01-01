#include "Sort.h"

// ����ʵ�ֵĽӿ�

//����
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

// �������� 
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		//��ǰ[0, end]��һ���������У���end+1����
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

// ϣ������
void ShellSort(int* a, int n)
{
	int gap = n;
	//gap > 1ʱ��Ԥ����Ŀ��������ӽ�����
	//gap == 1�������ղ�������Ŀ������������
	while (gap > 1)
	{
		//gap = gap / 2;  ��������Ҫ����̫���ˣ����Կ���ʹ��/3
		gap = gap / 3 + 1;//Ϊ�˱�֤���һ��һ����1���˴�Ҫ+1

		for (int i = 0; i < n - gap; i++)//�˴�������n-gap�ڣ����һ��end + gap�Ͳ���Խ��
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

// ѡ������
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

// ������
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
	//����
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDwon(a, n, i);
	}

	//����
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		end--;
	}
}

// ð������
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

// ��������ݹ�ʵ��
// ��������hoare�汾
int GetMidi(int* a, int begin, int end)
{
	int midi = (begin + end) / 2;
	//ѡbegin end midi ����λ��
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

// ���������ڿӷ�
int PartSort2(int* a, int left, int right)
{

}

// ��������ǰ��ָ�뷨
int PartSort3(int* a, int left, int right)
{

}

void QuickSort(int* a, int left, int right)
{

}

// �������� �ǵݹ�ʵ��
void QuickSortNonR(int* a, int left, int right)
{

}

// �鲢����ݹ�ʵ��
void MergeSort(int* a, int n)

{}

// �鲢����ǵݹ�ʵ��
void MergeSortNonR(int* a, int n)
{

}

// ��������
void CountSort(int* a, int n)
{

}

// ������������ܶԱ�
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

	//clock�������ش�ϵͳ������ִ�д����ĺ�����
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

	//printf("InsertSort:%d\n", end1 - begin1);//������ʱ�������ʱ��Ĳ�ֵ,�ó��������ʱ��
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