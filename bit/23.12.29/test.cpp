#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

void Swap(int* arr, int a, int b)
{
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

void AdjustDown(int* heap, int size, int parent)
{
	int child = parent * 2 + 1;

	while (child < size)
	{
		if (child + 1 < size && heap[child + 1] > heap[child])
			child++;

		if (heap[parent] < heap[child])
		{
			Swap(heap, parent, child);
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

int buyChoco(int* prices, int pricesSize, int money) 
{
	int i = 0;
	int heap[2];

	for (i = 0; i < 2; i++)
	{
		heap[i] = prices[i];
	}

	CreateHeap(heap, 2);

	for (i = 2; i < pricesSize; i++)
	{
		if (prices[i] < heap[0])
		{
			heap[0] = prices[i];
			AdjustDown(heap, 2, 0);
		}
	}

	if (money < heap[0] + heap[1])
		return money;
	
	return money - heap[0] - heap[1];
}

int main()
{



	return 0;
}