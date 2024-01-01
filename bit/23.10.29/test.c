#define _CRT_SECURE_NO_WARNINGS 1

//////单身狗
//#include <stdio.h>
//
//int findoutdog(int * arr,int sz)
//{
//	int dog = 0;
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		dog ^= arr[i];
//	}
//	return dog;
//}
//
//int main()
//{
//	int arr[9] = { 1,2,3,4,5,1,2,3,4 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	int dog = findoutdog(arr, sz);
//
//	printf("The dog is %d", dog);
//
//	return 0;
//}
//#include <stdio.h>

//int NumberOf1(int n) {
//	int num = 1;
//	int count = 0;
//	for (int i = 0; i < 32; i++)
//	{
//		if (num & n)
//		{
//			count++;
//		}
//
//		num <<= 1;
//	}
//	return count;
//}

//int NumberOf1(int n) 
//{
//	int count = 0;
//	while (n)
//	{
//		n = n & (n - 1);
//		count++;
//	}
//	return count;
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int count = NumberOf1(n);
//	printf("%d", count);
//	return 0;
//}

//void swap(int* a,int* b)
//{
//	(*a) = (*a) ^ (*b);
//	(*b) = (*a) ^ (*b);
//	(*a) = (*a) ^ (*b);
//}
//
//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	printf("a = %d\n", a);
//	printf("b = %d\n", b);
//	swap(&a, &b);
//	printf("a = %d\n", a);
//	printf("b = %d\n", b);
//
//	return 0;
//}

//int main()
//{
//    int i = 1;
//    int ret = (++i) + (++i) + (++i);
//    printf("ret = %d\n", ret);
//    return 0;
//}

//int i;
//
//int main()
//{
//    i--;
//    if (i > sizeof(i))
//    {
//        printf(">\n");
//    }
//    else
//    {
//        printf("<\n");
//    }
//    return 0;
//}
// 
// 
// 求一个数的二进制序列的奇偶项
//void number(int a)
//{
//	for (int i = 31; i >= 0; i--)
//	{
//		if (a & (1 << i))
//			printf("1 ");
//		else
//			printf("0 ");
//	}
//}
//#include <stdio.h>
////求奇数
//void odd_number(int a)
//{
//	for (int i = 31; i >= 0; i-=2)
//	{
//		if (a & (1 << i))
//			printf("1 ");
//		else
//			printf("0 ");
//	}
//}
////求偶数
//void even_number(int a)
//{
//	for (int i = 30; i >= 0; i -= 2)
//	{
//		if (a & (1 << i))
//			printf("1 ");
//		else
//			printf("0 ");
//	}
//}
//
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	printf("原二进制是：\n");
//	number(a);
//	printf("\n");
//	printf("奇数位是：\n");
//	odd_number(a);
//	printf("\n");
//	printf("偶数位是：\n");
//	even_number(a);
//	return 0;
//}
//
//#include <stdio.h>
//
//int compare(int a,int b)
//{
//    int count = 0;
//    for (int i = 0; i < 32; i++)
//    {
//        int x = a & (1 << i);
//        int y = b & (1 << i);
//        if (x != y)
//            count++;
//    }
//    return count;
//}
//
//int main() {
//    int a, b;
//    while (scanf("%d %d", &a, &b) != EOF) 
//    { 
//        int count = compare(a, b);
//        printf("%d\n", count);
//    }
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int i = 0;
//    i--;
//    if (i > sizeof(i))
//    {
//        printf(">\n");
//    }
//    else
//    {
//        printf("<\n");
//    }
//    return 0;
//}
//#include <assert.h>
//size_t my_strlen(char *str)
//{
//	assert(str != NULL);
//	char* p = str;
//	while(*str != '\0')
//		str++;
//	return str - p;
//}
//
//int main()
//{
//	char arr[] = {"hello bit"};
//	size_t a = my_strlen(arr);
//	printf("%zd", a);
//
//	return 0;
//}

