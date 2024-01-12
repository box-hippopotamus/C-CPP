#include "Heap.h"

//int main()
//{
//	int a[] = { 4,6,2,1,5,8,2,9 };
//	HP hp;
//	HeapInit(&hp);
//	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
//	{
//		HeapPush(&hp, a[i]);
//	}
//
//	//找出最小的前k个
//	int k = 3;
//	while (k--)
//	{
//		printf("%d\n", HeapTop(&hp));
//		HeapPop(&hp);
//	}
//
//	//遍历
//	while (!HeapEmpty(&hp))
//	{
//		printf("%d ", HeapTop(&hp));
//		HeapPop(&hp);
//	}
//	printf("\n");
//
//	return 0;
//}


//int main()
//{
//	printtopk("data.txt", 5);
//
//	return 0;
//}



//------------------------------------------------------------------------------------------//
//堆排序(升序)
void HeapSort(HPDataType* a, int n)
{
	int i;
	//向上调整建堆
	//for (i = 0; i < n; i++)
	//{
	//	AdjustUp(a, i);
	//}

	//向下调整建堆
	for (i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}


void CreateData()
{
	//造数据
	int n = 10000000;
	srand(time(NULL));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		int x = (rand() * rand()) % 10000000;
		fprintf(fin, "%d\n", x);
	}
	fclose(fin);
}

//void PrintTopK(const char* file, int k)
//{
//	FILE* fout = fopen(file, "r");
//	if (fout == NULL)
//	{
//		perror("fopen fail");
//		return;
//	}
//
//	//------------------------------
//	//建立一个k个数字的小堆
//	int* minheap = (int*)malloc(sizeof(int) * k);
//	if (minheap == NULL)
//	{
//		perror("malloc fail");
//		return;
//	}
//
//	for (int i = 0; i < k; i++)
//	{
//		fscanf(fout, "%d", &minheap[i]);
//		AdjustUp(minheap, i);
//	}
//
//	//-------------------------------
//	//将后续数字与当前的堆中数据比较
//	int x = 0;
//	while (fscanf(fout, "%d", &x) != EOF)
//	{
//		if (x > minheap[0])
//		{
//			minheap[0] = x;
//			AdjustDown(minheap, k, 0);
//		}
//	}
//
//	for (int i = 0; i < k; i++)
//	{
//		printf("%d ", minheap[i]);
//	}
//	printf("\n");
//
//	fclose(fout);
//}

void PrintTopK(int* a, int size, int k)
{
	//------------------------------
	//建立一个k个数字的小堆
	int* minheap = (int*)malloc(sizeof(int) * k);
	if (minheap == NULL)
	{
		perror("malloc fail");
		return;
	}

	for (int i = 0; i < k; i++)
	{
		minheap[i] = a[i];
		AdjustUp(minheap, i);
	}

	//-------------------------------
	//将后续数字与当前的堆中数据比较
	for (int i = k; i < size; i++)
	{
		if (a[i] > minheap[0])
		{
			minheap[0] = a[i];
			AdjustDown(minheap, k, 0);
		}
	}

	for (int i = 0; i < k; i++)
	{
		printf("%d ", minheap[i]);
	}
	printf("\n");
}

int main()
{
	printtopk("data.txt", 5);

	return 0;
}