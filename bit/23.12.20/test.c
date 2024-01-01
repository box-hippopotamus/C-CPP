#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//bool isAcronym(char** words, int wordsSize, char* s) 
//{
//	if (strlen(s) == wordsSize)
//	{
//		for (int i = 0; i < wordsSize; i++)
//		{
//			if (words[i][0] != s[i])
//			{
//				return false;
//			}
//		}
//		return true;
//	}
//	return false;
//}

bool pollution(int** grid, int i, int j, int gridSize, int* gridColSize)
{
	bool flag = false;
	if (i - 1 >= 0 && grid[i - 1][j] == 1)
	{
		grid[i - 1][j] = 3;
		flag = true;
	}
	if (i + 1 < gridSize && grid[i + 1][j] == 1)
	{
		grid[i + 1][j] = 3;
		flag = true;
	}
	if (j - 1 >= 0 && grid[i][j - 1] == 1)
	{
		grid[i][j - 1] = 3;
		flag = true;
	}
	if (j + 1 < gridColSize[0] && grid[i][j + 1] == 1)
	{
		grid[i][j + 1] = 3;
		flag = true;
	}
	return flag;
}

int orangesRotting(int** grid, int gridSize, int* gridColSize)
{
	int min = 0;
	bool flag1 = true;
	bool flag2 = false;
	while (flag1)
	{
		flag1 = false;
		flag2 = false;
		for (int i = 0; i < gridSize; i++)
		{
			for (int j = 0; j < gridColSize[0]; j++)
			{
				if (grid[i][j] == 1)
				{
					flag2 = true;
					break;
				}
			}
			if (flag2)
				break;
		}

		if (!flag2)
			return min;

		for (int i = 0; i < gridSize; i++)
		{
			for (int j = 0; j < gridColSize[0]; j++)
			{
				if (grid[i][j] == 2)
				{
					flag1 = pollution(grid, i, j, gridSize, gridColSize) || flag1;
				}
			}
		}

		for (int i = 0; i < gridSize; i++)
		{
			for (int j = 0; j < gridColSize[0]; j++)
			{
				if (grid[i][j] == 3)
				{
					grid[i][j] = 2;
				}
			}
		}

		if (flag1 && flag2)
			min++;

		if (flag1 == false && flag2 == true)
		{
			min = -1;
			break;
		}
	}

	return min;
}


int main()
{
	int** grid = malloc(sizeof(int*) * 3);
	int* grid1 = malloc(sizeof(int) * 3);
	int* grid2 = malloc(sizeof(int) * 3);
	int* grid3 = malloc(sizeof(int) * 3);

	grid1[0] = 2;
	grid1[1] = 1;
	grid1[2] = 1;

	grid2[0] = 1;
	grid2[1] = 1;
	grid2[2] = 1;

	grid3[0] = 0;
	grid3[1] = 1;
	grid3[2] = 2;


	grid[0] = grid1;
	grid[1] = grid2;
	grid[2] = grid3;

	int a = 3;

	int* gridColSize = &a;

	int min  = orangesRotting(grid, 3, gridColSize);

	printf("%d", min);


	return 0;
}