#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>

//void sort(int arr[], int n)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < n - 1; i++)
//	{
//		for (j = 0; j < n - 1; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int t = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = t;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int m, n;
//	int arr1[6];
//	int arr2[8];
//
//	for (m = 0; m < 6; m++)
//	{
//		scanf("%d", &arr1[m]);
//	}
//
//	for (m = 0; m < 8; m++)
//	{
//		scanf("%d", &arr2[m]);
//	}
//
//	sort(arr1, 6);
//	sort(arr2, 8);
//
//	for (m = 0; m < 6; m++)
//	{
//		for (n = 0; n < 8; n++)
//		{
//			if (arr1[m] == arr2[n])
//			{
//				printf("%d\n", arr1[m]);
//			}
//		}
//
//	}
//
//	return 0;
//}

//ð������
#include <stdio.h>

void sort(int arr[], int sz)
{
	int m, n;
	for (m = 0; m < (sz-1); m++)//��������
	{
		int flag = 1;//����û�н��н���
		for (n = 0; n < (sz - 1 - m); n++)//����ÿ�˽�������
		{
			if (arr[n] > arr[n + 1])
			{
				//����
				int tmp = arr[n];
				arr[n] = arr[n + 1];
				arr[n + 1] = tmp;
				flag = 0;//֤����һ�˽����˽���
			}

		}
		if (flag != 0)//��if������˵����һ����û�н������ݣ��Ѿ�������ɣ�ֱ������
		{
			break;
		}
	}

}

void print(int* arr, int sz)
{
	int m;
	for (m = 0; m < sz; m++)
	{
		printf("%d ", arr[m]);
	}
}

int main()
{
	int arr[10];
	int i;
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < sz; i++)
	{
		scanf("%d", &arr[i]);
	}

	sort(arr, sz);
	print(arr, sz); 

	return 0;
}