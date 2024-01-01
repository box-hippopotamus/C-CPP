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
	}//����һ��26���ȵ����飬����ÿһλ��ĸ

	int ans = 0;

	for (int i = 0; i < startWordsSize; i++)
	{
		
		for (int j = 0; j < targetWordsSize; j++)//˫��ѭ������ÿ�����ַ���һһƥ��
		{
			if (strlen(startWords[i]) - strlen(targetWords[j]) == 1)//ֻ��Ŀ���ַ�����ԭ�ַ�������С1�����п���׷�ӵ�������
			{	
				int m = 0;
				while (startWords[i][m] != '\0')
				{
					nums[startWords[i][m] - 97] += 1;//����ASCII�Ĳ�ֵ��ʹ��ĸ�������±��Ӧ
					m++;
				}//��start��ÿ����ĸ�����ݴ浽������

				m = 0;
				while (targetWords[j][m] != '\0')
				{
					nums[targetWords[j][m] - 97] -= 1;//��target��ÿ����ĸ��start����ĸ��������ֵ
					m++;
				}

				int more = 0;//��ֵΪ1�ĸ���
				int equal = 0;//��ֵΪ0�ĸ���

				for (int i = 0; i < 26; i++)
				{
					if (nums[i] == 1)//�����ֵΪ1
						more++;
					if (nums[i] == 0)//�����ֵΪ0
						equal++;
					nums[i] = 0;//���������ͬʱ��˳��������һ�����ݣ��������һ�����Ӱ��
				}

				if (equal == 25 && more == 1)//ֻ�е�һ����ĸ�Ĳ�ֵΪ1��ʣ��25����ĸ�Ĳ�ֵΪ0��������׷��һ���ַ����ַ�����ͬ
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