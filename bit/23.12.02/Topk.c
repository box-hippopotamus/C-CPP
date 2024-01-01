//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//#include <stdbool.h>
//#include <time.h>
//
//void swap(int* x, int* y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//
//void AdjustUp(int* a, int child)
//{
//	assert(a);
//	int parent = (child - 1) / 2;
//
//	while (child > 0)
//	{
//		if (a[parent] > a[child])
//		{
//			swap(&a[parent], &a[child]);
//			child = parent;
//			parent = (child - 1) / 2;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
//
//void AdjustDown(int* a, int size, int parent)
//{
//	assert(a);
//	int child = parent * 2 + 1;
//
//	while (child < size)
//	{
//		if (child + 1 < size && a[child + 1] < a[child])
//		{
//			child++;
//		}
//
//		if (a[parent] > a[child])
//		{
//			swap(&a[parent], &a[child]);
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
//
//void CreateNDate()
//{
//	// дьЪ§Он
//	int n = 10000000;
//	srand(time(0));
//	const char* file = "data.txt";
//	FILE* fin = fopen(file, "w");
//	if (fin == NULL)
//	{
//		perror("fopen error");
//		return;
//	}
//
//	for (size_t i = 0; i < n; ++i)
//	{
//		int x = (rand() * rand()) % 1000000;
//		fprintf(fin, "%d\n", x);
//	}
//
//	fclose(fin);
//}
//
//void PrintTopK(const char* file, int k)
//{
//	FILE* fout = fopen(file, "r");
//	if (fout == NULL)
//	{
//		perror("fopen fail");
//		return;
//	}
//
//	int* heap = (int*)malloc(k * sizeof(int));
//	if (heap == NULL)
//	{
//		perror("malloc fail");
//		return;
//	}
//
//	for (int i = 0; i < k; i++) 
//	{
//		fscanf(fout, "%d", &heap[i]);
//		AdjustUp(heap, i);
//	}
//
//	int x = 0;
//	while (fscanf(fout, "%d", &x) != EOF)
//	{
//		if (x > heap[0])
//		{
//			heap[0] = x;
//			AdjustDown(heap, k, 0);
//		}
//	}
//
//	for (int i = 0; i < k; i++)
//	{
//		printf("%d ", heap[i]);
//	}
//	printf("\n");
//
//	fclose(fout);
//}
//
//
//int main()
//{
//	CreateNDate();
//
//	PrintTopK("data.txt", 10);
//	return 0;
//}