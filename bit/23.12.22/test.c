#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int* lengthOfLIS(int* nums, int numsSize)
{
	int* dp = (int*)malloc(sizeof(int) * numsSize);

	dp[0] = 1;

	int max = 0;

	for (int i = 0; i < numsSize; ++i) 
	{
		dp[i] = 1;
		for (int j = 0; j < i; ++j) 
		{
			if (nums[j] < nums[i]) 
			{
				dp[i] = fmax(dp[i], dp[j] + 1);
			}
			max = dp[i] > dp[max] ? i : max;
		}
	}

	return dp;
}

void reverse(int* arr, int beg, int end)
{
	while (beg < end)
	{
		int tmp = arr[beg];
		arr[beg] = arr[end];
		arr[end] = tmp;
		beg++;
		end--;
	}
}

int minimumMountainRemovals(int* nums, int numsSize)
{
	int* before = lengthOfLIS(nums, numsSize);
	reverse(nums, 0, numsSize - 1);
	int* after = lengthOfLIS(nums, numsSize);
	reverse(after, 0, numsSize - 1);

	int ans = 0;
	for (int i = 0; i < numsSize; i++)
	{
		if (before[i] > 1 && after[i] > 1) {
			ans = fmax(ans, before[i] + after[i] - 1);
		}
	}

	free(before);
	free(after);

	return numsSize - ans;
}

int wordCount(char** startWords, int startWordsSize, char** targetWords, int targetWordsSize)
{

	int nums[26];
	for (int i = 0; i < 26; i++)
	{
		nums[i] = 0;
	}//定义一个26长度的数组，对于每一位字母

	int ans = 0;

	for (int i = 0; i < startWordsSize; i++)
	{
		
		for (int j = 0; j < targetWordsSize; j++)//双重循环，让每两对字符串一一匹配
		{
			if (strlen(startWords[i]) - strlen(targetWords[j]) == 1)//只有目标字符串比原字符串长度小1，才有可能追加调序后相等
			{	
				int m = 0;
				while (startWords[i][m] != '\0')
				{
					nums[startWords[i][m] - 97] += 1;//利用ASCII的差值，使字母与数组下标对应
					m++;
				}//将start的每个字母的数据存到数组中

				m = 0;
				while (targetWords[j][m] != '\0')
				{
					nums[targetWords[j][m] - 97] -= 1;//将target的每个字母与start的字母个数做差值
					m++;
				}

				int more = 0;//差值为1的个数
				int equal = 0;//差值为0的个数

				for (int i = 0; i < 26; i++)
				{
					if (nums[i] == 1)//做差后值为1
						more++;
					if (nums[i] == 0)//做差后值为0
						equal++;
					nums[i] = 0;//遍历数组的同时，顺便清空这次一的数据，避免对下一次造成影响
				}

				if (equal == 25 && more == 1)//只有当一个字母的差值为1，剩下25个字母的差值为0，才能在追加一个字符后，字符串相同
					ans++;
			}
		}
	}

	return ans;
}

int cmp(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{


}

int main() {



	return 0;
}