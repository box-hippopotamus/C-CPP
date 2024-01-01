#define _CRT_SECURE_NO_WARNINGS 1

//
//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	char str1[20];
//	char str2[20];
//	scanf("%s", str1);
//	scanf("%s", str2);
//
//	int a = strcmp(str1, str2);
//	printf("%d", a);
//
//
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//int main()
//{
//
//	char a[60];
//	char str1[60];
//	scanf("%s", a);
//	int t = 0;
//
//	for (int i = strlen(a) -1 ; i >= 0; i--)
//	{
//		str1[t] = a[i];
//		t++;
//	}
//
//	strcat(a, str1);
//	printf("%s", a);
//	return 0;
//}

//杨氏矩阵

//#include <stdio.h>
//
//int main()
//{
//	int arr[5][5];
//	int i, j;
//
//	for (i = 0; i < 5; i++)
//	{
//		for (j = 0; j < 5; j++)
//		{
//			scanf("%d ", (*(arr + i) + j));
//
//		}
//	}
//	printf("你的数组为：\n");
//
//	for (i = 0; i < 5; i++)
//	{
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d ", *(*(arr + i) + j));
//		}
//		printf("\n");
//	}
//
//	int num;
//	scanf("请输入要查找的数字\n");
//
//	while(scanf("%d ", &num) != EOF)
//	{
//		for (i = 0; i < 5; i++)
//		{
//			if ((num > **(arr + i)) && )
//			{
//				for (j = 0; j < 5; j++)
//				{
//					if (*(*(arr + i) + j) == num)
//					{
//						printf("数字存在\n");
//						printf("在 %d行 %d列\n", (i + 1), (j + 1));
//						break;
//					}
//					printf("数字不存在\n");
//					break;
//				}
//
//			}
//			else if (num < **(arr + i))
//			{
//				printf("数字不存在\n");
//				break;
//			}
//			else
//			{
//				printf("数字存在\n");
//				printf("在 %d行 %d列\n", (i + 1), 1);
//				break;
//			}
//		}
//
// 
//	}
//	return 0;
//}

//
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 杨氏矩阵
//#include <stdio.h>
//
//int main()
//{
//	int arr[5][5];
//	int i, j;
//
//	for (i = 0; i < 5; i++)
//	{
//		for (j = 0; j < 5; j++)
//		{
//			scanf("%d ", (*(arr + i) + j));
//		}
//	}
//
//	printf("你的数组为：\n");
//	for (i = 0; i < 5; i++)
//	{
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d ", *(*(arr + i) + j));
//		}
//		printf("\n");
//	}
//
//	int num = 0;
//
//	while (scanf("请输入要查找的数字 %d ", &num) != EOF)
//	{
//		int count = -1;
//		for (i = 0; i < 5; i++)
//		{
//			if (num > **(arr + i))
//			{
//				count++;
//				continue;
//			}
//			else if (num == **(arr + i))
//			{
//				printf("数字存在\n");
//				printf("在 %d行 %d列\n", (i + 1), 1);
//				count = -1;
//				break;
//			}
//			else if(count == -1)
//			{		
//				printf("数字不存在\n");
//				break;
//			}
//		}
//
//		if (0 <= count < 5)
//		{
//			for (i = 1; i < 5; i++)
//			{
//				if (num == *(*(arr + count) + i))
//				{
//					printf("数字存在\n");
//					printf("在 %d行 %d列\n", (count + 1), (i + 1));
//					break;
//				}
//			}
//			if (i == 5)
//			{
//				printf("数字不存在\n");
//			}
//
//		}
//	}
//
//
//}



//猜凶手
//#include <stdio.h>
//
//int main()
//{
//	//ABCD
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	int d = 1;
//
//	////A   a = 1;
//	////B   c = 0;
//	////C   d = 0;
//	////D   c = 0;
//
//	//if A
//	a = 0;
//
//
//
//	return 0;
//}


//杨辉三角

int main()
{
	int arr[50][50];
	arr[0][0] = 1;
	int i, j;
	
	for (i = 1; i < 50; i++)
	{
		for (j = 0; j <= i; j++)
		{
			arr[i][0] = 1;



		}


	}

	return 0;
}