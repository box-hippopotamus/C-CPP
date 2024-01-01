#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void AdjustUp(int* a, int child)
{
	assert(a);
	int parent = (child - 1) / 2;

	while (child > 0)
	{
		if (a[parent] < a[child])
		{
			swap(&a[parent], &a[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void AdjustDown(int* a, int size, int parent)
{
	assert(a);
	int child = parent * 2 + 1;

	while (child < size)
	{
		if (child + 1 < size && a[child + 1] > a[child])
		{
			child++;
		}

		if (a[parent] < a[child])
		{
			swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}


//堆排序
void HeapSort(int* a, int n)
{
	////向上调整建堆
	//for (int i = 0; i < n; i++)
	//{
	//	AdjustUp(a, i);
	//}

	//向下调整建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		swap(&a[i], &a[0]);
		AdjustDown(a, i, 0);
	}

}

int main()
{
	/*CreateNDate();*/
	/*PrintTopK("data.txt", 10);*/

	int arr[] = { 1, 4, 5, 8, 15, 44, 9, 56, 1, 7, 6, 45, 555, 88, 0 };

	int size = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, size);

	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}