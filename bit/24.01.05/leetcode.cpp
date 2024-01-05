#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
//
//int canSeePerson(int* heights, int heightsSize, int* stack, int me)
//{
//	if (me == heightsSize - 1)
//		return 0;
//
//	int top = -1;
//
//	int person = 0;
//	for (int i = me + 1; i <= heightsSize; i++)
//	{
//		if (i == heightsSize)
//		{
//			while (top > -1)
//			{
//				top--;
//				person++;
//			}
//			break;
//		}
//
//		if (heights[me] > heights[i])
//		{
//			if (top == -1 || stack[top] < heights[i])
//			{
//				stack[top + 1] = heights[i];
//				top++;
//			}
//		}
//		else
//		{
//			if (heights[i] > heights[me])
//				person++;
//
//			while (top > -1)
//			{
//				top--;
//				person++;
//			}
//			break;
//		}
//	}
//
//	return person;
//}
//
//int* canSeePersonsCount(int* heights, int heightssize, int* returnsize)
//{
//	int* ans = (int*)malloc(sizeof(int) * heightssize);
//	int* stack = (int*)malloc(sizeof(int) * heightssize);
//
//	for (int i = 0; i < heightssize; i++)
//	{
//		ans[i] = canSeePerson(heights, heightssize,stack, i);
//	}
//	*returnsize = heightssize;
//
//	free(stack);
//	return ans;
//}

int* canSeePersonsCount(int* heights, int heightsSize, int* returnSize) {
    int n = heightsSize;
    int stackSize = 0;
    int* stack = (int*)malloc(n * sizeof(int));
    int* res = (int*)malloc(n * sizeof(int));
    *returnSize = n;

    for (int i = n - 1; i >= 0; i--) {
        int h = heights[i];
        res[i] = 0;
        while (stackSize > 0 && stack[stackSize - 1] <= h) {
            stackSize--;
            res[i] += 1;
        }
        if (stackSize > 0) {
            res[i] += 1;
        }
        stack[stackSize++] = h;
    }
    free(stack);
    return res;
}

int main()
{
	int heights[] = { 10, 6, 8, 5, 11, 9 };
    int heightsSize = 6;
    int returnsize = 0;
	int* ans = canSeePersonsCount(heights, heightsSize, &returnsize );
	
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", ans[i]);
    }
	return 0;
}