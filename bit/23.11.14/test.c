#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//int main()
//{
//	int n;
//	int arr[100] = { 0 };
//
//	scanf("%d", &n);
//
//	for (int i = 0; i < n; i++)
//	{
//		int m = 0;
//		scanf("%d", &m);
//		for (int j = 0; j < m; j++)
//		{
//			int num = 0;
//			scanf("%d", &num);
//			arr[i] += num;
//		}
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d\n", arr[i]);
//	}
//
//	return 0;
//}


//#include <stdio.h>
//
//int add(int n)
//{
//	if (n > 1)
//		return n * (n - 1);
//	else
//		return 1;
//}
//int main()
//{
//
//
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int n = 0;
//	int Sn;
//	scanf("%d", &n);
//	Sn = n * 2 + 0.5 * n * (n - 1) * 3;
//	printf("%d", Sn);
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int arr[3][3];
//
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//
//	int sum = arr[0][0] + arr[1][1] + arr[2][2];
//
//	printf("%d", sum);
//
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int m, n, tmp, big, small;
//	scanf("%d %d", &m, &n);
//	big = m;
//	small = n;
//
//	if (m < n)
//	{
//		big = n;
//		small = m;
//	}
//
//	while (big % small)
//	{
//		tmp = big % small;
//		big = small;
//		small = tmp;
//	}
//	printf("%d ", small);
//	printf("%d", (m * n) / small);
//
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int arr[20];
//	int i;
//	int count = 0, j = 0;
//	float sum = 0;
//	for (i = 0; i < 20; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	for (i = 0; i < 20; i++)
//	{
//		if (arr[i] < 0)
//		{
//			count++;
//		}
//		else if (arr[i] > 0)
//		{
//			sum += arr[i];
//			j++;
//		}
//	}
//
//
//	printf("%d\n", count);
//	printf("%.2f\n",(sum / j));
//	return 0;
//}

