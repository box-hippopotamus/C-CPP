#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* findPeakGrid(int** mat, int matSize, int* matColSize, int* returnSize)
{
	int* a = (int*)malloc(sizeof(int) * 2);
	int col = matColSize[0];
	int row = matSize;

	int max[row];

	for (int i = 0; i < row; i++)
	{
		max[i] = 0;
		for (int j = 0; j < col; j++)
		{
			if (mat[i][j] > mat[i][max[i]])
				max[i] = j;
		}
	}
	int top = 0;
	int bottom = row - 1;
	int mid = (top + bottom) / 2;

	int ans = 0;
	while (top <= bottom)
	{
		mid = (top + bottom) / 2;

		if (mid + 1 < row)
		{
			if (mat[mid][max[mid]] > mat[mid + 1][max[mid + 1]])
			{
				ans = mid;
				bottom = mid - 1;
			}
			else
				top = mid + 1;
		}
		else
		{
			ans = mid;
			break;
		}
		
	}

	a[0] = ans;
	a[1] = max[ans];
	*returnSize = 2;
	return a;
}

int main()
{

	return 0;
}