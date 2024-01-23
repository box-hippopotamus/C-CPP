#include <iostream>
#include <stdlib.h>
using namespace std;

int alternatingSubarray(int* nums, int numsSize) 
{

}

//int MoreThanHalfNum_Solution(int* numbers, int numbersLen) 
//{
//    int numsArr[100001] = { 0 };
//
//    for (int i = 0; i < numbersLen; i++)
//    {
//        numsArr[numbers[i]]++;
//    }
//
//    int ans;
//
//    for (int i = 0; i < 10001; i++)
//    {
//        if (numsArr[i] > numbersLen / 2)
//        {
//            ans = i;
//            break;
//        }
//    }
//
//    return ans;
//}



//int main()
//{
//	char str[256];
//	cin >> str;
//
//	char* cur = str;
//	char* pre = str;
//
//	int count = 0;
//	int sum = 0;
//	char* ans = nullptr;
//
//	while (*cur != '\0')
//	{
//		if (*cur >= 48 && *cur <= 57)
//		{
//			count++;
//			cur++;
//		}
//		else
//		{
//			if (count > sum)
//			{
//				sum = count;
//				ans = pre;
//			}
//			pre = ++cur;
//
//			count = 0;
//		}
//	}
//
//	if (count > sum)
//	{
//		sum = count;
//		ans = pre;
//	}
//
//	for (int i = 0; i < sum; i++)
//	{
//		printf("%c", *ans);
//		ans++;
//	}
//	printf("\n");
//
//	return 0;
//}
