#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void AdjustDown(int* heap, int parent, int heapSize, int* nums)
{
	int child = parent * 2 + 1;

	while (child < heapSize)
	{
		if (child + 1 < heapSize && nums[heap[child + 1]] < nums[heap[child]])
			child++;

		if (nums[heap[parent]] < nums[heap[child]])
		{
			Swap(&heap[parent], &heap[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

int maximumRows(int** matrix, int matrixSize, int* matrixColSize, int numSelect)
{
	int nums[matrixColSize[0]] = { 0 };
	
	for (int i = 0; i < matrixSize; i++)
	{
		int count = 0;
		for (int j = 0; j < matrixColSize[0]; j++)
		{
			if (matrix[i][j] == 1)
				count++;
		}

		if (count <= numSelect)
		{
			for (int j = 0; j < matrixColSize[0]; j++)
			{
				if (matrix[i][j] == 1)
					nums[j]++;
			}
		}
	}

	int index[numSelect] = { 0 };

	for (int i = 0; i < matrixColSize[0]; i++)
	{
		if (nums[i] > nums[index[0]])
		{
			index[0] = i;
			AdjustDown(index, 0, numSelect, nums);

		}
	}

}


int maximumRows(int** matrix, int matrixSize, int* matrixColSize, int numSelect)
{
	int m = matrixSize, n = matrixColSize[0];
	int* mask = (int*)malloc(sizeof(int) * m);

	for (int i = 0; i < m; i++) 
	{
		mask[i] = 0;
		for (int j = 0; j < n; j++) 
		{
			mask[i] += matrix[i][j] << (n - 1 - j);
		}
	}
	int res = 0, limit = 1 << n;

	for (int cur = 1; cur < limit; cur++) 
	{
		if (__builtin_popcount(cur) != numSelect)
		{
			continue;
		}
		int t = 0;
		for (int j = 0; j < m; j++) 
		{
			if ((mask[j] & cur) == mask[j]) 
			{
				t++;
			}
		}
		res = res > t ? res : t;
	}

	free(mask);
	return res;
}

int main()
{

	return 0;
}