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

////����ȡ��һ���ڵ���key
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

//����ȡ��
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
		if (a[end] < a[midi])
			return midi;
		else if (a[end] > a[begin])
			return begin;
		else
			return end;
	}
}

//��������ȡ�п��� + С�����Ż�
int PartSort1(int* a, int begin, int end)
{
	int midi = GetMidi(a, begin, end);
	Swap(&a[midi], &a[begin]);//��ȡ�����м�ֵ������λ��key

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

// ���������ڿӷ�
int PartSort2(int* a, int begin, int end)
{
	int midi = GetMidi(a, begin, end);
	Swap(&a[midi], &a[begin]);

	int key = a[begin];
	int hole = begin;

	while (begin < end)
	{
		//�ұ���С�������ߵĿ�
		while (begin < end && a[end] >= key)
		{
			end--;
		}

		a[hole] = a[end];
		hole = end;

		//����Ҵ���ұߵĿ�
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

// ��������ǰ��ָ�뷨 
int PartSort3(int* a, int begin, int end)
{
	int midi = GetMidi(a, begin, end);
	Swap(&a[midi], &a[begin]);

	int prev = begin;
	int cur = prev + 1;

	int keyi = begin;

	while (cur <= end)
	{
		if (a[cur] < a[keyi] && ++prev != cur)//�����Լ����Լ�����
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

	//int keyi = PartSort1(a, begin, end);//����
	//int keyi = PartSort2(a, begin, end);//�ڿӷ�
	int keyi = PartSort3(a, begin, end);//ǰ��ָ�뷨
	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);
}

// �������� �ǵݹ�ʵ��
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



// �鲢����ݹ�ʵ��
void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;

	int mid = (begin + end) / 2;
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);

	//�鲢
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;

	int i = begin;//ʹ������������ԭ�����λ�ö�Ӧ
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

// �鲢����ǵݹ�ʵ��
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
			//��[begin1, end1][begin2, end2]�鲢

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

// ��������
void CountSort(int* a, int n)
{
	int min = a[0], max = a[0];//��ֹ����ʼ�������±����������ֵ�����˱Ƚ�

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

	//printf("InsertSort:%d\n", end1 - begin1);//������ʱ�������ʱ��Ĳ�ֵ,�ó��������ʱ��
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
