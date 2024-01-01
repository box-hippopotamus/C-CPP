#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

//int main()
//{
//	int n;
//	double arr[100];
//
//	scanf("%d",&n);
//	double x1, y1, x2, y2, x3, y3;
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
//
//		if (((x1 - x2) / (y1 - y2)) != ((x2 - x3) / (y2 - y3)))//ÅÐ¶ÏÐ±ÂÊ
//		{
//			arr[i] = 0.5 * (x1 * abs(y2 - y3) + x2 * abs(y1 - y3) + x3 * abs(y1 - y2));
//		}
//		else
//		{
//			arr[i] = 0;
//		}
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		if (arr[i])
//		{
//			printf("%.3lf\n", arr[i]);
//		}
//		else
//		{
//			printf("Can not form a triangle.\n");
//		}
//	}
//
//	return 0;
//}


//int main()
//{
//	int a, b, i = 0, j = 0;
//
//	int arr[100];
//	while (scanf("%d %d", &a, &b) != EOF)
//	{
//		arr[i] = a + b;
//		i++;
//	}
//
//	for (j = 0; j < i; j++)
//	{
//		printf("%d\n", arr[j]);
//	}
//	return 0;
//}

//int main()
//{
//	
//	sccanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d %d", &a, &b);
//		arr[i] = a + b;
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d\n", arr[i]);
//	}
//	return 0;
//}

//int main()
//{
//	int arr[100];
//	int a, b, i = 0;
//	while (scanf("%d %d", &a,&b))
//	{
//		if (!(a || b))
//			break;
//		else 
//		{
//			arr[i] = a + b;
//			i++;
//		}
//	}
//
//	for (int j = 0; j < i; j++)
//	{
//		printf("%d\n", arr[j]);
//	}
//	return 0;
//}

int main()
{
	int n, j = 0;
	int arr[100] = {0};

	while (scanf("%d", &n) && n)
	{

		for (int i = 0; i < n; i++)
		{
			int num;
			scanf("%d", &num);
			arr[j] += num;
		}
		j++;
	}

	for (int i = 0; i < j; i++)
	{
		printf("%d\n", arr[j]);
	}

	return 0;
}