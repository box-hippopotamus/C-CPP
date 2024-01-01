#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int main()
//{
//	int arr[5][5] = { {1,3,8,9,10},{15,19,22,26,28},{30,33,38,45,49},{50,58,66,72,81} ,{87,88,89,95,99}};
//	int i = 0;
//	int j = 0;
//
//	for (i = 0; i < 5; i++)
//	{
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//
//	int x = 0;
//	while (scanf("%d ", &x) != EOF)
//	{
//		if (x < arr[0][0])
//		{
//			printf("不存在\n");
//		}
//		int count = 0;
//		for (i = 0; i < 5; i++)
//		{
//			if (arr[i][0] == x)
//			{
//				//数字存在
//				printf("存在，在%d行%d列\n", (count + 1), 1);
//				count = 0;
//				break;
//			}
//			else if (arr[i][0] > x)
//			{
//				break;
//				//跳出循环
//			}
//			else
//			{
//				count++;
//				//下一次循环
//			}
//		}
//
//		if (count)
//		{
//			for (i = 0; i < 5; i++)
//			{
//				if (arr[count - 1][i] == x)
//				{
//					printf("存在，在%d行%d列\n", count, (i + 1));
//					break;
//				}
//			}
//
//			if (i == 5)
//			{
//				printf("不存在\n");
//			}
//		}
//	}
//
//
//	return 0;
//}


int main()
{
	int arr[9][9];

	int i, j;

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			arr[i][j] = 1;
		}
	}

	for (i = 2; i < 9; i++)
	{
		for (j = 1; j < i-1; j++)
		{
			arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
		}
	}


	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < i; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}