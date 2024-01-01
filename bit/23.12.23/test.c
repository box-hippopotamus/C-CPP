#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void Swap(int* nums, int i, int j) {
	int x = nums[i];
	nums[i] = nums[j];
	nums[j] = x;
}

void AdjustDown(int* Heap, int HeapSize, int parent)
{
	int child = parent * 2 + 1;

	while (child < HeapSize)
	{
		if (child + 1 < HeapSize && Heap[child + 1] > Heap[child])
		{
			child++;
		}

		if (Heap[parent] < Heap[child])
		{
			Swap(Heap, parent, child);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void CreateHeap(int* Heap, int HeapSize)
{
	int i;
	for (i = (HeapSize - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(Heap, HeapSize, i);
	}
}

int minStoneSum(int* piles, int pilesSize, int k)
{
	CreateHeap(piles, pilesSize);

	while (k--)
	{
		piles[0] = piles[0] - piles[0] / 2;
		Swap(piles, 0, pilesSize - 1);
		AdjustDown(piles, pilesSize, 0);
	}

	int sum = 0;

	for (int i = 0; i < pilesSize; i++)
	{
		sum += piles[i];
	}

	return sum;
}

int main()
{
	int piles[4] = {4, 3, 6, 7};
	int n = minStoneSum(piles, 4, 3);

	printf("%d", n);
	return 0;
}