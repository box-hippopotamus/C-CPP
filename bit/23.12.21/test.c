#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//long long sumHeight(int* maxHeights, int maxHeightsSize, int Height)
//{
//	int tow[maxHeightsSize];
//
//	int cur = Height + 1;
//	tow[Height] = maxHeights[Height];
//
//	long long sum = tow[Height];
//
//	while (cur < maxHeightsSize)
//	{
//		if (maxHeights[cur] >= tow[cur - 1])
//		{
//			tow[cur] = tow[cur - 1];
//		}
//		else
//		{
//			tow[cur] = maxHeights[cur];
//		}
//		sum += tow[cur];
//		cur++;
//	}
//
//	cur = Height - 1;
//
//	while (cur >= 0)
//	{
//		if (maxHeights[cur] >= tow[cur + 1])
//		{
//			tow[cur] = tow[cur + 1];
//		}
//		else
//		{
//			tow[cur] = maxHeights[cur];
//		}
//		sum += tow[cur];
//		cur--;
//	}
//
//
//	return sum;
//}
//
//long long maximumSumOfHeights(int* maxHeights, int maxHeightsSize)
//{
//	long long sumTowHeight[maxHeightsSize];
//
//	long long max = 0;
//
//	for (int i = 0; i < maxHeightsSize; i++)
//	{
//		sumTowHeight[i] = sumHeight(maxHeights, maxHeightsSize, i);
//
//		max = max > sumTowHeight[i] ? max : sumTowHeight[i];
//	}
//
//	return max;
//}
//
//
//int main()
//{
//	int maxHeights[5] = { 5,3,4,1,1 };
//
//	long long a = maximumSumOfHeights(maxHeights, 5);
//	printf("%ll",a);
//
//	return 0;
//}


int largestRectangleArea(int* heights, int heightsSize)
{
	int max = 0;
	for (int i = 0; i < heightsSize; i++)
	{
		int area = 0;
		int stack[8];
		int top = 0;
		stack[top] = heights[i];
		top++;

		int cur = i + 1;
		while (cur < heightsSize)
		{
			if (stack[0] <= heights[cur])
			{
				stack[top] = heights[cur];
				top++;
				cur++;
			}
			else
			{
				break;
			}
		}

		area = top;
		top = 1;
		cur = i - 1;

		while (cur >= 0)
		{
			if (stack[0] <= heights[cur])
			{
				stack[top] = heights[cur];
				top++;
				cur--;
			}
			else
			{
				break;
			}
		}

		area += top;
		area = (area - 1) * heights[i];

		max = max > area ? max : area;
	}

	return max;
}

int main(){
	int heights[8] = { 4,2,0,3,2,4,3,4 };
	int a = largestRectangleArea(heights, 8);

	printf("%d", a);

	return 0;
}

int largestRectangleArea(int* heights, int heightsSize)
{
	int stack[heightsSize];//定义栈
	int top = -1;
	stack[++top] = 0;

	int max = -1;
	for (int i = 1; i < heightsSize; i++)//遍历数组
	{
		if (heights[i] >= heights[stack[top]])//入栈
		{
			stack[++top] = i;
		}
		else
		{
			while (top != -1 && heights[i] < heights[stack[top]])//出栈并计算面积，维护递增性，需要对小于的元素全部出栈
			{
				if (top - 1 == -1)//最后一个栈顶元素，出栈计算面积需要包含一下前面和后面，因为矩形可以延伸，这里需要好好想一想
				{
					max = fmax(max, i * heights[stack[top]]);
				}
				else
				{
					max = fmax(max, (i - stack[top] + stack[top] - stack[top - 1] - 1) * heights[stack[top]]);//栈中元素，计算面积与需要延伸，能延伸多长就延伸多长
				}
				--top;
			}
			stack[++top] = i;
		}
	}
	while (top != -1)//数组元素全部遍历完了，单是栈还有元素，进行清空栈
	{
		if (top - 1 == -1)
		{
			max = fmax(max, (heightsSize)*heights[stack[top]]);
		}
		else
		{
			max = fmax(max, (heightsSize - 1 - stack[top - 1]) * heights[stack[top]]);
		}
		--top;
	}
	return max;
}

//for (遍历这个数组)
//{
//	if (栈空 || 栈顶元素大于等于当前比较元素)
//	{
//		入栈;
//	}
//	else
//	{
//		while (栈不为空 && 栈顶元素小于当前元素)
//		{
//			栈顶元素出栈;
//			更新结果;
//		}
//		当前数据入栈;
//	}
//}


int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize)
{
	int stack[temperaturesSize];
	int top = -1;

	int* ans = (int*)malloc(sizeof(int) * temperaturesSize);

	for (int i = temperaturesSize - 1; i > -1; i--)
	{
		if (top == -1 || temperatures[stack[top]] >= temperatures[i])
		{
			if (top == -1)
				ans[i] = 0;
			else
				ans[i] = 1;

			stack[++top] = i;
		}
		else
		{
			ans[i] = 1;
			while (top != -1 && temperatures[i] > temperatures[stack[top]])
			{
				top--;
				ans[i] += 1;
			}
			stack[++top] = i;
		}
	}

	*returnSize = temperaturesSize;
	return ans;
}