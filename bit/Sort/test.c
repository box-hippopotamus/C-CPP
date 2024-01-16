#include "Sort.h"

int main()
{
	srand((unsigned int)time(NULL));
	int i;
	int a[20] = { 0 };

	for (i = 0; i < 20; i++)
	{
		a[i] = rand() % 1000;
		printf("%4d ", a[i]);
	}
	printf("\n");

	int n = sizeof(a) / sizeof(a[0]);
	//---------------------------
	CountSort(a, n);
	//---------------------------
	for (i = 0; i < 20; i++)
	{
		printf("%4d ", a[i]);
	}
	printf("\n");

	TestOP();
	return 0;
}