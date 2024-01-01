#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <stdbool.h>

//struct ListNode {
//	int val;
//	struct ListNode* next;
//};
// 
////反转链表
//struct ListNode* reverseList(struct ListNode* head)
//{
//	if (head == NULL)
//	{
//		return NULL;
//	}
//	struct ListNode* prev = NULL;
//	struct ListNode* cur = head;
//	struct ListNode* next = NULL;
//
//	while (cur)
//	{
//		next = cur->next;
//		cur->next = prev;
//		prev = cur;
//		cur = next;
//	}
//
//	return prev;
//}
//
////合并有序链表
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) 
//{
//	struct ListNode* cur1 = list1;
//	struct ListNode* cur2 = list2;
//	struct ListNode* newhead = (struct ListNode*)malloc(sizeof(struct ListNode));
//	newhead->next = NULL;
//	struct ListNode* tail = newhead;
//
//
//	while (cur1 && cur2)
//	{
//		if (cur1->val < cur2->val)
//		{
//			tail->next = cur1;
//			cur1 = cur1->next;
//		}
//		else
//		{
//			tail->next = cur2;
//			cur2 = cur2->next;
//		}
//		tail = tail->next;
//	}
//
//	if (cur1)
//	{
//		tail->next = cur1;
//	}
//	else if(cur2)
//	{
//		tail->next = cur2;
//	}
//
//	return newhead->next;
//}
//
////链表分割
//
//struct ListNode {
//	int val;
//	struct ListNode *next;
//};
//
//struct ListNode* partition(struct ListNode* pHead, int x) 
//{
//	struct ListNode* bighead = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* smallhead = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* big = bighead;
//	struct ListNode* small = smallhead;
//	big->next = NULL;
//	small->next = NULL;
//	struct ListNode* cur = pHead;
//
//	while (cur)
//	{
//		if (cur->val >= x)
//		{
//			big->next = cur;
//			big = cur;
//		}
//		else
//		{
//			small->next = cur;
//			small = cur;
//		}
//		cur = cur->next;
//	}
//
//	small->next = bighead->next;
//	big->next = NULL;
//	return smallhead->next;
//};
//
////回文链表
//bool partition(struct ListNode* A)
//{
//	if (A == NULL) 
//	{
//		return true;
//	}
//	struct ListNode* prev = NULL;
//	struct ListNode* cur = A;
//	struct ListNode* next = NULL;
//
//	struct ListNode* fast = A;
//	struct ListNode* slow = A;
//
//	while (fast && fast->next) 
//	{
//		slow = slow->next;
//		fast = fast->next->next;
//	}
//
//	cur = slow;
//	while (cur) 
//	{
//		next = cur->next;
//		if (prev)
//			cur->next = prev;
//		else
//			cur->next = NULL;
//		prev = cur;
//		cur = next;
//	}
//
//	cur = A;
//	while (cur && prev) 
//	{
//		if (cur->val != prev->val) 
//		{
//			return false;
//		}
//		cur = cur->next;
//		prev = prev->next;
//	}
//	return true;
//}
//
//int main()
//{
//
//	return 0;
//}
//

#include <stdio.h>

//void add(int x, int y)
//{
//	int z = x + y;
//
//}
//
//int main()
//{
//	int a = 3;
//	int b = 5;
//	add(3, 5);
//	return 0;
//}

int add(int x, int y)
{
	return x + y;
}

int main()
{
	int(*p)(int, int) = &add;
	int num1 = add(3, 5);
	int num2 = p(3, 5);
	int num3 = (*p)(3, 5);

	printf("%d %d %d", num1, num2, num3);

	return 0;
}