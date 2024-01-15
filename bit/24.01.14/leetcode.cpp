#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h> 

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void sortColors(int* nums, int numsSize)
{
	int left = -1;
	int right = numsSize - 1;
	int cur = 0;
	int key = 1;

	while (cur <= right)
	{
		if (nums[cur] > key)
		{
			Swap(&nums[cur], &nums[right--]);
		}
		else if (nums[cur] < key)
		{
			Swap(&nums[cur++], &nums[++left]);
		}
		else
		{
			cur++;
		}
	}
}



struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* deleteDuplicates(struct ListNode* head)
{
	if (head == NULL)
		return head;

	struct ListNode* prev = head;
	struct ListNode* cur = head->next;

	while (cur != NULL)
	{
		if (cur->val == prev->val)
		{
			prev->next = cur->next;
			cur = cur->next;
		}
		else
		{
			cur = cur->next;
			prev = prev->next;
		}
	}
	return head;
}

struct ListNode* deleteDuplicates(struct ListNode* head)
{
	if (head == NULL)
		return head;

	struct ListNode* prev = head;
	struct ListNode* before = NULL;
	struct ListNode* cur = head->next;
	int key = head->val;
	head = NULL;

	while (prev != NULL)
	{
		if (cur && cur->val == prev->val)
			cur = cur->next;
		else
		{
			if (prev->next == cur)
			{
				if (before)
				{
					before->next = prev;
					before = prev;
				}
				else
				{
					before = head = prev;
				}
			}
			prev = cur;
			if (cur)
				cur = cur->next;
		}
	}

	if (before)
		before->next = NULL;

	return head;
}

int main()
{

	return 0;
}