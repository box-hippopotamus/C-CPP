#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//
//void bubble_sort(int* arr,int n)
//{
//	int i, j;
//	for (i = n - 1; i >= 0; i--)
//	{
//		for (j = 0; j < i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int n, i;
//	int arr[1000];
//	scanf("%d", &n);
//
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	bubble_sort(arr, n);
//
//	int sum = 0;
//
//	if (n % 2 == 1)
//	{
//		i = 0;
//	}
//	else
//	{
//		i = 1;
//	}
//
//	while (i < n)
//	{
//		sum += arr[i];
//		i = i + 2;
//	}
//
//	printf("%d", sum);
//	return 0;
//}
// 5  23  55  155

//#include <stdio.h>
//
//int main()
//{
//	char* s = "May your dreams be as boundless as the open sky, and may your journey through life be as beautiful as a summer's day.";
//	int i = 0, j = 0;
//	char arr[1000];
//
//	while (s[i] != '\0')
//	{
//		if (s[i] != 'o' && s[i] != 'p')
//		{
//			arr[j] = s[i];
//			j++;
//		}
//		i++;
//	}
//
//	arr[j] = '\0';
//
//	printf("%s", arr);
//
//	return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//
//
//
//	return 0;
//}


//#include <stdio.h>
//
//struct data {
//	int normal;
//	int prev;
//};
//
//void bubble_sort(struct data* arr, int n)
//{
//	int i, j;
//	for (i = n - 1; i >= 0; i--)
//	{
//		for (j = 0; j < i; j++)
//		{
//			if (arr[j].normal > arr[j + 1].normal)
//			{
//				struct data tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//			else if (arr[j].normal == arr[j + 1].normal)
//			{
//				if (arr[j].prev > arr[j + 1].prev)
//				{
//					struct data tmp = arr[j];
//					arr[j] = arr[j + 1];
//					arr[j + 1] = tmp;
//				}
//			}
//
//		}
//	}
//}
//
//int main()
//{
//	int n;
//	int i = 0, j = 0;
//	scanf("%d", &n);
//	struct data arr[100];
//
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d %d", &arr[i].normal, &arr[i].prev);
//	}
//
//	bubble_sort(arr, n);
//
//	for (i = 1; i <= arr[n-1].normal; i++)
//	{
//		while (i == arr[j].prev || i == arr[j].normal)
//		{
//			j++;
//			if (j == n)
//				break;
//		}
//
//		if (j == n)
//			break;
//	}
//
//	printf("%d", i);
//
//	return 0;
//}

//#include <stdio.h>
//
//int jc(long long n)
//{
//	if (n == 0)
//		return 1;
//	if (n > 0)
//		return jc(n - 1) * n;
//}
//
//
//int main()
//{
//	int i;
//	long long t;
//	scanf("%ld", &t);
//
//	long long arr[10000];
//
//	for (i = 0; i < t; i++)
//	{
//		scanf("%ld", &arr[i]);
//	}
//
//	for (i = 0; i < t; i++)
//	{
//		printf("%ld\n", jc(arr[i]));
//	}
//
//	return 0;
//}


//#include <stdio.h>
//
//struct box
//{
//	int a;
//	int b;
//};
//
//int main()
//{
//	int t, n;
//	int i, j;
//	int arr[10][100000] = { 0 };
//	scanf("%d", &t);
//
//	for (i = 0; i < t; i++)
//	{
//		scanf("%d", &n);
//		for (j = 0; j < n; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//
//	for (i = 0; i < t; i++)
//	{
//		scanf("%d", &n);
//		for (j = 0; j < n; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//
//
//	return 0;
//}




//------------------------------------
//
//int main()
//{
//	int n, m;
//	scanf("%d %d", &n, &m);
//	int t = sqrt(2*(m + n) + 1) - 1;
//	int x = n - t;
//	printf("%d", x);
//	return 0;
//}
//----------------


//#include <stdio.h>
//int win(int n)
//{
//	int arr[10000] = { 0 };
//	int i,j;
//	for (i = 0; i < n; i++)
//	{
//		arr[i] = 1;
//	}
//	
//	int prev = 0;
//	int next = prev + 1;
//	int sum = 0;
//
//	for (i = 0; i < n; i++)
//	{
//		sum += arr[i];
//	}
//
//	while (sum != 1)
//	{
//		if (arr[next] == 1)
//		{
//			arr[next] = 0;
//			sum -= 1;
//			prev += 1;
//			prev %= n;
//			while (arr[prev] == 0)
//			{
//				prev++;
//				prev %= n;
//			}
//			next = prev + 1;
//		}
//		else
//		{
//			next++;
//		}
//		prev %= n;
//		next %= n;
//
//	}
//	return prev + 1;
//}
//
//int main()
//{
//	int t;
//	int i;
//	scanf("%d", &t);
//
//	int arr[1000] = {0};
//	for (i = 0; i < t; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	for (i = 0; i < t; i++)
//	{
//		printf("%d\n",win(arr[i]));
//	}
//	return 0;
//}

//---------------------------------------------------------------

//#include <stdio.h>
//
//int pow(int n)
//{
//	if (n >= 1)
//		return pow(n - 1) * 2;
//	if (n == 0)
//		return 1;
//}
//
//int sumpow(int n)
//{
//	int i = 0;
//	int num = 0;
//
//	for (i = 0; i < 100; i++)
//	{
//		if (num <= n && n < num + pow(i + 1))
//		{
//			return num;
//		}
//		num += pow(i + 1);
//	}
//}
//
//int sumpow2(int n)
//{
//	int i = 0;
//	int num = 0;
//
//	for (i = 0; i < 100; i++)
//	{
//		if (num <= n && n < num + pow(i + 1))
//		{
//			return i;
//		}
//		num += pow(i + 1);
//	}
//}
//
//int win(int n)
//{
//	int count = 0;
//	int num = 1;
//	int tmp = n;
//	int i, j;
//
//	j = sumpow2(n);
//
//	tmp = tmp - sumpow(j) - 1;
//
//	while (tmp--)
//	{
//		num = num + 2;
//	}
//
//	return num - 2;
//}
//
//int main()
//{
//	int t;
//	int i;
//	scanf("%d", &t);
//
//	int arr[1000] = { 0 };
//	for (i = 0; i < t; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	for (i = 0; i < t; i++)
//	{
//		printf("%d ", win(arr[i]));
//	}
//
//	return 0;
//}
//------------------------


#include <stdio.h>

int main()
{
	int t;
	int i;
	scanf("%d", &t);

	for (i = 0; i < t; i++)
	{
		int num;
		scanf("%d", &num);

	}

	return 0;
}