//字符串左旋
//#include <stdio.h>
//拷贝思路
//void spin(int *str,int k)
//{
//	int i;
//	int sz = sizeof(str) / sizeof(str[0]);
//	int arr[sz];
//	for (i = 0; i < sz; i++)
//	{
//		arr[(k+i)%sz] = str[i];
//	}
//
//	for (i = 0; i < sz; i++)
//	{
//		str[i] = arr[i];
//	}
//}
//三趟旋转思路
//void spin(int * str,int beg,int end)
//{
//	while (beg < end)
//	{
//		str[beg] = str[beg] ^ str[end];
//		str[end] = str[beg] ^ str[end];
//		str[beg] = str[beg] ^ str[end];
//		beg++;
//		end--;
//	}
//
//}
//void rotate(int* nums, int numsSize, int k) 
//{
//	if (k > numsSize)
//	{
//		k %= numsSize;
//	}
//	spin(nums, 0, numsSize - 1);
//	spin(nums, numsSize - k, numsSize - 1);
//	spin(nums, 0, numsSize - k - 1);
//}
//

//int main()
//{
//	int k;
//	int arr[] = { 1,2,3,4,5,6,7,8,9 };
//	scanf("%d", &k);
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	rotate(arr,sz,k);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d", arr[i]);
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//void spin(char *str,int beg,int end)
//{
//    while (beg < end)
//    {
//        char tmp = str[beg];
//        str[beg] = str[end];
//        str[end] = tmp;
//        beg++;
//        end--;
//    }
//}
//
//int main() {
//    char str[10000] = { '\0'};
//    while (gets(str))
//    {
//        int sz = strlen(str);
//        spin(str, 0, sz - 1);
//        printf("%s", str);
//    }
//    return 0;
//}

//
//#include <stdio.h>
//
//int main()
//{
//
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", *(arr + i));
//	}
//
//	return 0;
//}

//#include <stdio.h>
//
//void bubble_sort(int * p,int sz)
//{
//	int i, j;
//	for (i = 0; i < sz; i++)
//	{
//		int flag = 1;
//		for (j = 0; j < sz - i - 1; j++)
//		{
//			if (*(p + j) > *(p + 1 + j))
//			{
//				int tmp = *(p + j);
//				*(p + j) = *(p + 1 + j);
//				*(p + 1 + j) = tmp;
//				flag = 0;
//			}
//		}
//		if (flag == 1)
//			break;
//	}
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	int i;
//	for (i = 0; i < 10;i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz);
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//
//#include <stdio.h>
//
//void odd_even(int * p,int sz)
//{
//	int i, j;
//	for (i = 0; i < sz; i++)
//	{
//		int flag = 1;
//		for (j = 0; j < sz - i - 1; j++)
//		{
//			if (((*(p + j)%2) == 0) && ((*(p + 1 + j)%2)==1))
//			{
//				int tmp = *(p + j);
//				*(p + j) = *(p + 1 + j);
//				*(p + 1 + j) = tmp;
//				flag = 0;
//			}
//		}
//		if (flag == 1)
//			break;
//	}
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	int i;
//	for (i = 0; i < 10;i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	odd_even(arr, sz);
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}










//
//#include <stdio.h>
//#include <string.h>
////判断旋转后是否相等
//int same(char* p1, char* p2,int sz)
//{
//    for (int i = 0; i < sz; i++)
//    {
//        if (p1[i] != p2[i])
//            return 0;
//    }
//    return 1;
//}
////旋转字符串
//void spin(char *str,int beg,int end)
//{
//    while (beg < end)
//    {
//        char tmp = str[beg];
//        str[beg] = str[end];
//        str[end] = tmp;
//        beg++;
//        end--;
//    }
//}
////判断字符串是否旋转后相等总函数
//int strspin(char *str1,char *str2)
//{
//    if (strlen(str1) != strlen(str2))
//        return 0;
//    else
//    {
//        //右旋判断
//        for (int i = 0; i < strlen(str1); i++)
//        {
//            char* p1 = str1;
//            spin(p1, 0, strlen(str1) - 1);
//            spin(p1, 0, i);
//            spin(p1, i + 1, strlen(str1) - 1);
//
//            if (same(p1, str2, strlen(str1)))
//                return 1;
//        }
//        //左旋判断
//        for (int i = 0; i < strlen(str1); i++)
//        {
//            char* p1 = str1;
//            spin(p1, 0, strlen(str1) - 1);
//            spin(p1, 0, i);
//            spin(p1, i + 1, strlen(str1) - 1);
//
//            if (same(p1, str2, strlen(str1)))
//                return 1;
//        }
//        return 0;
//    }
//}
//
//int main() {
//    char str1[] = { "123456789" };
//    char str2[] = { "789123456" };
//    if (strspin(str1, str2))
//        printf("yes");
//    else
//        printf("no");
//    return 0;
//}

