#define _CRT_SECURE_NO_WARNINGS 1

////#include<stdio.h>
//
////int main()
////{
////	int n,i;
////	scanf("%d", &n);
////
////	int arr1[n][100000];
////
////	for (i = 0; i < n; i++)
////	{
////		int k, b,j;
////		scanf("%d %d", &k,&b);
////
////		for (j = 0; j < 100000; j++)
////		{
////			arr1[i][j] =( k * j) + b;
////
////		}
////
////	}
////
////
////	return 0;
////}
////
//////
////#include<stdio.h>
////
////int find(int n,int arr[], int x)
////{
////	int num;
////	int left = 0;
////	int right = n;
////	int mid = (right - left) / 2 + left;
////
////
////	while (left<=right)
////	{
////	
////		if (x < arr[mid])
////		{
////			right = mid-1;
////			mid = (right - left) / 2 + left;
////		}
////		else if (x > arr[mid])
////		{
////			left = mid+1;
////			mid = (right - left) / 2 + left;
////		}
////		else if (x == arr[mid])
////		{
////			right = mid;
////			mid = (right - left) / 2 + left;
////		}
////	}
////	if (left == right)
////		return mid + 1;
////
////	else if (left != right)
////		
////////return -1;
////
////}
//////
//////
////
////
////int main()
////{
////	int i,n,m;
////	int arr[1000];
////	int arr1[1000];
////
////
////	scanf("%d %d", &n,&m);
////
////	for (i = 0; i < n; i++)
////	{
////		scanf("%d", &arr[i]);
////	}
////
////
////	for (i = 0 ; i < m; i++)
////	{
////		scanf("%d", &arr1[i]);
////	}
////
////	for (i = 0; i < m; i++)
////	{
////		int num = find(n, arr, arr1[i]);
////		printf("%d ", num);
////	}
////
////	return 0;
////}
////
////
//#include<stdio.h>
//
//int find(int arr[], int k, int len) {
//	int left = 0;
//	int right = len - 1;
//	while (left <= right) {
//		int mid = (left + right) / 2;
//		if (arr[mid] < k) {
//			left = mid + 1;
//		}
//		else if (arr[mid] > k) {
//			right = mid - 1;
//		}
//		else {
//			if (arr[mid] == arr[mid + 1]) {
//				return mid;
//			}
//			return mid + 1;
//		}
//	}
//	return -1;
//
//}
//
// 
//// 
//// 
// 
//#include<stdio.h>
//int find(int arr[], int k, int len) {
//
//	int left = 0;
//	int right = len - 1;
//	int firstFound = -1; // 用于记录第一次找到目标元素的位置
//	while (left <= right) {
//		int mid = (left + right) / 2;
//		if (arr[mid] < k) {
//			left = mid + 1;
//		}
//		else if (arr[mid] > k) {
//			right = mid - 1;
//		}
//		else {
//			firstFound = mid;
//			right = mid - 1; // 修改此处以查找第一个出现的位置
//		}
//	}
//	return (firstFound != -1) ? firstFound + 1 : -1; // 返回索引时加1
//}//"?“为三目操作符，当（）内内容满足，执行冒号前内容，当不满足，执行冒号后内容
//
// 
// 
//int main() {
//	int i, n, m;
//	int arr[1000];
//	int arr1[1000];
//
//	scanf("%d %d", &n, &m);
//	for (i = 0; i < n; i++) {
//		scanf("%d", &arr[i]);
//	}
//	
//	for (i = 0; i < m; i++) {
//		scanf("%d", &arr1[i]);
//	}
//	for (i = 0; i < m; i++) {
//		int num = find(arr, arr1[i], n);
//		printf("%d ", num);
//	}
//
//	return 0;
//}
//
//#include<stdio.h>
//int find(int len,int arr[],int k)
//{
//	int left = 0;
//	int right = len - 1;
//	int first_find = -1;
//
//	while (left <= right)
//	{
//		int mid = (right - left) / 2 + left;
//
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//
//		}
//		else if (arr[mid] > k)
//		{
//
//			right = mid - 1;
//		}
//		else 
//		{
//			first_find = mid;
//			if (arr[mid] == arr[mid - 1])
//			{
//				right = mid - 1;
//			}
//		}
//	}
//	return (first_find != -1) ? first_find + 1 : -1;
//}
//
//int main()
//{
//	int n, m,i;
//
//	int arr[1000];
//	int arr1[1000];
//	scanf("%d %d", &n, &m);
//
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	for (i = 0; i < m; i++)
//	{
//		scanf("%d", &arr1[i]);
//	}
//
//	for (i = 0; i < m; i++)
//	{
//		int num = find(n,arr,arr1[i]);
//		printf("%d ", num);
//	}
//	return 0;
//}
//




int main()
{

	int n, k,i,num,sum;//原木条数量，小木条数量
	int arr[1000];
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);//把长度存入数组
		num += arr[i];
		printf("\n");
	}

	

	return 0;
}