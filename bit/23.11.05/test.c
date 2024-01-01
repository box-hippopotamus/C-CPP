#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>



// 
//struct ListNode* middleNode(struct ListNode* head) 
//{
//	struct ListNode* tmp = head;
//	int count = 1;
//	int num = 1;
//	while (tmp->next != NULL)
//	{
//		tmp = tmp->next;
//		count++;
//	}
//
//	if (count % 2 == 0)
//	{
//		count = count / 2;
//		count++;
//		tmp = head;
//		while (num != count)
//		{
//			tmp = tmp->next;
//			num++;
//		}
//
//		return tmp->val;
//
//	}
//	else
//	{
//		count = count / 2;
//		tmp = head;
//		while (num != count)
//		{
//			tmp = tmp->next;
//			num++;
//		}
//		return tmp;
//	}
//
//}
//
//struct ListNode* middleNode(struct ListNode* head)
//{
//	struct ListNode* fast = head;
//	struct ListNode* slow = head;
//
//	while (fast && fast->next)
//	{
//		fast = fast->next->next;
//		slow = slow->next;
//	}
//
//	return slow;
//}
//
//

struct ListNode {
	int val;
	struct ListNode* next;
};
struct ListNode* removeElements(struct ListNode* head, int val)
{
	struct ListNode* p1 = head;
	struct ListNode* pre = NULL;

	while (p1)
	{
		if (p1->val == val)
		{
			if (p1 == head)
			{
				head = head->next;
			}
			struct ListNode* tmp = p1->next;	
			free(p1);
			p1 = tmp;
			if (pre)
			{
				pre->next = p1;
			}
		}
		else
		{
			pre = p1;
			p1 = p1->next;
		}
	}
	return head;
}



//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//	struct ListNode* cur = head;
//	struct ListNode* pre = NULL;
//
//	while (cur)
//	{
//		if (cur->val == val)
//		{
//			struct ListNode* tmp = cur->next;
//			free(cur);
//
//			if (pre)
//				pre->next = tmp;
//			else
//				head = tmp;
//
//			cur = tmp;
//		}
//		else
//		{
//			pre = cur;
//			cur = cur->next;
//		}
//	}
//	return head;
//}

int main()
{
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));

	n1->val = 7;
	n2->val = 7;
	n3->val = 7;
	n4->val = 7;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;

	removeElements(n1, 7);
	return 0;
}