//#include <stdio.h>
//#include <string.h>
////判断旋转后是否相等
//int same(char* p1, char* p2, int sz)
//{
//    for (int i = 0; i < sz; i++)
//    {
//        if (p1[i] != p2[i])//只要有一个字符不同，字符串就不同
//            return 0;
//    }
//    return 1;//若上方没有返回，则证明字符串相等
//}
////旋转字符串
//void spin(char* str, int beg, int end)
//{
//    while (beg < end)
//    {
//        char tmp = str[beg];
//        str[beg] = str[end];
//        str[end] = tmp;
//        beg++;
//        end--;
//    }
//}
////判断字符串是否旋转后相等总函数
//bool rotateString(char* str1, char* str2)
//{
//    if (strlen(str1) != strlen(str2))//若字符串长度不同，必定不同
//        return false;
//    else
//    {
//        //右旋判断
//        for (int i = 0; i < strlen(str1); i++)
//        {
//            //利用不同的i，把每种旋转都尝试
//            spin(str1, 0, strlen(str1) - 1);
//            spin(str1, 0, i);
//            spin(str1, i + 1, strlen(str1) - 1);
//
//            if (same(str1, str2, strlen(str1)))//旋转后判断是否相等
//                return true;
//        }
//        //左旋判断
//        for (int i = 0; i < strlen(str1); i++)
//        {
//            spin(str1, 0, strlen(str1) - 1);
//            spin(str1, 0, strlen(str1) - i - 1);
//            spin(str1, strlen(str1) - i, strlen(str1) - 1);
//
//            if (same(str1, str2, strlen(str1)))
//                return true;
//        }
//        return false;
//    }
//}
//
//#include <ctype.h>
//#include <string.h>
//#include <stdbool.h>
//
//bool rotateString(char* str1, char* str2)
//{
//    if (strlen(str1) != strlen(str2))//若字符串长度不同，必定不同
//        return false;
//    else
//    {
//
//        strcpy(arr1 = str1);
//        int sz = strlen(str1);
//        strcat(arr1+sz-1, str1);
//  
//        for (int i = 0; i < sz; i++)
//        {
//            char* p = arr1 + i;
//            for (int j = 0; j < sz; j++)
//            {
//                if (arr1[j] != str2[j])
//                {
//                    break;
//                }
//                return true;
//               
//            }
//
//        }
//        return false;
//    }
//}



//#include <stdio.h>
//
//void printarr(const int* arr,int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", *(arr+i));
//
//	}
//}
//
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	printarr(arr,sz);
//
//		return 0;
//}
//#include <stdio.h>
//
//void bubblesort(int * arr,int sz)
//{
//	int i, j;
//
//	for (i = 0; i < sz; i++ )
//	{
//
//		for (j = 0; j < sz - i - 1; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//
//}
//
//int main()
//{
//	int arr[10];
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 0; i < sz; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	bubblesort(arr,sz);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}


//
//#include <stdio.h>
//#include <stdlib.h>
//
//void odd_even(int* arr, int sz)
//{
//	int* arrodd = (int*)malloc((sz + 1) * sizeof(int));
//	int src = 0;
//	int dst = 0;
//
//	while (src < sz)
//	{
//		if (arr[src] % 2 == 1)
//		{
//			*arrodd = arr[src];
//			arrodd++;
//			src++;
//		}
//		else
//		{
//			arr[dst] = arr[src];
//			dst++;
//			src++;
//		}
//
//	};
//
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	int i;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	odd_even(arr, sz);
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

bool samestr(const char* str1, const char* str2)
{
	assert((str1 != NULL)&&(str2 != NULL));
	if (strlen(str1) != strlen(str2))
		return false;
	else 
	{
		char* p = (char*)malloc(2 * strlen(str1) * sizeof(char));
		strcpy(p, str1);
		strncat(p, str1, strlen(str1));

		if (strstr(p, str2) != NULL)
		{
			return true;
		}
		
	}
	return false;
}


int main()
{
	char str1[100] = "\0";
	char str2[100] = "\0";
	gets(str1);
	gets(str2);
	if (samestr(str1, str2))
	{
		printf("true");
	}
	else
	{
		printf("false");
	}
	
	return 0;
}
