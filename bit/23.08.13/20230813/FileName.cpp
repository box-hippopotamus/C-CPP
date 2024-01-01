#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <math.h>
//
//int is_prime(int i)
//{
//	int j;
//	int a = 1;
//	int b = sqrt(i);
//	for (j = 2; j <= b; j++)
//	{
//		if (i % j == 0)
//		{
//			a = 0;
//			break;
//		}
//	}
//	return a;
//}
//int main()
//{
//	int i;
//	int num = 0;
//
//	for (i = 100; i <= 200; i++) 
//	{
//		num = is_prime(i);
//		if (num)
//		{
//			printf("%d ", i);
//		}
//		num = 0;
//	}
//	return 0;
//}

//#include <stdio.h>
//
//int leap_year(int num)
//{
//	if (((num % 4 == 0) && (num % 100 != 0)) || (num % 400 == 0))
//	{
//		printf("%d年是闰年\n", num);
//	}
//	else
//	{
//		printf("%d年不是闰年\n", num);
//	}
//		return 0;
//}
//
//int main()
//{
//	int num;
//	while (scanf("%d", &num) != EOF)
//	{
//		leap_year(num);
//	}
//
//	return 0;
//}
//
//
//#include <stdio.h>
//
//void inti(int arr[],int sz)
//{
//	int i;
//	for (i =0; i < sz; i++)
//	{
//		arr[i] = 0;
//	}
//}
//
//void print(int arr[],int sz)
//{
//	int i;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//
//int reverse(int arr1[],int arr2[],int sz)
//{
//	int i;
//	for (i = 0; i < sz; i++)
//	{
//		arr1[i] = arr2[sz - i-1];
//	}
//
//	return 0;
//}
//int main()
//{
//	int arr[10];
//	int sz = sizeof arr / arr[0];
//	return 0;
//}

//
//
//#include <stdio.h>
//
//int main()
//{
//	int i, j,a,b;
//	scanf("%d", &a);
//
//	for (i = 1; i <= a; i++)
//	{
//		for (j = 1; (j <= a)&&(j<=i); j++)
//		{
//			b = i * j;
//			printf("%d*%d=%d ", i, j, b);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}