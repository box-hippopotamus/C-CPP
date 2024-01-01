#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

int minCostClimbingStairs(int* cost, int costSize)
{

    int dp[costSize + 1];
    dp[0] = dp[1] = 0;
    for (int i = 2; i < costSize + 1; i++)
    {
        dp[i] = fmin(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }

    return dp[costSize];
}

int climbStairs(int n)
{
    if (n == 1)
        return 1;

    int dp[n];
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 1; i < n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n - 1];
}

int fib(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i < n + 1; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int uniquePaths(int m, int n)
{
    int dp[m][n];

    for (int i = 0; i < m; i++)
    {
        dp[i][n] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        dp[m][i] = 0;
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; i < n; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

int minPathSum(int** grid, int gridSize, int* gridColSize)
{
    int col = gridColSize[0];
    int row = gridSize;
    int dp[row][col];

    dp[0][0] = grid[0][0];

    for (int i = 1; i < row; i++)
    {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for (int i = 1; i < col; i++)
    {
        dp[0][i] = dp[0][i - 1] + grid[0][i];
    }

    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            dp[i][j] = fmin(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }

    return dp[row - 1][col - 1];
}



int lenLongestFibSubseq(int* arr, int arrSize)
{
    int dp[arrSize][arrSize];

    for (int i = 1; i < arrSize; i++)
    {
        for (int j = 1; j < arrSize; j++)
        {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i < arrSize; i++)
    {
        for (int j = 1; j < i; j++)
        {
            for (int m = 0; m < j; m++)
            {
                if (arr[m] + arr[j] == arr[i])
                {
                    if (dp[j][m] + 1 > dp[i][j])
                        dp[i][j] = dp[j][m] + 1;
                }
            }

            for (int m = 0; m < j; m++)
            {
                if (dp[m][j] > dp[i][j])
                    dp[i][j] = dp[m][j];
            }
        }
    }
    return dp[arrSize - 1][arrSize - 2];
}


int main()
{

	return 0;
}